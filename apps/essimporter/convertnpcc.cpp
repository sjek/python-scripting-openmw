#include "apps/essimporter/importnpcc.hpp"
#include "components/esm/npcstate.hpp"
#include "components/esm/npcstats.hpp"
#include "convertinventory.hpp"
#include "convertnpcc.hpp"

namespace ESSImport
{

    void convertNPCC(const NPCC &npcc, ESM::NpcState &npcState)
    {
        npcState.mNpcStats.mDisposition = npcc.mNPDT.mDisposition;
        npcState.mNpcStats.mReputation = npcc.mNPDT.mReputation;

        convertInventory(npcc.mInventory, npcState.mInventory);
    }
}
