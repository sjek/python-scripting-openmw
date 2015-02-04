#include <components/esm/esmreader.hpp>

#include "apps/essimporter/importinventory.hpp"
#include "importcntc.hpp"

namespace ESSImport
{

    void CNTC::load(ESM::ESMReader &esm)
    {
        mIndex = 0;
        esm.getHNT(mIndex, "INDX");

        mInventory.load(esm);
    }

}
