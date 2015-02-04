#ifndef GAME_MWMECHANICS_AICOMBAT_H
#define GAME_MWMECHANICS_AICOMBAT_H

#include <OgreVector3.h>
#include <boost/shared_ptr.hpp>

#include "../mwbase/world.hpp"
#include "../mwworld/cellstore.hpp" // for Doors
#include "aipackage.hpp"
#include "apps/openmw/mwmechanics/../mwbase/../mwworld/ptr.hpp"
#include "apps/openmw/mwmechanics/aistate.hpp"
#include "movement.hpp"
#include "obstacle.hpp"
#include "pathfinding.hpp"

namespace ESM {
namespace AiSequence {
struct AiSequence;
}  // namespace AiSequence
}  // namespace ESM

namespace ESM
{
    namespace AiSequence
    {
        struct AiCombat;
    }
}

namespace MWMechanics
{
    class Action;

    /// \brief Causes the actor to fight another actor
    class AiCombat : public AiPackage
    {
        public:
            ///Constructor
            /** \param actor Actor to fight **/
            AiCombat(const MWWorld::Ptr& actor);

            AiCombat (const ESM::AiSequence::AiCombat* combat);

            void init();

            virtual AiCombat *clone() const;

            virtual bool execute (const MWWorld::Ptr& actor, AiState& state, float duration);

            virtual int getTypeId() const;

            virtual unsigned int getPriority() const;

            ///Returns target ID
            MWWorld::Ptr getTarget() const;

            virtual void writeState(ESM::AiSequence::AiSequence &sequence) const;

        private:

            int mTargetActorId;


            void buildNewPath(const MWWorld::Ptr& actor, const MWWorld::Ptr& target);
    };
    
    
}

#endif
