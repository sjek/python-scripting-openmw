
#include <string>
#include <utility>

#include "../world/universalid.hpp"
#include "apps/opencs/model/tools/../doc/messages.hpp"
#include "apps/opencs/model/tools/../world/idcollection.hpp"
#include "apps/opencs/model/tools/../world/record.hpp"
#include "components/esm/loadsoun.hpp"
#include "soundcheck.hpp"

CSMTools::SoundCheckStage::SoundCheckStage (const CSMWorld::IdCollection<ESM::Sound>& sounds)
: mSounds (sounds)
{}

int CSMTools::SoundCheckStage::setup()
{
    return mSounds.getSize();
}

void CSMTools::SoundCheckStage::perform (int stage, CSMDoc::Messages& messages)
{
    const CSMWorld::Record<ESM::Sound>& record = mSounds.getRecord (stage);

    if (record.isDeleted())
        return;

    const ESM::Sound& sound = record.get();

    CSMWorld::UniversalId id (CSMWorld::UniversalId::Type_Sound, sound.mId);

    if (sound.mData.mMinRange>sound.mData.mMaxRange)
        messages.push_back (std::make_pair (id, "Maximum range larger than minimum range"));

    /// \todo check, if the sound file exists
}
