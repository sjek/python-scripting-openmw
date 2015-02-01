
#include <components/esm/loadregn.hpp>
#include <string>
#include <utility>

#include "../world/universalid.hpp"
#include "apps/opencs/model/tools/../doc/messages.hpp"
#include "apps/opencs/model/tools/../world/idcollection.hpp"
#include "apps/opencs/model/tools/../world/record.hpp"
#include "regioncheck.hpp"

CSMTools::RegionCheckStage::RegionCheckStage (const CSMWorld::IdCollection<ESM::Region>& regions)
: mRegions (regions)
{}

int CSMTools::RegionCheckStage::setup()
{
    return mRegions.getSize();
}

void CSMTools::RegionCheckStage::perform (int stage, CSMDoc::Messages& messages)
{
    const CSMWorld::Record<ESM::Region>& record = mRegions.getRecord (stage);

    if (record.isDeleted())
        return;

    const ESM::Region& region = record.get();

    CSMWorld::UniversalId id (CSMWorld::UniversalId::Type_Region, region.mId);

    // test for empty name
    if (region.mName.empty())
        messages.push_back (std::make_pair (id, region.mId + " has an empty name"));

    /// \todo test that the ID in mSleeplist exists

    /// \todo check data members that can't be edited in the table view
}
