#include <components/misc/stringops.hpp>
#include <string>

#include "apps/essimporter/importscpt.hpp"
#include "components/esm/esmcommon.hpp"
#include "components/esm/globalscript.hpp"
#include "components/esm/loadscpt.hpp"
#include "convertscpt.hpp"
#include "convertscri.hpp"

namespace ESSImport
{

    void convertSCPT(const SCPT &scpt, ESM::GlobalScript &out)
    {
        out.mId = Misc::StringUtils::lowerCase(scpt.mSCHD.mName.toString());
        out.mRunning = scpt.mRunning;
        convertSCRI(scpt.mSCRI, out.mLocals);
    }

}
