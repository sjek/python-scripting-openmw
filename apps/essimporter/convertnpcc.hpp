#ifndef OPENMW_ESSIMPORT_CONVERTNPCC_H
#define OPENMW_ESSIMPORT_CONVERTNPCC_H

#include <components/esm/npcstate.hpp>

#include "importnpcc.hpp"

namespace ESM {
struct NpcState;
}  // namespace ESM
namespace ESSImport {
struct NPCC;
}  // namespace ESSImport

namespace ESSImport
{

    void convertNPCC (const NPCC& npcc, ESM::NpcState& npcState);

}

#endif
