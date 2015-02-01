
#include "../mwbase/environment.hpp"
#include "../mwbase/soundmanager.hpp"
#include "action.hpp"
#include "apps/openmw/mwworld/ptr.hpp"
#include "apps/openmw/mwworld/refdata.hpp"

const MWWorld::Ptr& MWWorld::Action::getTarget() const
{
    return mTarget;
}

MWWorld::Action::Action (bool keepSound, const Ptr& target) : mKeepSound (keepSound), mTarget (target), mSoundOffset(0)
{}

MWWorld::Action::~Action() {}

void MWWorld::Action::execute (const Ptr& actor)
{
    if (!mSoundId.empty())
    {
        if (mKeepSound && actor.getRefData().getHandle()=="player")
            MWBase::Environment::get().getSoundManager()->playSound(mSoundId, 1.0, 1.0,
                    MWBase::SoundManager::Play_TypeSfx, MWBase::SoundManager::Play_Normal,mSoundOffset);
        else
        {
            bool local = mTarget.isEmpty() || !mTarget.isInCell(); // no usable target
        
            MWBase::Environment::get().getSoundManager()->playSound3D(local ? actor : mTarget,
                mSoundId, 1.0, 1.0, MWBase::SoundManager::Play_TypeSfx,
                mKeepSound ? MWBase::SoundManager::Play_NoTrack : MWBase::SoundManager::Play_Normal,
                        mSoundOffset);
        }
    }

    executeImp (actor);
}

void MWWorld::Action::setSound (const std::string& id)
{
    mSoundId = id;
}

void MWWorld::Action::setSoundOffset(float offset)
{
    mSoundOffset=offset;
}
