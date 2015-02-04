
#include "components/esm/inventorystate.hpp"
#include "components/esm/objectstate.hpp"
#include "containerstate.hpp"

namespace ESM {
class ESMReader;
class ESMWriter;
}  // namespace ESM

void ESM::ContainerState::load (ESMReader &esm)
{
    ObjectState::load (esm);

    mInventory.load (esm);
}

void ESM::ContainerState::save (ESMWriter &esm, bool inInventory) const
{
    ObjectState::save (esm, inInventory);

    mInventory.save (esm);
}
