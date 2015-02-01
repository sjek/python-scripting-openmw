#include "../mwbase/environment.hpp"
#include "../mwbase/windowmanager.hpp"
#include "../mwbase/world.hpp"
#include "../mwworld/player.hpp"
#include "actionsoulgem.hpp"
#include "apps/openmw/mwworld/action.hpp"

namespace MWWorld {
class Ptr;
}  // namespace MWWorld

namespace MWWorld
{

    ActionSoulgem::ActionSoulgem(const Ptr &object)
        : Action(false, object)
    {

    }

    void ActionSoulgem::executeImp(const Ptr &actor)
    {
        if(MWBase::Environment::get().getWorld()->getPlayer().isInCombat()) { //Ensure we're not in combat
            MWBase::Environment::get().getWindowManager()->messageBox("#{sInventoryMessage5}");
            return;
        }
        MWBase::Environment::get().getWindowManager()->showSoulgemDialog(getTarget());
    }


}
