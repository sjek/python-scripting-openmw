#include "../mwbase/environment.hpp"
#include "../mwbase/windowmanager.hpp"
#include "../mwgui/container.hpp"
#include "../mwmechanics/disease.hpp"
#include "actionopen.hpp"
#include "apps/openmw/mwworld/../mwbase/../mwgui/mode.hpp"
#include "apps/openmw/mwworld/action.hpp"

namespace MWWorld {
class Ptr;
}  // namespace MWWorld

namespace MWWorld
{
    ActionOpen::ActionOpen (const MWWorld::Ptr& container, bool loot)
        : Action (false, container)
        , mLoot(loot)
    {
    }

    void ActionOpen::executeImp (const MWWorld::Ptr& actor)
    {
        if (!MWBase::Environment::get().getWindowManager()->isAllowed(MWGui::GW_Inventory))
            return;

        MWMechanics::diseaseContact(actor, getTarget());

        MWBase::Environment::get().getWindowManager()->pushGuiMode(MWGui::GM_Container);
        MWBase::Environment::get().getWindowManager()->getContainerWindow()->open(getTarget(), mLoot);
    }
}
