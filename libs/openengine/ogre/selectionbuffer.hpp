#ifndef OENGINE_SELECTIONBUFFER_H
#define OENGINE_SELECTIONBUFFER_H


#include <OgreColourValue.h>
#include <OgreImage.h>
#include <OgreMaterialManager.h>
#include <OgrePrerequisites.h>
#include <OgreRenderTarget.h>
#include <OgreResource.h>
#include <OgreSharedPtr.h>
#include <OgreTechnique.h>
#include <OgreTexture.h>
#include <map>

namespace Ogre {
class Camera;
class Material;
class RenderTexture;
class Renderable;
}  // namespace Ogre

namespace OEngine
{
namespace Render
{

    struct cmp_ColourValue
    {
        bool operator()(const Ogre::ColourValue &a, const Ogre::ColourValue &b) const
        {
        return a.getAsBGRA() < b.getAsBGRA();
        }
    };

    class SelectionBuffer : public Ogre::MaterialManager::Listener, public Ogre::ManualResourceLoader
    {
    public:
        SelectionBuffer(Ogre::Camera* camera, int sizeX, int sizeY, int visibilityFlags);
        virtual ~SelectionBuffer();

        int getSelected(int xPos, int yPos);
        ///< @return ID of the selected object

        void update();

        virtual void loadResource(Ogre::Resource* resource);

        virtual Ogre::Technique* handleSchemeNotFound (
            unsigned short schemeIndex, const Ogre::String &schemeName, Ogre::Material *originalMaterial,
            unsigned short lodIndex, const Ogre::Renderable *rend);


    private:
        Ogre::TexturePtr mTexture;
        Ogre::RenderTexture* mRenderTarget;

        Ogre::Image mBuffer;

        std::map<Ogre::ColourValue, int, cmp_ColourValue> mColourMap;

        Ogre::ColourValue mCurrentColour;

        Ogre::Camera* mCamera;
        int mVisibilityFlags;

        void getNextColour();

        void setupRenderTarget();
    };

}
}

#endif
