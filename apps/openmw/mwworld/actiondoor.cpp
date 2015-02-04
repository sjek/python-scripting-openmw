#include "../mwbase/environment.hpp"
#include "../mwbase/world.hpp"
#include "actiondoor.hpp"
#include "apps/openmw/mwworld/action.hpp"

namespace MWWorld {
class Ptr;
}  // namespace MWWorld

namespace MWWorld
{
    ActionDoor::ActionDoor (const MWWorld::Ptr& object) : Action (false, object)
    {
    }

    void ActionDoor::executeImp (const MWWorld::Ptr& actor)
    {
        MWBase::Environment::get().getWorld()->activateDoor(getTarget());
    }
}
