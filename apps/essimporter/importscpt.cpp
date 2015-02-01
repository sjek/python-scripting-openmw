#include <components/esm/esmreader.hpp>

#include "apps/essimporter/importscri.hpp"
#include "components/esm/loadscpt.hpp"
#include "importscpt.hpp"



namespace ESSImport
{

    void SCPT::load(ESM::ESMReader &esm)
    {
        esm.getHNT(mSCHD, "SCHD");

        mSCRI.load(esm);

        mRefNum = -1;
        if (esm.isNextSub("RNAM"))
        {
            mRunning = true;
            esm.getHT(mRefNum);
        }
        else
            mRunning = false;
    }

}
