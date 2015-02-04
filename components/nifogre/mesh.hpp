#ifndef COMPONENTS_NIFOGRE_MESH_HPP
#define COMPONENTS_NIFOGRE_MESH_HPP

#include <OgreResource.h>
#include <stddef.h>
#include <stdlib.h>
#include <cassert>
#include <iostream>
#include <map>
#include <string>

namespace Ogre {
class Mesh;
}  // namespace Ogre

namespace Nif
{
    class NiTriShape;
}

namespace NifOgre
{

/** Manual resource loader for NiTriShapes. This is the main class responsible
 * for translating the internal NIF meshes into something Ogre can use.
 */
class NIFMeshLoader : Ogre::ManualResourceLoader
{
    static void warn(const std::string &msg)
    {
        std::cerr << "NIFMeshLoader: Warn: " << msg << std::endl;
    }

    static void fail(const std::string &msg)
    {
        std::cerr << "NIFMeshLoader: Fail: "<< msg << std::endl;
        abort();
    }

    std::string mName;
    std::string mGroup;
    size_t mShapeIndex;

    // Convert NiTriShape to Ogre::SubMesh
    void createSubMesh(Ogre::Mesh *mesh, const Nif::NiTriShape *shape);

    typedef std::map<std::string,NIFMeshLoader> LoaderMap;
    static LoaderMap sLoaders;

    NIFMeshLoader(const std::string &name, const std::string &group, size_t idx);

    virtual void loadResource(Ogre::Resource *resource);

public:
    static void createMesh(const std::string &name, const std::string &fullname, const std::string &group, size_t idx);
};

}

#endif
