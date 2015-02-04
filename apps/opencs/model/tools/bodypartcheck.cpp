#include <string>
#include <utility>

#include "apps/opencs/model/tools/../doc/messages.hpp"
#include "apps/opencs/model/tools/../world/idcollection.hpp"
#include "apps/opencs/model/tools/../world/record.hpp"
#include "apps/opencs/model/tools/../world/resources.hpp"
#include "apps/opencs/model/tools/../world/universalid.hpp"
#include "bodypartcheck.hpp"
#include "components/esm/loadbody.hpp"

namespace ESM {
struct Race;
}  // namespace ESM

CSMTools::BodyPartCheckStage::BodyPartCheckStage(
        const CSMWorld::IdCollection<ESM::BodyPart> &bodyParts,
        const CSMWorld::Resources                   &meshes,
        const CSMWorld::IdCollection<ESM::Race>     &races ) :
    mBodyParts(bodyParts),
    mMeshes(meshes),
    mRaces(races)
{ }

int CSMTools::BodyPartCheckStage::setup()
{
    return mBodyParts.getSize();
}

void CSMTools::BodyPartCheckStage::perform (int stage, CSMDoc::Messages &messages)
{
    const CSMWorld::Record<ESM::BodyPart> &record = mBodyParts.getRecord(stage);

    if ( record.isDeleted() )
        return;

    const ESM::BodyPart &bodyPart = record.get();

    CSMWorld::UniversalId id( CSMWorld::UniversalId::Type_BodyPart, bodyPart.mId );

    // Check BYDT
    if (bodyPart.mData.mPart > 14 )
        messages.push_back(std::make_pair( id, bodyPart.mId + " has out of range part value." ));

    if (bodyPart.mData.mFlags > 3 )
        messages.push_back(std::make_pair( id, bodyPart.mId + " has out of range flags value." ));

    if (bodyPart.mData.mType > 2 )
        messages.push_back(std::make_pair( id, bodyPart.mId + " has out of range type value." ));

    // Check MODL

    if ( bodyPart.mModel.empty() )
        messages.push_back(std::make_pair( id, bodyPart.mId + " has no model." ));
    else if ( mMeshes.searchId( bodyPart.mModel ) == -1 )
        messages.push_back(std::make_pair( id, bodyPart.mId + " has invalid model." ));

    // Check FNAM

    if ( bodyPart.mRace.empty() )
        messages.push_back(std::make_pair( id, bodyPart.mId + " has no race." ));
    else if ( mRaces.searchId( bodyPart.mRace ) == -1 )
        messages.push_back(std::make_pair( id, bodyPart.mId + " has invalid race." ));
}
