#include "../mwbase/environment.hpp"
#include "../mwbase/windowmanager.hpp"
#include "../mwbase/world.hpp"
#include "../mwworld/player.hpp"
#include "actionrepair.hpp"
#include "apps/openmw/mwworld/../mwbase/../mwgui/mode.hpp"
#include "apps/openmw/mwworld/action.hpp"

namespace MWWorld {
class Ptr;
}  // namespace MWWorld

namespace MWWorld
{
    ActionRepair::ActionRepair(const Ptr &item)
        : Action(false, item)
    {
    }

    void ActionRepair::executeImp (const Ptr& actor)
    {
        if(MWBase::Environment::get().getWorld()->getPlayer().isInCombat()) {
            MWBase::Environment::get().getWindowManager()->messageBox("#{sInventoryMessage2}");
            return;
        }

        MWBase::Environment::get().getWindowManager()->pushGuiMode(MWGui::GM_Repair);
        MWBase::Environment::get().getWindowManager()->startRepairItem(getTarget());
    }
}
