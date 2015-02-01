#ifndef OPENMW_ESSIMPORT_CONVERTCREC_H
#define OPENMW_ESSIMPORT_CONVERTCREC_H

#include <components/esm/creaturestate.hpp>

#include "importcrec.hpp"

namespace ESM {
struct CreatureState;
}  // namespace ESM
namespace ESSImport {
struct CREC;
}  // namespace ESSImport

namespace ESSImport
{

    void convertCREC(const CREC& crec, ESM::CreatureState& state);

}

#endif
