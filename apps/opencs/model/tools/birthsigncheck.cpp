
#include <components/esm/loadbsgn.hpp>
#include <string>
#include <utility>

#include "../world/universalid.hpp"
#include "apps/opencs/model/tools/../doc/messages.hpp"
#include "apps/opencs/model/tools/../world/idcollection.hpp"
#include "apps/opencs/model/tools/../world/record.hpp"
#include "birthsigncheck.hpp"

CSMTools::BirthsignCheckStage::BirthsignCheckStage (const CSMWorld::IdCollection<ESM::BirthSign>& birthsigns)
: mBirthsigns (birthsigns)
{}

int CSMTools::BirthsignCheckStage::setup()
{
    return mBirthsigns.getSize();
}

void CSMTools::BirthsignCheckStage::perform (int stage, CSMDoc::Messages& messages)
{
    const CSMWorld::Record<ESM::BirthSign>& record = mBirthsigns.getRecord (stage);

    if (record.isDeleted())
        return;

    const ESM::BirthSign& birthsign = record.get();

    CSMWorld::UniversalId id (CSMWorld::UniversalId::Type_Birthsign, birthsign.mId);

    // test for empty name, description and texture
    if (birthsign.mName.empty())
        messages.push_back (std::make_pair (id, birthsign.mId + " has an empty name"));

    if (birthsign.mDescription.empty())
        messages.push_back (std::make_pair (id, birthsign.mId + " has an empty description"));

    if (birthsign.mTexture.empty())
        messages.push_back (std::make_pair (id, birthsign.mId + " is missing a texture"));

    /// \todo test if the texture exists

    /// \todo check data members that can't be edited in the table view
}
