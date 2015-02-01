
#include "components/esm/creaturestats.hpp"
#include "components/esm/inventorystate.hpp"
#include "components/esm/objectstate.hpp"
#include "creaturestate.hpp"

namespace ESM {
class ESMReader;
class ESMWriter;
}  // namespace ESM

void ESM::CreatureState::load (ESMReader &esm)
{
    ObjectState::load (esm);

    if (mHasCustomState)
    {
        mInventory.load (esm);

        mCreatureStats.load (esm);
    }
}

void ESM::CreatureState::save (ESMWriter &esm, bool inInventory) const
{
    ObjectState::save (esm, inInventory);

    if (mHasCustomState)
    {
        mInventory.save (esm);

        mCreatureStats.save (esm);
    }
}

void ESM::CreatureState::blank()
{
    ObjectState::blank();
    mCreatureStats.blank();
}
