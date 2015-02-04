#ifndef CSM_TOOLS_SOUNDCHECK_H
#define CSM_TOOLS_SOUNDCHECK_H

#include <components/esm/loadsoun.hpp>

#include "../doc/stage.hpp"
#include "../world/idcollection.hpp"

namespace CSMDoc {
class Messages;
}  // namespace CSMDoc
namespace ESM {
struct Sound;
}  // namespace ESM

namespace CSMTools
{
    /// \brief VerifyStage: make sure that sound records are internally consistent
    class SoundCheckStage : public CSMDoc::Stage
    {
            const CSMWorld::IdCollection<ESM::Sound>& mSounds;

        public:

            SoundCheckStage (const CSMWorld::IdCollection<ESM::Sound>& sounds);

            virtual int setup();
            ///< \return number of steps

            virtual void perform (int stage, CSMDoc::Messages& messages);
            ///< Messages resulting from this tage will be appended to \a messages.
    };
}

#endif
