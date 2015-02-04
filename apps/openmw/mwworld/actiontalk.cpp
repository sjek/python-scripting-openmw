
#include "../mwbase/dialoguemanager.hpp"
#include "../mwbase/environment.hpp"
#include "actiontalk.hpp"
#include "apps/openmw/mwworld/action.hpp"

namespace MWWorld {
class Ptr;
}  // namespace MWWorld

namespace MWWorld
{
    ActionTalk::ActionTalk (const Ptr& actor) : Action (false, actor) {}

    void ActionTalk::executeImp (const Ptr& actor)
    {
        MWBase::Environment::get().getDialogueManager()->startDialogue (getTarget());
    }
}
