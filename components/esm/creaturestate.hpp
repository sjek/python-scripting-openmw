#ifndef OPENMW_ESM_CREATURESTATE_H
#define OPENMW_ESM_CREATURESTATE_H

#include "creaturestats.hpp"
#include "inventorystate.hpp"
#include "objectstate.hpp"

namespace ESM {
class ESMReader;
class ESMWriter;
}  // namespace ESM

namespace ESM
{
    // format 0, saved games only

    struct CreatureState : public ObjectState
    {
        InventoryState mInventory;
        CreatureStats mCreatureStats;

        /// Initialize to default state
        void blank();

        virtual void load (ESMReader &esm);
        virtual void save (ESMWriter &esm, bool inInventory = false) const;
    };
}

#endif
