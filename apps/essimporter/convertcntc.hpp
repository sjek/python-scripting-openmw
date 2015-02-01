#ifndef OPENMW_ESSIMPORT_CONVERTCNTC_H
#define OPENMW_ESSIMPORT_CONVERTCNTC_H

#include <components/esm/containerstate.hpp>

#include "importcntc.hpp"

namespace ESM {
struct ContainerState;
}  // namespace ESM
namespace ESSImport {
struct CNTC;
}  // namespace ESSImport

namespace ESSImport
{

    void convertCNTC(const CNTC& cntc, ESM::ContainerState& state);

}

#endif
