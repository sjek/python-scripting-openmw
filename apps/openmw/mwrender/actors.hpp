#ifndef GAME_RENDER_ACTORS_H
#define GAME_RENDER_ACTORS_H

#include <openengine/ogre/renderer.hpp>
#include <stddef.h>
#include <map>
#include <string>

#include "apps/openmw/mwrender/../mwworld/ptr.hpp"

namespace OEngine {
namespace Render {
class OgreRenderer;
}  // namespace Render
}  // namespace OEngine
namespace Ogre {
class Camera;
class SceneNode;
}  // namespace Ogre

namespace MWWorld
{
    class CellStore;
    class InventoryStore;
    class Ptr;
}

namespace MWRender
{
    class Animation;
    class RenderingManager;

    class Actors
    {
        typedef std::map<MWWorld::CellStore*,Ogre::SceneNode*> CellSceneNodeMap;
        typedef std::map<MWWorld::Ptr,Animation*> PtrAnimationMap;

        OEngine::Render::OgreRenderer &mRend;
        MWRender::RenderingManager* mRendering;
        Ogre::SceneNode* mRootNode;

        CellSceneNodeMap mCellSceneNodes;
        PtrAnimationMap mAllActors;

        void insertBegin(const MWWorld::Ptr &ptr);

    public:
        Actors(OEngine::Render::OgreRenderer& _rend, MWRender::RenderingManager* rendering)
            : mRend(_rend)
            , mRendering(rendering)
            , mRootNode(NULL)
        {}
        ~Actors();

        void setRootNode(Ogre::SceneNode* root);

        void insertNPC(const MWWorld::Ptr& ptr);
        void insertCreature (const MWWorld::Ptr& ptr, const std::string& model, bool weaponsShields);
        void insertActivator (const MWWorld::Ptr& ptr, const std::string& model, bool addLight=false);
        bool deleteObject (const MWWorld::Ptr& ptr);
        ///< \return found?

        void enableLights();
        void disableLights();

        void removeCell(MWWorld::CellStore* store);

        void update (Ogre::Camera* camera);

        /// Updates containing cell for object rendering data
        void updateObjectCell(const MWWorld::Ptr &old, const MWWorld::Ptr &cur);

        Animation* getAnimation(const MWWorld::Ptr &ptr);
    };
}
#endif
