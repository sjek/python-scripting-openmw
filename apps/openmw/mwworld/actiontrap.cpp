#include <OgreVector3.h>

#include "../mwmechanics/spellcasting.hpp"
#include "actiontrap.hpp"
#include "apps/openmw/mwworld/cellref.hpp"
#include "apps/openmw/mwworld/ptr.hpp"
#include "apps/openmw/mwworld/refdata.hpp"
#include "components/esm/defs.hpp"

namespace MWWorld
{

    void ActionTrap::executeImp(const Ptr &actor)
    {
        MWMechanics::CastSpell cast(mTrapSource, actor);
        cast.mHitPosition = Ogre::Vector3(actor.getRefData().getPosition().pos);
        cast.cast(mSpellId);

        mTrapSource.getCellRef().setTrap("");
    }

}
