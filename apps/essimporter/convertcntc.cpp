#include "apps/essimporter/importcntc.hpp"
#include "components/esm/containerstate.hpp"
#include "convertcntc.hpp"
#include "convertinventory.hpp"

namespace ESSImport
{

    void convertCNTC(const CNTC &cntc, ESM::ContainerState &state)
    {
        convertInventory(cntc.mInventory, state.mInventory);
    }

}
