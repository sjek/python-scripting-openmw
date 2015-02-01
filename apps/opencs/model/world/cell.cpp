
#include <sstream>

#include "cell.hpp"
#include "components/esm/loadcell.hpp"

namespace ESM {
class ESMReader;
}  // namespace ESM

void CSMWorld::Cell::load (ESM::ESMReader &esm)
{
    mName = mId;

    ESM::Cell::load (esm, false);

    if (!(mData.mFlags & Interior))
    {
        std::ostringstream stream;

        stream << "#" << mData.mX << " " << mData.mY;

        mId = stream.str();
    }
}
