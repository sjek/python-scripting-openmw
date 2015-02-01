#ifndef OPENMW_ESSIMPORT_CONVERTSCRI_H
#define OPENMW_ESSIMPORT_CONVERTSCRI_H

#include <components/esm/locals.hpp>

#include "importscri.hpp"

namespace ESM {
struct Locals;
}  // namespace ESM
namespace ESSImport {
struct SCRI;
}  // namespace ESSImport

namespace ESSImport
{

    /// Convert script variable assignments
    void convertSCRI (const SCRI& scri, ESM::Locals& locals);

}

#endif
