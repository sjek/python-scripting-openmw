#ifndef COMPONENTS_NIFOGRE_MATERIAL_HPP
#define COMPONENTS_NIFOGRE_MATERIAL_HPP

#include <OgrePrerequisites.h>
#include <OgreString.h>
#include <stddef.h>
#include <cassert>
#include <iostream>
#include <map>
#include <string>

namespace Nif
{
    class NiAlphaProperty;
    class NiMaterialProperty;
    class NiSpecularProperty;
    class NiStencilProperty;
    class NiTexturingProperty;
    class NiVertexColorProperty;
    class NiWireframeProperty;
    class NiZBufferProperty;
    class ShapeData;
}

namespace NifOgre
{

class NIFMaterialLoader {
    static void warn(const std::string &msg)
    {
        std::cerr << "NIFMaterialLoader: Warn: " << msg << std::endl;
    }

    static std::map<size_t,std::string> sMaterialMap;

public:
    static Ogre::String getMaterial(const Nif::ShapeData *shapedata,
                                    const Ogre::String &name, const Ogre::String &group,
                                    const Nif::NiTexturingProperty *texprop,
                                    const Nif::NiMaterialProperty *matprop,
                                    const Nif::NiAlphaProperty *alphaprop,
                                    const Nif::NiVertexColorProperty *vertprop,
                                    const Nif::NiZBufferProperty *zprop,
                                    const Nif::NiSpecularProperty *specprop,
                                    const Nif::NiWireframeProperty *wireprop,
                                    const Nif::NiStencilProperty *stencilprop,
                                    bool &needTangents, bool particleMaterial=false);
};

}

#endif
