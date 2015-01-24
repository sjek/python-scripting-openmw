#include "openmwbindings.hpp"
#include "openmwbindings0.hpp"

#include "interpretercontext.hpp"
#include "globalscripts.hpp"


#include <components/compiler/locals.hpp>

#include "../mwbase/environment.hpp"
#include "../mwbase/scriptmanager.hpp"

#include "../mwworld/class.hpp"
#include "../mwworld/ptr.hpp"
#include "../mwworld/worldimp.hpp"


namespace MWScriptExtensions
{
    void set(std::string name, float value)
    {
        char type;
        MWWorld::Ptr ptr = context->getReference(false); // can be empty, e.g. console or global

        if (!ptr.isEmpty())
        {
            const MWScript::Locals &locals = ptr.getRefData().getLocals();
            const std::string script = ptr.getClass().getScript(ptr);
            const Compiler::Locals &complocals = MWBase::Environment::get().getScriptManager()->getLocals(script);
            //if there is is a script, get locals for script
            type = complocals.getType (name);
            if (type!=' ')
            {
                // do what is done:       Generator::assignToLocal (mCode, mLocals.getType (mName),
                //            mLocals.getIndex (mName), code, type);
                //return
                std::cout << "YES I'm a LOCAL\n";
                std::cout.flush();
                return;
            }
        }

        type = context->getGlobalType(name);
        if (type!=' ')
        {
            // do what is done: Generator::assignToGlobal (mCode, mLiterals, mType, mName, code, type);
            //return
            std::cout << "YES I'm a GLOBAL\n";
            std::cout.flush();
            switch (type)
            {
                case 'f':

                    context->setGlobalFloat(name,value);
                    break;

                case 's':

                    context->setGlobalShort(name,static_cast<int>(value));
                    break;

                case 'l':

                    context->setGlobalLong(name,static_cast<int>(value));
                    break;

                default:

                    assert (0);
            }
            return;
        }

        std::cout << "YES I'm a MEMBER\n";
        std::cout.flush();

        std::string id = name.substr(0,name.find_first_of('.'));
        std::string varname = name.substr(name.find_first_of('.')+1);
        std::cout << "member: " << id << " name: " << varname << "\n";
        std::cout.flush();

        if (!MWBase::Environment::get().getScriptManager()->getGlobalScripts().getLocals(id).isEmpty())
        {
            const MWScript::Locals &locals = MWBase::Environment::get().getScriptManager()->getGlobalScripts().getLocals(id);
        }
        else
        {
            const MWWorld::Ptr ptr =  MWBase::Environment::get().getWorld()->getPtr (id, false);

            id = ptr.getClass().getScript (ptr);

            ptr.getRefData().setLocals (
                *MWBase::Environment::get().getWorld()->getStore().get<ESM::Script>().find (id));

            const MWScript::Locals &locals = ptr.getRefData().getLocals();
        }
    }
    //create a function which takes locals, varname, and type and sets the appopriate
}
