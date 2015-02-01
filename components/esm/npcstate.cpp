
#include "components/esm/creaturestats.hpp"
#include "components/esm/inventorystate.hpp"
#include "components/esm/npcstats.hpp"
#include "components/esm/objectstate.hpp"
#include "npcstate.hpp"

namespace ESM {
class ESMReader;
class ESMWriter;
}  // namespace ESM

void ESM::NpcState::load (ESMReader &esm)
{
    ObjectState::load (esm);

    if (mHasCustomState)
    {
        mInventory.load (esm);

        mNpcStats.load (esm);

        mCreatureStats.load (esm);
    }
}

void ESM::NpcState::save (ESMWriter &esm, bool inInventory) const
{
    ObjectState::save (esm, inInventory);

    if (mHasCustomState)
    {
        mInventory.save (esm);

        mNpcStats.save (esm);

        mCreatureStats.save (esm);
    }
}

void ESM::NpcState::blank()
{
    ObjectState::blank();
    mNpcStats.blank();
    mCreatureStats.blank();
    mHasCustomState = true;
}
