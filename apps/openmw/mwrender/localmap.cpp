#include "localmap.hpp"


#include <osg/LightModel>
#include <osg/Texture2D>
#include <osg/ComputeBoundsVisitor>

#include <osgDB/ReadFile>

#include <osgViewer/Viewer>

#include <components/settings/settings.hpp>
#include <components/sceneutil/visitor.hpp>
#include <components/files/memorystream.hpp>

#include "../mwbase/environment.hpp"
#include "../mwbase/world.hpp"

#include "../mwworld/cellstore.hpp"

#include "vismask.hpp"

namespace
{

    class CameraUpdateCallback : public osg::NodeCallback
    {
    public:
        CameraUpdateCallback(osg::Camera* cam, MWRender::LocalMap* parent)
            : mRendered(false)
            , mCamera(cam)
            , mParent(parent)
        {
        }

        virtual void operator()(osg::Node*, osg::NodeVisitor*)
        {
            if (mRendered)
                mCamera->setNodeMask(0);

            if (!mRendered)
            {
                mRendered = true;
                mParent->markForRemoval(mCamera);
            }

            // Note, we intentionally do not traverse children here. The map camera's scene data is the same as the master camera's,
            // so it has been updated already.
            //traverse(node, nv);
        }

    private:
        bool mRendered;
        osg::ref_ptr<osg::Camera> mCamera;
        MWRender::LocalMap* mParent;
    };

    float square(float val)
    {
        return val*val;
    }

}

namespace MWRender
{

LocalMap::LocalMap(osgViewer::Viewer* viewer)
    : mViewer(viewer)
    , mMapResolution(Settings::Manager::getInt("local map resolution", "Map"))
    , mMapWorldSize(8192.f)
    , mAngle(0.f)
    , mInterior(false)
{
    mRoot = mViewer->getSceneData()->asGroup();

    SceneUtil::FindByNameVisitor find("Scene Root");
    mRoot->accept(find);
    mSceneRoot = find.mFoundNode;
    if (!mSceneRoot)
        throw std::runtime_error("no scene root found");
}

LocalMap::~LocalMap()
{
    for (CameraVector::iterator it = mActiveCameras.begin(); it != mActiveCameras.end(); ++it)
        mRoot->removeChild(*it);
    for (CameraVector::iterator it = mCamerasPendingRemoval.begin(); it != mCamerasPendingRemoval.end(); ++it)
        mRoot->removeChild(*it);
}

const osg::Vec2f LocalMap::rotatePoint(const osg::Vec2f& point, const osg::Vec2f& center, const float angle)
{
    return osg::Vec2f( std::cos(angle) * (point.x() - center.x()) - std::sin(angle) * (point.y() - center.y()) + center.x(),
                    std::sin(angle) * (point.x() - center.x()) + std::cos(angle) * (point.y() - center.y()) + center.y());
}

void LocalMap::clear()
{
    mSegments.clear();
}

void LocalMap::saveFogOfWar(MWWorld::CellStore* cell)
{
    if (!mInterior)
    {
        const MapSegment& segment = mSegments[std::make_pair(cell->getCell()->getGridX(), cell->getCell()->getGridY())];

        if (segment.mFogOfWarImage && segment.mHasFogState)
        {
            std::auto_ptr<ESM::FogState> fog (new ESM::FogState());
            fog->mFogTextures.push_back(ESM::FogTexture());

            segment.saveFogOfWar(fog->mFogTextures.back());

            cell->setFog(fog.release());
        }
    }
    else
    {
        // FIXME: segmenting code duplicated from requestMap
        osg::Vec2f min(mBounds.xMin(), mBounds.yMin());
        osg::Vec2f max(mBounds.xMax(), mBounds.yMax());
        osg::Vec2f length = max-min;
        const int segsX = static_cast<int>(std::ceil(length.x() / mMapWorldSize));
        const int segsY = static_cast<int>(std::ceil(length.y() / mMapWorldSize));

        std::auto_ptr<ESM::FogState> fog (new ESM::FogState());

        fog->mBounds.mMinX = mBounds.xMin();
        fog->mBounds.mMaxX = mBounds.xMax();
        fog->mBounds.mMinY = mBounds.yMin();
        fog->mBounds.mMaxY = mBounds.yMax();
        fog->mNorthMarkerAngle = mAngle;

        fog->mFogTextures.reserve(segsX*segsY);

        for (int x=0; x<segsX; ++x)
        {
            for (int y=0; y<segsY; ++y)
            {
                const MapSegment& segment = mSegments[std::make_pair(x,y)];

                fog->mFogTextures.push_back(ESM::FogTexture());

                // saving even if !segment.mHasFogState so we don't mess up the segmenting
                // plus, older openmw versions can't deal with empty images
                segment.saveFogOfWar(fog->mFogTextures.back());

                fog->mFogTextures.back().mX = x;
                fog->mFogTextures.back().mY = y;
            }
        }

        cell->setFog(fog.release());
    }
}

osg::ref_ptr<osg::Camera> LocalMap::createOrthographicCamera(float x, float y, float width, float height, const osg::Vec3d& upVector, float zmin, float zmax)
{
    osg::ref_ptr<osg::Camera> camera (new osg::Camera);

    camera->setProjectionMatrixAsOrtho(-width/2, width/2, -height/2, height/2, 5, (zmax-zmin) + 10);
    camera->setComputeNearFarMode(osg::Camera::DO_NOT_COMPUTE_NEAR_FAR);
    camera->setViewMatrixAsLookAt(osg::Vec3d(x, y, zmax + 5), osg::Vec3d(x, y, zmin), upVector);
    camera->setReferenceFrame(osg::Camera::ABSOLUTE_RF);
    camera->setRenderTargetImplementation(osg::Camera::FRAME_BUFFER_OBJECT, osg::Camera::PIXEL_BUFFER_RTT);
    camera->setClearColor(osg::Vec4(0.f, 0.f, 0.f, 1.f));
    camera->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera->setRenderOrder(osg::Camera::PRE_RENDER);

    camera->setCullMask(Mask_Scene|Mask_Water|Mask_Terrain);
    camera->setNodeMask(Mask_RenderToTexture);

    osg::ref_ptr<osg::StateSet> stateset = new osg::StateSet;
    stateset->setMode(GL_LIGHTING, osg::StateAttribute::ON);
    stateset->setMode(GL_NORMALIZE, osg::StateAttribute::ON);
    stateset->setMode(GL_CULL_FACE, osg::StateAttribute::ON);
    stateset->setMode(GL_FOG, osg::StateAttribute::OFF|osg::StateAttribute::OVERRIDE);

    osg::ref_ptr<osg::LightModel> lightmodel = new osg::LightModel;
    lightmodel->setAmbientIntensity(osg::Vec4(0.3f, 0.3f, 0.3f, 1.f));
    stateset->setAttributeAndModes(lightmodel, osg::StateAttribute::ON|osg::StateAttribute::OVERRIDE);

    osg::ref_ptr<osg::Light> light = new osg::Light;
    light->setPosition(osg::Vec4(-0.3f, -0.3f, 0.7f, 0.f));
    light->setDiffuse(osg::Vec4(0.7f, 0.7f, 0.7f, 1.f));
    light->setAmbient(osg::Vec4(0,0,0,1));
    light->setSpecular(osg::Vec4(0,0,0,0));
    light->setLightNum(0);
    light->setConstantAttenuation(1.f);
    light->setLinearAttenuation(0.f);
    light->setQuadraticAttenuation(0.f);

    osg::ref_ptr<osg::LightSource> lightSource = new osg::LightSource;
    lightSource->setLight(light);

    lightSource->setStateSetModes(*stateset, osg::StateAttribute::ON|osg::StateAttribute::OVERRIDE);

    camera->addChild(lightSource);
    camera->setStateSet(stateset);
    camera->setGraphicsContext(mViewer->getCamera()->getGraphicsContext());
    camera->setViewport(0, 0, mMapResolution, mMapResolution);
    camera->setUpdateCallback(new CameraUpdateCallback(camera, this));

    return camera;
}

void LocalMap::setupRenderToTexture(osg::ref_ptr<osg::Camera> camera, int x, int y)
{
    osg::ref_ptr<osg::Texture2D> texture (new osg::Texture2D);
    texture->setTextureSize(mMapResolution, mMapResolution);
    texture->setInternalFormat(GL_RGB);
    texture->setFilter(osg::Texture::MIN_FILTER, osg::Texture::LINEAR);
    texture->setFilter(osg::Texture::MAG_FILTER, osg::Texture::LINEAR);
    texture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_EDGE);
    texture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_EDGE);

    camera->attach(osg::Camera::COLOR_BUFFER, texture);

    camera->addChild(mSceneRoot);
    mRoot->addChild(camera);
    mActiveCameras.push_back(camera);

    MapSegment& segment = mSegments[std::make_pair(x, y)];
    segment.mMapTexture = texture;
}

void LocalMap::requestMap(std::set<MWWorld::CellStore*> cells)
{
    for (std::set<MWWorld::CellStore*>::iterator it = cells.begin(); it != cells.end(); ++it)
    {
        MWWorld::CellStore* cell = *it;
        if (cell->isExterior())
            requestExteriorMap(cell);
        else
            requestInteriorMap(cell);
    }
}

void LocalMap::removeCell(MWWorld::CellStore *cell)
{
    saveFogOfWar(cell);

    if (cell->isExterior())
        mSegments.erase(std::make_pair(cell->getCell()->getGridX(), cell->getCell()->getGridY()));
    else
        mSegments.clear();
}

osg::ref_ptr<osg::Texture2D> LocalMap::getMapTexture(int x, int y)
{
    SegmentMap::iterator found = mSegments.find(std::make_pair(x, y));
    if (found == mSegments.end())
        return osg::ref_ptr<osg::Texture2D>();
    else
        return found->second.mMapTexture;
}

osg::ref_ptr<osg::Texture2D> LocalMap::getFogOfWarTexture(int x, int y)
{
    SegmentMap::iterator found = mSegments.find(std::make_pair(x, y));
    if (found == mSegments.end())
        return osg::ref_ptr<osg::Texture2D>();
    else
        return found->second.mFogOfWarTexture;
}

void LocalMap::markForRemoval(osg::Camera *cam)
{
    CameraVector::iterator found = std::find(mActiveCameras.begin(), mActiveCameras.end(), cam);
    if (found == mActiveCameras.end())
    {
        std::cerr << "trying to remove an inactive camera" << std::endl;
        return;
    }
    mActiveCameras.erase(found);
    mCamerasPendingRemoval.push_back(cam);
}

void LocalMap::cleanupCameras()
{
    if (mCamerasPendingRemoval.empty())
        return;

    for (CameraVector::iterator it = mCamerasPendingRemoval.begin(); it != mCamerasPendingRemoval.end(); ++it)
    {
        (*it)->removeChildren(0, (*it)->getNumChildren());
        (*it)->setGraphicsContext(NULL);
        mRoot->removeChild(*it);
    }

    mCamerasPendingRemoval.clear();
}

void LocalMap::requestExteriorMap(MWWorld::CellStore* cell)
{
    mInterior = false;

    int x = cell->getCell()->getGridX();
    int y = cell->getCell()->getGridY();

    osg::BoundingSphere bound = mViewer->getSceneData()->getBound();
    float zmin = bound.center().z() - bound.radius();
    float zmax = bound.center().z() + bound.radius();

    osg::ref_ptr<osg::Camera> camera = createOrthographicCamera(x*mMapWorldSize + mMapWorldSize/2.f, y*mMapWorldSize + mMapWorldSize/2.f, mMapWorldSize, mMapWorldSize,
                                                                osg::Vec3d(0,1,0), zmin, zmax);
    setupRenderToTexture(camera, cell->getCell()->getGridX(), cell->getCell()->getGridY());

    MapSegment& segment = mSegments[std::make_pair(cell->getCell()->getGridX(), cell->getCell()->getGridY())];
    if (!segment.mFogOfWarImage)
    {
        if (cell->getFog())
            segment.loadFogOfWar(cell->getFog()->mFogTextures.back());
        else
            segment.initFogOfWar();
    }
}

void LocalMap::requestInteriorMap(MWWorld::CellStore* cell)
{
    osg::ComputeBoundsVisitor computeBoundsVisitor;
    computeBoundsVisitor.setTraversalMask(Mask_Scene|Mask_Terrain);
    mSceneRoot->accept(computeBoundsVisitor);

    osg::BoundingBox bounds = computeBoundsVisitor.getBoundingBox();

    // If we're in an empty cell, bail out
    // The operations in this function are only valid for finite bounds
    if (!bounds.valid() || bounds.radius2() == 0.0)
        return;

    mInterior = true;

    mBounds = bounds;

    // Get the cell's NorthMarker rotation. This is used to rotate the entire map.
    osg::Vec2f north = MWBase::Environment::get().getWorld()->getNorthVector(cell);

    mAngle = std::atan2(north.x(), north.y());

    // Rotate the cell and merge the rotated corners to the bounding box
    osg::Vec2f origCenter(bounds.center().x(), bounds.center().y());
    osg::Vec3f origCorners[8];
    for (int i=0; i<8; ++i)
        origCorners[i] = mBounds.corner(i);

    for (int i=0; i<8; ++i)
    {
        osg::Vec3f corner = origCorners[i];
        osg::Vec2f corner2d (corner.x(), corner.y());
        corner2d = rotatePoint(corner2d, origCenter, mAngle);
        mBounds.expandBy(osg::Vec3f(corner2d.x(), corner2d.y(), 0));
    }

    // Do NOT change padding! This will break older savegames.
    // If the padding really needs to be changed, then it must be saved in the ESM::FogState and
    // assume the old (500) value as default for older savegames.
    const float padding = 500.0f;

    // Apply a little padding
    mBounds.set(mBounds._min - osg::Vec3f(padding,padding,0.f),
                mBounds._max + osg::Vec3f(padding,padding,0.f));

    float zMin = mBounds.zMin();
    float zMax = mBounds.zMax();

    // If there is fog state in the CellStore (e.g. when it came from a savegame) we need to do some checks
    // to see if this state is still valid.
    // Both the cell bounds and the NorthMarker rotation could be changed by the content files or exchanged models.
    // If they changed by too much (for bounds, < padding is considered acceptable) then parts of the interior might not
    // be covered by the map anymore.
    // The following code detects this, and discards the CellStore's fog state if it needs to.
    if (cell->getFog())
    {
        ESM::FogState* fog = cell->getFog();

        osg::Vec3f newMin (fog->mBounds.mMinX, fog->mBounds.mMinY, zMin);
        osg::Vec3f newMax (fog->mBounds.mMaxX, fog->mBounds.mMaxY, zMax);

        osg::Vec3f minDiff = newMin - mBounds._min;
        osg::Vec3f maxDiff = newMax - mBounds._max;

        if (std::abs(minDiff.x()) > padding || std::abs(minDiff.y()) > padding
            || std::abs(maxDiff.x()) > padding || std::abs(maxDiff.y()) > padding
                || std::abs(mAngle - fog->mNorthMarkerAngle) > osg::DegreesToRadians(5.f))
        {
            // Nuke it
            cell->setFog(NULL);
        }
        else
        {
            // Looks sane, use it
            mBounds = osg::BoundingBox(newMin, newMax);
            mAngle = fog->mNorthMarkerAngle;
        }
    }

    osg::Vec2f min(mBounds.xMin(), mBounds.yMin());
    osg::Vec2f max(mBounds.xMax(), mBounds.yMax());

    osg::Vec2f length = max-min;

    osg::Vec2f center(bounds.center().x(), bounds.center().y());

    // divide into segments
    const int segsX = static_cast<int>(std::ceil(length.x() / mMapWorldSize));
    const int segsY = static_cast<int>(std::ceil(length.y() / mMapWorldSize));

    int i = 0;
    for (int x=0; x<segsX; ++x)
    {
        for (int y=0; y<segsY; ++y)
        {
            osg::Vec2f start = min + osg::Vec2f(mMapWorldSize*x, mMapWorldSize*y);
            osg::Vec2f newcenter = start + osg::Vec2f(mMapWorldSize/2.f, mMapWorldSize/2.f);

            osg::Quat cameraOrient (mAngle, osg::Vec3d(0,0,-1));
            osg::Vec2f a = newcenter - center;
            osg::Vec3f rotatedCenter = cameraOrient * (osg::Vec3f(a.x(), a.y(), 0));

            osg::Vec2f pos = osg::Vec2f(rotatedCenter.x(), rotatedCenter.y()) + center;

            osg::ref_ptr<osg::Camera> camera = createOrthographicCamera(pos.x(), pos.y(),
                                                                        mMapWorldSize, mMapWorldSize,
                                                                        osg::Vec3f(north.x(), north.y(), 0.f), zMin, zMax);

            setupRenderToTexture(camera, x, y);

            MapSegment& segment = mSegments[std::make_pair(x,y)];
            if (!segment.mFogOfWarImage)
            {
                if (!cell->getFog())
                    segment.initFogOfWar();
                else
                {
                    ESM::FogState* fog = cell->getFog();

                    // We are using the same bounds and angle as we were using when the textures were originally made. Segments should come out the same.
                    if (i >= int(fog->mFogTextures.size()))
                    {
                        std::cout << "Warning: fog texture count mismatch" << std::endl;
                        break;
                    }

                    segment.loadFogOfWar(fog->mFogTextures[i]);
                }
            }
            ++i;
        }
    }
}

void LocalMap::worldToInteriorMapPosition (osg::Vec2f pos, float& nX, float& nY, int& x, int& y)
{
    pos = rotatePoint(pos, osg::Vec2f(mBounds.center().x(), mBounds.center().y()), mAngle);

    osg::Vec2f min(mBounds.xMin(), mBounds.yMin());

    x = static_cast<int>(std::ceil((pos.x() - min.x()) / mMapWorldSize) - 1);
    y = static_cast<int>(std::ceil((pos.y() - min.y()) / mMapWorldSize) - 1);

    nX = (pos.x() - min.x() - mMapWorldSize*x)/mMapWorldSize;
    nY = 1.0f-(pos.y() - min.y() - mMapWorldSize*y)/mMapWorldSize;
}

osg::Vec2f LocalMap::interiorMapToWorldPosition (float nX, float nY, int x, int y)
{
    osg::Vec2f min(mBounds.xMin(), mBounds.yMin());
    osg::Vec2f pos (mMapWorldSize * (nX + x) + min.x(),
                    mMapWorldSize * (1.0f-nY + y) + min.y());

    pos = rotatePoint(pos, osg::Vec2f(mBounds.center().x(), mBounds.center().y()), -mAngle);
    return pos;
}

bool LocalMap::isPositionExplored (float nX, float nY, int x, int y, bool interior)
{
    const MapSegment& segment = mSegments[std::make_pair(x, y)];
    if (!segment.mFogOfWarImage)
        return false;

    nX = std::max(0.f, std::min(1.f, nX));
    nY = std::max(0.f, std::min(1.f, nY));

    int texU = static_cast<int>((sFogOfWarResolution - 1) * nX);
    int texV = static_cast<int>((sFogOfWarResolution - 1) * nY);

    uint32_t clr = ((const uint32_t*)segment.mFogOfWarImage->data())[texV * sFogOfWarResolution + texU];
    uint8_t alpha = (clr >> 24);
    return alpha < 200;
}

osg::Group* LocalMap::getRoot()
{
    return mRoot;
}

void LocalMap::updatePlayer (const osg::Vec3f& position, const osg::Quat& orientation,
                             float& u, float& v, int& x, int& y, osg::Vec3f& direction)
{
    // retrieve the x,y grid coordinates the player is in
    osg::Vec2f pos(position.x(), position.y());

    if (mInterior)
    {
        worldToInteriorMapPosition(pos, u,v, x,y);

        osg::Quat cameraOrient (mAngle, osg::Vec3(0,0,-1));
        direction = orientation * cameraOrient.inverse() * osg::Vec3f(0,1,0);
    }
    else
    {
        direction = orientation * osg::Vec3f(0,1,0);

        x = static_cast<int>(std::ceil(pos.x() / mMapWorldSize) - 1);
        y = static_cast<int>(std::ceil(pos.y() / mMapWorldSize) - 1);

        // convert from world coordinates to texture UV coordinates
        u = std::abs((pos.x() - (mMapWorldSize*x))/mMapWorldSize);
        v = 1.0f-std::abs((pos.y() - (mMapWorldSize*y))/mMapWorldSize);
    }

    // explore radius (squared)
    const float exploreRadius = (mInterior ? 0.1f : 0.3f) * (sFogOfWarResolution-1); // explore radius from 0 to sFogOfWarResolution-1
    const float sqrExploreRadius = square(exploreRadius);
    const float exploreRadiusUV = exploreRadius / sFogOfWarResolution; // explore radius from 0 to 1 (UV space)

    // change the affected fog of war textures (in a 3x3 grid around the player)
    for (int mx = -1; mx<2; ++mx)
    {
        for (int my = -1; my<2; ++my)
        {
            // is this texture affected at all?
            bool affected = false;
            if (mx == 0 && my == 0) // the player is always in the center of the 3x3 grid
                affected = true;
            else
            {
                bool affectsX = (mx > 0)? (u + exploreRadiusUV > 1) : (u - exploreRadiusUV < 0);
                bool affectsY = (my > 0)? (v + exploreRadiusUV > 1) : (v - exploreRadiusUV < 0);
                affected = (affectsX && (my == 0)) || (affectsY && mx == 0) || (affectsX && affectsY);
            }

            if (!affected)
                continue;

            int texX = x + mx;
            int texY = y + my*-1;

            MapSegment& segment = mSegments[std::make_pair(texX, texY)];

            if (!segment.mFogOfWarImage || !segment.mMapTexture)
                continue;

            unsigned char* data = segment.mFogOfWarImage->data();
            for (int texV = 0; texV<sFogOfWarResolution; ++texV)
            {
                for (int texU = 0; texU<sFogOfWarResolution; ++texU)
                {
                    float sqrDist = square((texU + mx*(sFogOfWarResolution-1)) - u*(sFogOfWarResolution-1))
                            + square((texV + my*(sFogOfWarResolution-1)) - v*(sFogOfWarResolution-1));

                    uint32_t clr = *(uint32_t*)data;
                    uint8_t alpha = (clr >> 24);

                    alpha = std::min( alpha, (uint8_t) (std::max(0.f, std::min(1.f, (sqrDist/sqrExploreRadius)))*255) );
                    *(uint32_t*)data = (uint32_t) (alpha << 24);

                    data += 4;
                }
            }

            segment.mHasFogState = true;
            segment.mFogOfWarImage->dirty();
        }
    }
}

LocalMap::MapSegment::MapSegment()
    : mHasFogState(false)
{
}

LocalMap::MapSegment::~MapSegment()
{

}

void LocalMap::MapSegment::createFogOfWarTexture()
{
    if (mFogOfWarTexture)
        return;
    mFogOfWarTexture = new osg::Texture2D;
    // TODO: synchronize access? for now, the worst that could happen is the draw thread jumping a frame ahead.
    //mFogOfWarTexture->setDataVariance(osg::Object::DYNAMIC);
    mFogOfWarTexture->setFilter(osg::Texture::MIN_FILTER, osg::Texture::LINEAR);
    mFogOfWarTexture->setFilter(osg::Texture::MAG_FILTER, osg::Texture::LINEAR);
    mFogOfWarTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_EDGE);
    mFogOfWarTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_EDGE);
    mFogOfWarTexture->setUnRefImageDataAfterApply(false);
}

void LocalMap::MapSegment::initFogOfWar()
{
    mFogOfWarImage = new osg::Image;
    // Assign a PixelBufferObject for asynchronous transfer of data to the GPU
    mFogOfWarImage->setPixelBufferObject(new osg::PixelBufferObject);
    mFogOfWarImage->allocateImage(sFogOfWarResolution, sFogOfWarResolution, 1, GL_RGBA, GL_UNSIGNED_BYTE);
    assert(mFogOfWarImage->isDataContiguous());
    std::vector<uint32_t> data;
    data.resize(sFogOfWarResolution*sFogOfWarResolution, 0xff000000);

    memcpy(mFogOfWarImage->data(), &data[0], data.size()*4);

    createFogOfWarTexture();
    mFogOfWarTexture->setImage(mFogOfWarImage);
}

void LocalMap::MapSegment::loadFogOfWar(const ESM::FogTexture &esm)
{
    const std::vector<char>& data = esm.mImageData;
    if (!data.size())
    {
        initFogOfWar();
        return;
    }

    // TODO: deprecate tga and use raw data instead

    osgDB::ReaderWriter* readerwriter = osgDB::Registry::instance()->getReaderWriterForExtension("tga");
    if (!readerwriter)
    {
        std::cerr << "Unable to load fog, can't find a tga ReaderWriter" << std::endl;
        return;
    }

    Files::IMemStream in(&data[0], data.size());

    osgDB::ReaderWriter::ReadResult result = readerwriter->readImage(in);
    if (!result.success())
    {
        std::cerr << "Failed to read fog: " << result.message() << std::endl;
        return;
    }

    mFogOfWarImage = result.getImage();
    mFogOfWarImage->flipVertical();
    mFogOfWarImage->dirty();

    createFogOfWarTexture();
    mFogOfWarTexture->setImage(mFogOfWarImage);
    mHasFogState = true;
}

void LocalMap::MapSegment::saveFogOfWar(ESM::FogTexture &fog) const
{
    if (!mFogOfWarImage)
        return;

    std::ostringstream ostream;

    osgDB::ReaderWriter* readerwriter = osgDB::Registry::instance()->getReaderWriterForExtension("tga");
    if (!readerwriter)
    {
        std::cerr << "Unable to write fog, can't find a tga ReaderWriter" << std::endl;
        return;
    }

    // extra flips are unfortunate, but required for compatibility with older versions
    mFogOfWarImage->flipVertical();
    osgDB::ReaderWriter::WriteResult result = readerwriter->writeImage(*mFogOfWarImage, ostream);
    if (!result.success())
    {
        std::cerr << "Unable to write fog: " << result.message() << std::endl;
        return;
    }
    mFogOfWarImage->flipVertical();

    std::string data = ostream.str();
    fog.mImageData = std::vector<char>(data.begin(), data.end());
}

}
