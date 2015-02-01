
#include "../world/collectionbase.hpp"
#include "../world/record.hpp"
#include "apps/opencs/model/tools/../doc/messages.hpp"
#include "apps/opencs/model/tools/../world/universalid.hpp"
#include "mandatoryid.hpp"

CSMTools::MandatoryIdStage::MandatoryIdStage (const CSMWorld::CollectionBase& idCollection,
    const CSMWorld::UniversalId& collectionId, const std::vector<std::string>& ids)
: mIdCollection (idCollection), mCollectionId (collectionId), mIds (ids)
{}

int CSMTools::MandatoryIdStage::setup()
{
    return mIds.size();
}

void CSMTools::MandatoryIdStage::perform (int stage, CSMDoc::Messages& messages)
{
    if (mIdCollection.searchId (mIds.at (stage))==-1 ||
        mIdCollection.getRecord (mIds.at (stage)).isDeleted())
        messages.add (mCollectionId, "Missing mandatory record: " + mIds.at (stage));
}
