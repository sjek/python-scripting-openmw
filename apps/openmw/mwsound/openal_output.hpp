#ifndef GAME_SOUND_OPENAL_OUTPUT_H
#define GAME_SOUND_OPENAL_OUTPUT_H

#include <stdint.h>
#include <deque>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "al.h"
#include "alc.h"
#include "apps/openmw/mwsound/../mwbase/soundmanager.hpp"
#include "apps/openmw/mwsound/soundmanagerimp.hpp"
#include "sound_output.hpp"

namespace Ogre {
class Vector3;
}  // namespace Ogre

namespace MWSound
{
    class Sound;
    class SoundManager;

    struct CachedSound
    {
        ALuint mALBuffer;
        std::vector<float> mLoudnessVector;
    };

    class OpenAL_Output : public Sound_Output
    {
        ALCdevice *mDevice;
        ALCcontext *mContext;

        typedef std::deque<ALuint> IDDq;
        IDDq mFreeSources;
        IDDq mUnusedBuffers;

        typedef std::map<std::string,CachedSound> NameMap;
        NameMap mBufferCache;

        typedef std::map<ALuint,ALuint> IDRefMap;
        IDRefMap mBufferRefs;

        uint64_t mBufferCacheMemSize;

        typedef std::vector<Sound*> SoundVec;
        SoundVec mActiveSounds;

        const CachedSound& getBuffer(const std::string &fname);
        void bufferFinished(ALuint buffer);

        Environment mLastEnvironment;

        virtual std::vector<std::string> enumerate();
        virtual void init(const std::string &devname="");
        virtual void deinit();

        /// @param offset Value from [0,1] meaning from which fraction the sound the playback starts.
        virtual MWBase::SoundPtr playSound(const std::string &fname, float vol, float basevol, float pitch, int flags, float offset);
        /// @param offset Value from [0,1] meaning from which fraction the sound the playback starts.
        virtual MWBase::SoundPtr playSound3D(const std::string &fname, const Ogre::Vector3 &pos,
                                             float vol, float basevol, float pitch, float min, float max, int flags, float offset, bool extractLoudness=false);
        virtual MWBase::SoundPtr streamSound(DecoderPtr decoder, float volume, float pitch, int flags);

        virtual void updateListener(const Ogre::Vector3 &pos, const Ogre::Vector3 &atdir, const Ogre::Vector3 &updir, Environment env);

        virtual void pauseSounds(int types);
        virtual void resumeSounds(int types);

        OpenAL_Output& operator=(const OpenAL_Output &rhs);
        OpenAL_Output(const OpenAL_Output &rhs);

        OpenAL_Output(SoundManager &mgr);
        virtual ~OpenAL_Output();

        class StreamThread;

        std::auto_ptr<StreamThread> mStreamThread;

        friend class OpenAL_Sound;
        friend class OpenAL_Sound3D;
        friend class OpenAL_SoundStream;
        friend class SoundManager;
    };
#ifndef DEFAULT_OUTPUT
#define DEFAULT_OUTPUT(x) ::MWSound::OpenAL_Output((x))
#endif
}

#endif
