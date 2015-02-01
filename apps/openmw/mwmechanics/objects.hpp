#ifndef GAME_MWMECHANICS_ACTIVATORS_H
#define GAME_MWMECHANICS_ACTIVATORS_H

#include <map>
#include <string>
#include <vector>

#include "apps/openmw/mwmechanics/../mwworld/ptr.hpp"
#include "character.hpp"

namespace MWMechanics {
class CharacterController;
}  // namespace MWMechanics
namespace Ogre {
class Vector3;
}  // namespace Ogre

namespace MWWorld
{
    class CellStore;
    class Ptr;
}

namespace MWMechanics
{
    class Objects
    {
        typedef std::map<MWWorld::Ptr,CharacterController*> PtrControllerMap;
        PtrControllerMap mObjects;

    public:
        Objects();
        ~Objects();

        void addObject (const MWWorld::Ptr& ptr);
        ///< Register an animated object

        void removeObject (const MWWorld::Ptr& ptr);
        ///< Deregister an object

        void updateObject(const MWWorld::Ptr &old, const MWWorld::Ptr& ptr);
        ///< Updates an object with a new Ptr

        void dropObjects(const MWWorld::CellStore *cellStore);
        ///< Deregister all objects in the given cell.

        void update(float duration, bool paused);
        ///< Update object animations

        void playAnimationGroup(const MWWorld::Ptr& ptr, const std::string& groupName, int mode, int number);
        void skipAnimation(const MWWorld::Ptr& ptr);

        void getObjectsInRange (const Ogre::Vector3& position, float radius, std::vector<MWWorld::Ptr>& out);
    };
}

#endif
