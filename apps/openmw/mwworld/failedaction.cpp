#include "../mwbase/environment.hpp"
#include "../mwbase/windowmanager.hpp"
#include "apps/openmw/mwworld/action.hpp"
#include "apps/openmw/mwworld/ptr.hpp"
#include "apps/openmw/mwworld/refdata.hpp"
#include "failedaction.hpp"


namespace MWWorld
{
    FailedAction::FailedAction(const std::string &msg)
      : Action(false), mMessage(msg)
    {   }

    void FailedAction::executeImp(const Ptr &actor)
    {
        if(actor.getRefData().getHandle() == "player" && !mMessage.empty())
            MWBase::Environment::get().getWindowManager()->messageBox(mMessage);
    }
}
