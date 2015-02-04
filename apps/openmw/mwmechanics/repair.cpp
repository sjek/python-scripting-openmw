#include <boost/format/alt_sstream.hpp>
#include <boost/format/format_class.hpp>
#include <boost/format/format_fwd.hpp>
#include <boost/format/format_implementation.hpp>
#include <stdlib.h>
#include <algorithm>
#include <string>

#include "../mwbase/environment.hpp"
#include "../mwbase/soundmanager.hpp"
#include "../mwbase/windowmanager.hpp"
#include "../mwbase/world.hpp"
#include "../mwmechanics/creaturestats.hpp"
#include "../mwmechanics/npcstats.hpp"
#include "../mwworld/class.hpp"
#include "../mwworld/containerstore.hpp"
#include "../mwworld/esmstore.hpp"
#include "apps/openmw/mwmechanics/../mwbase/../mwmechanics/stat.hpp"
#include "apps/openmw/mwmechanics/../mwworld/../mwscript/locals.hpp"
#include "apps/openmw/mwmechanics/../mwworld/cellref.hpp"
#include "apps/openmw/mwmechanics/../mwworld/livecellref.hpp"
#include "apps/openmw/mwmechanics/../mwworld/ptr.hpp"
#include "apps/openmw/mwmechanics/../mwworld/refdata.hpp"
#include "apps/openmw/mwmechanics/../mwworld/store.hpp"
#include "components/esm/attr.hpp"
#include "components/esm/loadgmst.hpp"
#include "components/esm/loadrepa.hpp"
#include "components/esm/loadskil.hpp"
#include "components/misc/stringops.hpp"
#include "repair.hpp"

namespace MWMechanics
{

void Repair::repair(const MWWorld::Ptr &itemToRepair)
{
    MWWorld::Ptr player = MWBase::Environment::get().getWorld()->getPlayerPtr();
    MWWorld::LiveCellRef<ESM::Repair> *ref =
        mTool.get<ESM::Repair>();

    // unstack tool if required
    player.getClass().getContainerStore(player).unstack(mTool, player);

    // reduce number of uses left
    int uses = mTool.getClass().getItemHealth(mTool);
    mTool.getCellRef().setCharge(uses-1);

    MWMechanics::CreatureStats& stats = player.getClass().getCreatureStats(player);
    MWMechanics::NpcStats& npcStats = player.getClass().getNpcStats(player);

    float fatigueTerm = stats.getFatigueTerm();
    int pcStrength = stats.getAttribute(ESM::Attribute::Strength).getModified();
    int pcLuck = stats.getAttribute(ESM::Attribute::Luck).getModified();
    int armorerSkill = npcStats.getSkill(ESM::Skill::Armorer).getModified();

    float fRepairAmountMult = MWBase::Environment::get().getWorld()->getStore().get<ESM::GameSetting>()
            .find("fRepairAmountMult")->getFloat();

    float toolQuality = ref->mBase->mData.mQuality;

    float x = (0.1 * pcStrength + 0.1 * pcLuck + armorerSkill) * fatigueTerm;

    int roll = static_cast<float> (std::rand()) / RAND_MAX * 100;
    if (roll <= x)
    {
        int y = fRepairAmountMult * toolQuality * roll;
        y = std::max(1, y);

        // repair by 'y' points
        int charge = itemToRepair.getClass().getItemHealth(itemToRepair);
        charge = std::min(charge + y, itemToRepair.getClass().getItemMaxHealth(itemToRepair));
        itemToRepair.getCellRef().setCharge(charge);

        // attempt to re-stack item, in case it was fully repaired
        MWWorld::ContainerStoreIterator stacked = player.getClass().getContainerStore(player).restack(itemToRepair);

        // set the OnPCRepair variable on the item's script
        std::string script = stacked->getClass().getScript(itemToRepair);
        if(script != "")
            stacked->getRefData().getLocals().setVarByInt(script, "onpcrepair", 1);

        // increase skill
        player.getClass().skillUsageSucceeded(player, ESM::Skill::Armorer, 0);

        MWBase::Environment::get().getSoundManager()->playSound("Repair",1,1);
        MWBase::Environment::get().getWindowManager()->messageBox("#{sRepairSuccess}");
    }
    else
    {
        MWBase::Environment::get().getSoundManager()->playSound("Repair Fail",1,1);
        MWBase::Environment::get().getWindowManager()->messageBox("#{sRepairFailed}");
    }

    // tool used up?
    if (mTool.getCellRef().getCharge() == 0)
    {
        MWWorld::Ptr player = MWBase::Environment::get().getWorld()->getPlayerPtr();
        MWWorld::ContainerStore& store = player.getClass().getContainerStore(player);

        store.remove(mTool, 1, player);

        std::string message = MWBase::Environment::get().getWorld()->getStore().get<ESM::GameSetting>()
                .find("sNotifyMessage51")->getString();

        MWBase::Environment::get().getWindowManager()->messageBox((boost::format(message) % mTool.getClass().getName(mTool)).str());

        // try to find a new tool of the same ID
        for (MWWorld::ContainerStoreIterator iter (store.begin());
             iter!=store.end(); ++iter)
        {
            if (Misc::StringUtils::ciEqual(iter->getCellRef().getRefId(), mTool.getCellRef().getRefId()))
            {
                mTool = *iter;
                break;
            }
        }
    }
}

}
