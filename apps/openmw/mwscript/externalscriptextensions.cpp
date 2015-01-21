
#include "externalscriptextensions.hpp"

#include <Python.h>

#include <components/compiler/extensions.hpp>
#include <components/compiler/opcodes.hpp>

#include <components/interpreter/interpreter.hpp>
#include <components/interpreter/runtime.hpp>
#include <components/interpreter/opcodes.hpp>
#include <components/interpreter/context.hpp>

#include "interpretercontext.hpp"
#include "extensions.hpp"
#include "openmwbindings.hpp"
#include "ref.hpp"

#include <iostream>

namespace MWScript
{
    namespace ExternalScript
    {
        class OpStartExternalScript : public Interpreter::Opcode0
        {
            public:

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    std::string scriptname = runtime.getStringLiteral (runtime[0].mInteger);
                    runtime.pop();

                    if (scriptname.find(".py") != std::string::npos)
                    {
                        MWScript::InterpreterContext pythonContext = static_cast<InterpreterContext&> (runtime.getContext());
                        MWScriptExtensions::context = &pythonContext;
                        Interpreter::Interpreter pythonInterpreter;
                        MWScript::installOpcodes(pythonInterpreter);
                        MWScriptExtensions::interpreter = &pythonInterpreter;
                        Py_Initialize();
                        FILE *file_1 = fopen(scriptname.c_str(),"r");
                        PyRun_SimpleFileEx(file_1,scriptname.c_str(),1);
                        Py_Finalize();
                        MWScriptExtensions::interpreter=NULL;
                        MWScriptExtensions::context = NULL;
                    }
                    else
                    {
                        std::cout << "StartExternalScript: " << scriptname << "is not valid script name";
                    }
                }
        };
        class OpExternalScriptReturn : public Interpreter::Opcode0
        {
            public:

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    MWScriptExtensions::stackReturn = runtime[0];
                }
        };


        void installOpcodes (Interpreter::Interpreter& interpreter)
        {
            interpreter.installSegment5 (Compiler::ExternalScript::opcodeStartExternalScript, new OpStartExternalScript);
            interpreter.installSegment5 (Compiler::ExternalScript::opcodeExternalScriptReturn, new OpExternalScriptReturn);
        }
    }
}

