#include "../mwbase/environment.hpp"
#include "../mwbase/windowmanager.hpp"
#include "../mwbase/world.hpp"
#include "../mwgui/bookwindow.hpp"
#include "../mwgui/scrollwindow.hpp"
#include "../mwmechanics/npcstats.hpp"
#include "actionread.hpp"
#include "apps/openmw/mwworld/../mwbase/../mwgui/mode.hpp"
#include "apps/openmw/mwworld/action.hpp"
#include "apps/openmw/mwworld/livecellref.hpp"
#include "apps/openmw/mwworld/ptr.hpp"
#include "apps/openmw/mwworld/store.hpp"
#include "class.hpp"
#include "components/esm/loadbook.hpp"
#include "components/esm/loadclas.hpp"
#include "components/esm/loadnpc.hpp"
#include "components/esm/loadskil.hpp"
#include "esmstore.hpp"
#include "player.hpp"

namespace MWWorld
{
    ActionRead::ActionRead (const MWWorld::Ptr& object) : Action (false, object)
    {
    }

    void ActionRead::executeImp (const MWWorld::Ptr& actor) {

        //Ensure we're not in combat
        if(MWBase::Environment::get().getWorld()->getPlayer().isInCombat()
                // Reading in combat is still allowed if the scroll/book is not in the player inventory yet
                // (since otherwise, there would be no way to pick it up)
                && getTarget().getContainerStore() == &actor.getClass().getContainerStore(actor)
                ) {
            MWBase::Environment::get().getWindowManager()->messageBox("#{sInventoryMessage4}");
            return;
        }

        LiveCellRef<ESM::Book> *ref = getTarget().get<ESM::Book>();

        if (ref->mBase->mData.mIsScroll)
        {
            MWBase::Environment::get().getWindowManager()->pushGuiMode(MWGui::GM_Scroll);
            MWBase::Environment::get().getWindowManager()->getScrollWindow()->open(getTarget());
        }
        else
        {
            MWBase::Environment::get().getWindowManager()->pushGuiMode(MWGui::GM_Book);
            MWBase::Environment::get().getWindowManager()->getBookWindow()->open(getTarget());
        }

        MWWorld::Ptr player = MWBase::Environment::get().getWorld ()->getPlayerPtr();
        MWMechanics::NpcStats& npcStats = player.getClass().getNpcStats (player);

        // Skill gain from books
        if (ref->mBase->mData.mSkillID >= 0 && ref->mBase->mData.mSkillID < ESM::Skill::Length
                && !npcStats.hasBeenUsed (ref->mBase->mId))
        {
            MWWorld::LiveCellRef<ESM::NPC> *playerRef = player.get<ESM::NPC>();

            const ESM::Class *class_ =
                MWBase::Environment::get().getWorld()->getStore().get<ESM::Class>().find (
                    playerRef->mBase->mClass
                );

            npcStats.increaseSkill (ref->mBase->mData.mSkillID, *class_, true);

            npcStats.flagAsUsed (ref->mBase->mId);
        }

    }
}
