#ifndef GAME_MWWORLD_FAILEDACTION_H
#define GAME_MWWORLD_FAILEDACTION_H

#include <string>

#include "action.hpp"
#include "ptr.hpp"

namespace MWWorld {
class Ptr;
}  // namespace MWWorld

namespace MWWorld
{
    class FailedAction : public Action
    {
        std::string mMessage;

        virtual void executeImp(const Ptr &actor);

    public:
        FailedAction(const std::string &message = std::string());
    };
}

#endif
