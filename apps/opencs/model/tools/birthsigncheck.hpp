#ifndef CSM_TOOLS_BIRTHSIGNCHECK_H
#define CSM_TOOLS_BIRTHSIGNCHECK_H

#include <components/esm/loadbsgn.hpp>

#include "../doc/stage.hpp"
#include "../world/idcollection.hpp"

namespace CSMDoc {
class Messages;
}  // namespace CSMDoc
namespace ESM {
struct BirthSign;
}  // namespace ESM

namespace CSMTools
{
    /// \brief VerifyStage: make sure that birthsign records are internally consistent
    class BirthsignCheckStage : public CSMDoc::Stage
    {
            const CSMWorld::IdCollection<ESM::BirthSign>& mBirthsigns;

        public:

            BirthsignCheckStage (const CSMWorld::IdCollection<ESM::BirthSign>& birthsigns);

            virtual int setup();
            ///< \return number of steps

            virtual void perform (int stage, CSMDoc::Messages& messages);
            ///< Messages resulting from this tage will be appended to \a messages.
    };
}

#endif
