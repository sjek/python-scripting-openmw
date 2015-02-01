#ifndef OPENMW_MWSOUND_MOVIEAUDIOFACTORY_H
#define OPENMW_MWSOUND_MOVIEAUDIOFACTORY_H

#include <boost/smart_ptr/shared_ptr.hpp>
#include <extern/ogre-ffmpeg-videoplayer/audiofactory.hpp>

namespace Video {
class MovieAudioDecoder;
struct VideoState;
}  // namespace Video

namespace MWSound
{

    class MovieAudioFactory : public Video::MovieAudioFactory
    {
        virtual boost::shared_ptr<Video::MovieAudioDecoder> createDecoder(Video::VideoState* videoState);
    };

}

#endif
