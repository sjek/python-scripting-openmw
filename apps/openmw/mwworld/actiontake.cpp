
#include "../mwbase/environment.hpp"
#include "../mwbase/mechanicsmanager.hpp"
#include "../mwbase/world.hpp"
#include "actiontake.hpp"
#include "apps/openmw/mwworld/action.hpp"
#include "apps/openmw/mwworld/ptr.hpp"
#include "apps/openmw/mwworld/refdata.hpp"
#include "class.hpp"
#include "containerstore.hpp"

namespace MWWorld
{
    ActionTake::ActionTake (const MWWorld::Ptr& object) : Action (true, object) {}

    void ActionTake::executeImp (const Ptr& actor)
    {
        MWBase::Environment::get().getMechanicsManager()->itemTaken(
                    actor, getTarget(), getTarget().getRefData().getCount());
        actor.getClass().getContainerStore (actor).add (getTarget(), getTarget().getRefData().getCount(), actor);
        MWBase::Environment::get().getWorld()->deleteObject (getTarget());
    }
}
