#include <stdlib.h>

#include "../mwbase/environment.hpp"
#include "../mwbase/mechanicsmanager.hpp"
#include "../mwbase/world.hpp"
#include "../mwworld/class.hpp"
#include "../mwworld/containerstore.hpp"
#include "../mwworld/esmstore.hpp"
#include "apps/openmw/mwmechanics/../mwbase/../mwmechanics/stat.hpp"
#include "apps/openmw/mwmechanics/../mwworld/cellref.hpp"
#include "apps/openmw/mwmechanics/../mwworld/livecellref.hpp"
#include "apps/openmw/mwmechanics/../mwworld/ptr.hpp"
#include "apps/openmw/mwmechanics/../mwworld/store.hpp"
#include "components/esm/attr.hpp"
#include "components/esm/loadgmst.hpp"
#include "components/esm/loadlock.hpp"
#include "components/esm/loadprob.hpp"
#include "components/esm/loadskil.hpp"
#include "components/esm/loadspel.hpp"
#include "creaturestats.hpp"
#include "npcstats.hpp"
#include "security.hpp"

namespace MWMechanics
{

    Security::Security(const MWWorld::Ptr &actor)
        : mActor(actor)
    {
        CreatureStats& creatureStats = actor.getClass().getCreatureStats(actor);
        NpcStats& npcStats = actor.getClass().getNpcStats(actor);
        mAgility = creatureStats.getAttribute(ESM::Attribute::Agility).getModified();
        mLuck = creatureStats.getAttribute(ESM::Attribute::Luck).getModified();
        mSecuritySkill = npcStats.getSkill(ESM::Skill::Security).getModified();
        mFatigueTerm = creatureStats.getFatigueTerm();
    }

    void Security::pickLock(const MWWorld::Ptr &lock, const MWWorld::Ptr &lockpick,
                            std::string& resultMessage, std::string& resultSound)
    {
        if (!(lock.getCellRef().getLockLevel() > 0)) //If it's unlocked back out immediately
            return;

        int lockStrength = lock.getCellRef().getLockLevel();

        float pickQuality = lockpick.get<ESM::Lockpick>()->mBase->mData.mQuality;

        float fPickLockMult = MWBase::Environment::get().getWorld()->getStore().get<ESM::GameSetting>().find("fPickLockMult")->getFloat();

        float x = 0.2 * mAgility + 0.1 * mLuck + mSecuritySkill;
        x *= pickQuality * mFatigueTerm;
        x += fPickLockMult * lockStrength;

        resultSound = "Open Lock Fail";
        if (x <= 0)
            resultMessage = "#{sLockImpossible}";
        else
        {
            MWBase::Environment::get().getMechanicsManager()->objectOpened(mActor, lock);
            int roll = static_cast<float> (std::rand()) / RAND_MAX * 100;
            if (roll <= x)
            {
                lock.getClass().unlock(lock);
                resultMessage = "#{sLockSuccess}";
                resultSound = "Open Lock";
                mActor.getClass().skillUsageSucceeded(mActor, ESM::Skill::Security, 1);
            }
            else
                resultMessage = "#{sLockFail}";
        }

        int uses = lockpick.getClass().getItemHealth(lockpick);
        --uses;
        lockpick.getCellRef().setCharge(uses);
        if (!uses)
            lockpick.getContainerStore()->remove(lockpick, 1, mActor);
    }

    void Security::probeTrap(const MWWorld::Ptr &trap, const MWWorld::Ptr &probe,
                             std::string& resultMessage, std::string& resultSound)
    {
        if (trap.getCellRef().getTrap()  == "")
            return;

        float probeQuality = probe.get<ESM::Probe>()->mBase->mData.mQuality;

        const ESM::Spell* trapSpell = MWBase::Environment::get().getWorld()->getStore().get<ESM::Spell>().find(trap.getCellRef().getTrap());
        float trapSpellPoints = trapSpell->mData.mCost;

        float fTrapCostMult = MWBase::Environment::get().getWorld()->getStore().get<ESM::GameSetting>().find("fTrapCostMult")->getFloat();

        float x = 0.2 * mAgility + 0.1 * mLuck + mSecuritySkill;
        x += fTrapCostMult * trapSpellPoints;
        x *= probeQuality * mFatigueTerm;

        resultSound = "Disarm Trap Fail";
        if (x <= 0)
            resultMessage = "#{sTrapImpossible}";
        else
        {
            MWBase::Environment::get().getMechanicsManager()->objectOpened(mActor, trap);
            int roll = static_cast<float> (std::rand()) / RAND_MAX * 100;
            if (roll <= x)
            {
                trap.getCellRef().setTrap("");

                resultSound = "Disarm Trap";
                resultMessage = "#{sTrapSuccess}";
                mActor.getClass().skillUsageSucceeded(mActor, ESM::Skill::Security, 0);
            }
            else
                resultMessage = "#{sTrapFail}";
        }

        int uses = probe.getClass().getItemHealth(probe);
        --uses;
        probe.getCellRef().setCharge(uses);
        if (!uses)
            probe.getContainerStore()->remove(probe, 1, mActor);
    }

}
