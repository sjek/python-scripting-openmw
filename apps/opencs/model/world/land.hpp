#ifndef CSM_WORLD_LAND_H
#define CSM_WORLD_LAND_H

#include <boost/shared_ptr.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <components/esm/loadland.hpp>
#include <string>

namespace ESM {
class ESMReader;
struct Land;
}  // namespace ESM

namespace CSMWorld
{
    /// \brief Wrapper for Land record. Encodes X and Y cell index in the ID.
    ///
    /// \todo Add worldspace support to the Land record.
    /// \todo Add a proper copy constructor (currently worked around using shared_ptr)
    struct Land
    {
        Land();

        boost::shared_ptr<ESM::Land> mLand;

        std::string mId;

        /// Loads the metadata and ID
        void load (ESM::ESMReader &esm);

        void blank();
    };
}

#endif
