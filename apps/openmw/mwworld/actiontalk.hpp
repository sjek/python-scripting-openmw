#ifndef GAME_MWWORLD_ACTIONTALK_H
#define GAME_MWWORLD_ACTIONTALK_H

#include "action.hpp"
#include "ptr.hpp"

namespace MWWorld {
class Ptr;
}  // namespace MWWorld

namespace MWWorld
{
    class ActionTalk : public Action
    {
            virtual void executeImp (const Ptr& actor);

        public:

            ActionTalk (const Ptr& actor);
            ///< \param actor The actor the player is talking to
    };
}

#endif
