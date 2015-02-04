#ifndef CSM_WOLRD_PATHGRID_H
#define CSM_WOLRD_PATHGRID_H

#include <components/esm/loadpgrd.hpp>
#include <string>
#include <vector>

#include "cell.hpp"
#include "idcollection.hpp"

namespace CSMWorld {
struct Cell;
}  // namespace CSMWorld
namespace ESM {
class ESMReader;
}  // namespace ESM

namespace CSMWorld
{
    /// \brief Wrapper for Pathgrid record
    ///
    /// \attention The mData.mX and mData.mY fields of the ESM::Pathgrid struct are not used.
    /// Exterior cell coordinates are encoded in the pathgrid ID.
    struct Pathgrid : public ESM::Pathgrid
    {
        std::string mId;

        void load (ESM::ESMReader &esm, const IdCollection<Cell>& cells);

        void load (ESM::ESMReader &esm);
    };
}

#endif
