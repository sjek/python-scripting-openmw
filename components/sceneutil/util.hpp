#ifndef OPENMW_COMPONENTS_SCENEUTIL_UTIL_H
#define OPENMW_COMPONENTS_SCENEUTIL_UTIL_H

#include <osg/Matrix>
#include <osg/BoundingSphere>
#include <osg/Vec4f>

namespace SceneUtil
{

    // Transform a bounding sphere by a matrix
    // based off private code in osg::Transform
    // TODO: patch osg to make public
    void transformBoundingSphere (const osg::Matrix& matrix, osg::BoundingSphere& bsphere);

    osg::Vec4f colourFromRGB (unsigned int clr);

    osg::Vec4f colourFromRGBA (unsigned int clr);

}

#endif
