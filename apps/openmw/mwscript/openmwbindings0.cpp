#include "openmwbindings.hpp"
#include "openmwbindings0.hpp"

#include <components/compiler/locals.hpp>

#include "../mwbase/environment.hpp"
#include "../mwbase/scriptmanager.hpp"

#include "../mwworld/class.hpp"
#include "../mwworld/ptr.hpp"

namespace MWScriptExtensions
{
    void set(std::string name, float value)
    {
        //MWWorld::Ptr ptr = MWWorld::Ptr(); use this for console, but no script name
        MWWorld::Ptr ptr = context->getReference(true);
        const std::string script = ptr.getClass().getScript(ptr);
        if(script.empty())
            std::cerr << ptr.getCellRef().getRefId()<<" ("<<ptr.getRefData().getHandle()<<") does not have a script.";

        const MWScript::Locals &locals = ptr.getRefData().getLocals();
        const Compiler::Locals &complocals = MWBase::Environment::get().getScriptManager()->getLocals(script);

        char type = complocals.getType (name);
        if (type!=' ')
        {
            // do what is done:       Generator::assignToLocal (mCode, mLocals.getType (mName),
            //            mLocals.getIndex (mName), code, type);
            //return
            std::cout << "YES I'm a LOCAL";
        }

        type = context->getGlobalType(name);
        if (type!=' ')
        {
            // do what is done: Generator::assignToGlobal (mCode, mLiterals, mType, mName, code, type);
            //return
            std::cout << "YES I'm a GLOBAL";
        }

        std::cout << "YES I'm a MEMBER";

        // do what is done: Generator::assignToMember
    }
}
