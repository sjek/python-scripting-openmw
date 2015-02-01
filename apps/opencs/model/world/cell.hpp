#ifndef CSM_WOLRD_CELL_H
#define CSM_WOLRD_CELL_H

#include <components/esm/loadcell.hpp>
#include <string>
#include <vector>

namespace ESM {
class ESMReader;
}  // namespace ESM

namespace CSMWorld
{
    /// \brief Wrapper for Cell record
    ///
    /// \attention The mData.mX and mData.mY fields of the ESM::Cell struct are not used.
    /// Exterior cell coordinates are encoded in the cell ID.
    struct Cell : public ESM::Cell
    {
        std::string mId;

        void load (ESM::ESMReader &esm);

    };
}

#endif
