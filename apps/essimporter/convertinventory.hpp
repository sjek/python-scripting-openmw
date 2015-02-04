#ifndef OPENMW_ESSIMPORT_CONVERTINVENTORY_H
#define OPENMW_ESSIMPORT_CONVERTINVENTORY_H

#include <components/esm/inventorystate.hpp>

#include "importinventory.hpp"

namespace ESM {
struct InventoryState;
}  // namespace ESM
namespace ESSImport {
struct Inventory;
}  // namespace ESSImport

namespace ESSImport
{

    void convertInventory (const Inventory& inventory, ESM::InventoryState& state);

}

#endif
