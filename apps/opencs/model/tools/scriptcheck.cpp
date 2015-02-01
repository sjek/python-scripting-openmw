
#include <components/compiler/extensions0.hpp>
#include <components/compiler/fileparser.hpp>
#include <components/compiler/scanner.hpp>
#include <components/compiler/tokenloc.hpp>
#include <exception>
#include <ostream>
#include <utility>

#include "../doc/document.hpp"
#include "../world/data.hpp"
#include "apps/opencs/model/tools/../doc/../world/idcollection.hpp"
#include "apps/opencs/model/tools/../doc/../world/record.hpp"
#include "apps/opencs/model/tools/../doc/../world/universalid.hpp"
#include "apps/opencs/model/tools/../doc/messages.hpp"
#include "apps/opencs/model/tools/../world/scriptcontext.hpp"
#include "components/compiler/errorhandler.hpp"
#include "components/esm/loadscpt.hpp"
#include "scriptcheck.hpp"

namespace Compiler {
class SourceException;
}  // namespace Compiler

void CSMTools::ScriptCheckStage::report (const std::string& message, const Compiler::TokenLoc& loc,
    Type type)
{
    std::ostringstream stream;

    CSMWorld::UniversalId id (CSMWorld::UniversalId::Type_Script, mId);

    if (type==ErrorMessage)
        stream << "error ";
    else
        stream << "warning ";

    stream
        << "script " << mFile
        << ", line " << loc.mLine << ", column " << loc.mColumn
        << " (" << loc.mLiteral << "): " << message;

    std::ostringstream hintStream;

    hintStream << "l:" << loc.mLine << " " << loc.mColumn;

    mMessages->add (id, stream.str(), hintStream.str());
}

void CSMTools::ScriptCheckStage::report (const std::string& message, Type type)
{
    CSMWorld::UniversalId id (CSMWorld::UniversalId::Type_Script, mId);

    mMessages->push_back (std::make_pair (id,
        (type==ErrorMessage ? "error: " : "warning: ") + message));
}

CSMTools::ScriptCheckStage::ScriptCheckStage (const CSMDoc::Document& document)
: mDocument (document), mContext (document.getData()), mMessages (0)
{
    /// \todo add an option to configure warning mode
    setWarningsMode (0);

    Compiler::registerExtensions (mExtensions);
    mContext.setExtensions (&mExtensions);
}

int CSMTools::ScriptCheckStage::setup()
{
    mContext.clear();
    mMessages = 0;
    mId.clear();

    return mDocument.getData().getScripts().getSize();
}

void CSMTools::ScriptCheckStage::perform (int stage, CSMDoc::Messages& messages)
{
    mId = mDocument.getData().getScripts().getId (stage);

    if (mDocument.isBlacklisted (
        CSMWorld::UniversalId (CSMWorld::UniversalId::Type_Script, mId)))
        return;

    mMessages = &messages;

    try
    {
        const CSMWorld::Data& data = mDocument.getData();

        mFile = data.getScripts().getRecord (stage).get().mId;
        std::istringstream input (data.getScripts().getRecord (stage).get().mScriptText);

        Compiler::Scanner scanner (*this, input, mContext.getExtensions());

        Compiler::FileParser parser (*this, mContext);

        scanner.scan (parser);
    }
    catch (const Compiler::SourceException&)
    {
        // error has already been reported via error handler
    }
    catch (const std::exception& error)
    {
        CSMWorld::UniversalId id (CSMWorld::UniversalId::Type_Script, mId);

        messages.push_back (std::make_pair (id,
            std::string ("Critical compile error: ") + error.what()));
    }

    mMessages = 0;
}
