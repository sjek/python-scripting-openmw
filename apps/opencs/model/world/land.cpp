#include <sstream>

#include "components/esm/loadland.hpp"
#include "land.hpp"

namespace ESM {
class ESMReader;
}  // namespace ESM

namespace CSMWorld
{

    Land::Land()
    {
        mLand.reset(new ESM::Land());
    }

    void Land::load(ESM::ESMReader &esm)
    {
        mLand->load(esm);

        std::ostringstream stream;
        stream << "#" << mLand->mX << " " << mLand->mY;

        mId = stream.str();
    }

    void Land::blank()
    {
        /// \todo
    }

}
