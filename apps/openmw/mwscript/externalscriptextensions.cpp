
#include "externalscriptextensions.hpp"

#include <Python.h>

#include <components/compiler/extensions.hpp>
#include <components/compiler/opcodes.hpp>

#include <components/interpreter/interpreter.hpp>
#include <components/interpreter/runtime.hpp>
#include <components/interpreter/opcodes.hpp>
#include <components/interpreter/context.hpp>
#include <components/files/configurationmanager.hpp>

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
                        if(!MWScriptExtensions::opcodesInstalled)
                        {
                            MWScript::installOpcodes(MWScriptExtensions::interpreter);
                            Py_Initialize();
                            boost::program_options::variables_map variables;

                            boost::program_options::options_description desc("Allowed options");
                            desc.add_options()
                            ("data", boost::program_options::value<Files::PathContainer>()->default_value(Files::PathContainer(), "data")->multitoken()->composing())
                            ("data-local", boost::program_options::value<std::string>()->default_value(""))
                            ("extensions", boost::program_options::value<std::string>()->default_value(""));

                            boost::program_options::notify(variables);

                            Files::ConfigurationManager cfgManager;
                            cfgManager.readConfiguration(variables, desc);

                            Files::PathContainer dataDirs, dataLocal;
                            if (!variables["data"].empty()) {
                                dataDirs = Files::PathContainer(variables["data"].as<Files::PathContainer>());
                            }

                            std::string local = variables["data-local"].as<std::string>();
                            if (!local.empty()) {
                                dataLocal.push_back(Files::PathContainer::value_type(local));
                            }

                            cfgManager.processPaths (dataDirs);
                            cfgManager.processPaths (dataLocal, true);

                            if (!dataLocal.empty())
                                dataDirs.insert (dataDirs.end(), dataLocal.begin(), dataLocal.end());

                            Files::PathContainer extensionDirs = variables["extensions"].as<Files::PathContainer>();
                            extensionDirs.push_back(dataDirs);
                            //need to find directories and append to sys.path, make new .cfg variable for extensions
                            // "lib/games/openmw" and look in data dirs for other scripts
                            // see "opemw/plugins/mygui_.../plugin.cpp for cfgManager.readConfiguration

                            PyRun_SimpleString("import sys; sys.path.append(\".\"); from openmw import *\n");
                            //PyRun_SimpleString("from openmw import *\n");
                            MWScriptExtensions::opcodesInstalled=true;

                        }
                        //PyThreadState* newPythonInterpreter = Py_NewInterpreter();
                        FILE *file_1 = fopen(scriptname.c_str(),"r");
                        PyRun_SimpleFileEx(file_1,scriptname.c_str(),1);
                        //Py_EndInterpreter(newPythonInterpreter);
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

