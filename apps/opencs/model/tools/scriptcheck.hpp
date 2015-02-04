#ifndef CSM_TOOLS_SCRIPTCHECK_H
#define CSM_TOOLS_SCRIPTCHECK_H

#include <components/compiler/errorhandler.hpp>
#include <components/compiler/extensions.hpp>
#include <string>

#include "../doc/stage.hpp"
#include "../world/scriptcontext.hpp"

namespace CSMDoc {
class Messages;
}  // namespace CSMDoc
namespace Compiler {
struct TokenLoc;
}  // namespace Compiler

namespace CSMDoc
{
    class Document;
}

namespace CSMTools
{
    /// \brief VerifyStage: make sure that scripts compile
    class ScriptCheckStage : public CSMDoc::Stage, private Compiler::ErrorHandler
    {
            const CSMDoc::Document& mDocument;
            Compiler::Extensions mExtensions;
            CSMWorld::ScriptContext mContext;
            std::string mId;
            std::string mFile;
            CSMDoc::Messages *mMessages;

            virtual void report (const std::string& message, const Compiler::TokenLoc& loc, Type type);
            ///< Report error to the user.

            virtual void report (const std::string& message, Type type);
            ///< Report a file related error

        public:

            ScriptCheckStage (const CSMDoc::Document& document);

            virtual int setup();
            ///< \return number of steps

            virtual void perform (int stage, CSMDoc::Messages& messages);
            ///< Messages resulting from this tage will be appended to \a messages.
    };
}

#endif
