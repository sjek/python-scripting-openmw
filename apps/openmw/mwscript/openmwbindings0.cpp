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

        if (!ptr.isEmpty()) //if the context is for an object/actor
        {
            const std::string script = ptr.getClass().getScript(ptr);
            const Compiler::Locals &complocals = MWBase::Environment::get().getScriptManager()->getLocals(script);
            //if there is is a script, get locals for script
            type = complocals.getType (name);
            if (type!=' ') //it is a variable in this local script
            {
                // do what is done:       Generator::assignToLocal (mCode, mLocals.getType (mName),
                //            mLocals.getIndex (mName), code, type);
                //return
                std::cout << "YES I'm a LOCAL\n";
                std::cout.flush();
                int index = complocals.getIndex(name);

                switch(type)
                {
                    case 's':
                        context->setLocalShort(index, static_cast<int>(value)); break;

                    case 'l':
                        context->setLocalLong(index, static_cast<int>(value)); break;

                    case 'f':
                        context->setLocalFloat(index, value); break;
                }
                return;
            }
        }

        type = context->getGlobalType(name); //is it a global variable?
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

        //all that's left is it a variable in another local or global script
        std::cout << "YES I'm a MEMBER\n";
        std::cout.flush();

        std::string id = name.substr(0,name.find_first_of('.'));
        std::string varname = name.substr(name.find_first_of('.')+1);
        std::cout << "member: " << id << " name: " << varname << "\n";
        std::cout.flush();

        bool globalscript = !MWBase::Environment::get().getScriptManager()->getGlobalScripts().getLocals(id).isEmpty();

        type = MWBase::Environment::get().getScriptManager()->getLocals (id).getType(varname);

        switch (type)
        {
            case 'f':

                context->setMemberFloat(id,varname,value,globalscript);
                return;

            case 's':

                context->setMemberShort(id,varname,static_cast<int>(value),globalscript);
                return;

            case 'l':

                context->setMemberLong(id,varname,static_cast<int>(value),globalscript);
                return;

            default:

                assert (0);
        }
        assert(0);
    }
}
