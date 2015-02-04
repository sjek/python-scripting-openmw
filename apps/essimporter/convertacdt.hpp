#ifndef OPENMW_ESSIMPORT_CONVERTACDT_H
#define OPENMW_ESSIMPORT_CONVERTACDT_H

#include <components/esm/creaturestats.hpp>
#include <components/esm/loadskil.hpp>
#include <components/esm/npcstats.hpp>

#include "importacdt.hpp"

namespace ESM {
struct CreatureStats;
struct NpcStats;
}  // namespace ESM
namespace ESSImport {
struct ACDT;
struct ActorData;
}  // namespace ESSImport

namespace ESSImport
{

    // OpenMW uses Health,Magicka,Fatigue, MW uses Health,Fatigue,Magicka
    int translateDynamicIndex(int mwIndex);


    void convertACDT (const ACDT& acdt, ESM::CreatureStats& cStats);

    void convertNpcData (const ActorData& actorData, ESM::NpcStats& npcStats);
}

#endif
