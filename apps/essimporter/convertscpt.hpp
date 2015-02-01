#ifndef OPENMW_ESSIMPORT_CONVERTSCPT_H
#define OPENMW_ESSIMPORT_CONVERTSCPT_H

#include <components/esm/globalscript.hpp>

#include "importscpt.hpp"

namespace ESM {
struct GlobalScript;
}  // namespace ESM
namespace ESSImport {
struct SCPT;
}  // namespace ESSImport

namespace ESSImport
{

void convertSCPT(const SCPT& scpt, ESM::GlobalScript& out);

}

#endif
