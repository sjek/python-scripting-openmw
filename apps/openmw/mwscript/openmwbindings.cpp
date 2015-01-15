#include "openmwbindings.hpp"

#include <components/compiler/literals.hpp>
#include <components/compiler/generator.hpp>
#include <components/interpreter/interpreter.hpp>
#include <apps/openmw/mwscript/interpretercontext.hpp>

#include <apps/openmw/mwbase/world.hpp>

#include <apps/openmw/mwscript/extensions.hpp>

#include <components/misc/stringops.hpp>

namespace MWScriptExtensions
{
    Interpreter::Interpreter interpreter;//define these as extern here and declare in the startexternalscript opcode and install opcodes
    MWScript::InterpreterContext context(NULL,MWWorld::Ptr());//define these as extern here and declare in the startexternalscript opcode and install opcodes

    void activate()
    {
        Interpreter::Type_Code codeword = 0xca000075;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void additem(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000076;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void addsoulgem(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001f3;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void addspell(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000147;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void addtolevcreature(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xca0002fb;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void addtolevitem(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xca0002fd;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void addtopic(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00013a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void aiactivate(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xc2001e00;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void aiescort(std::string arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3, Interpreter::Type_Float arg4, Interpreter::Type_Integer arg5)
    {
        Interpreter::Type_Code codeword = 0xc2000200;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 6;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg5!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg5);
            argumentsPassed++;
        }
        if (arg4!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void aiescortcell(std::string arg0, std::string arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3, Interpreter::Type_Float arg4, Interpreter::Type_Float arg5, Interpreter::Type_Integer arg6)
    {
        Interpreter::Type_Code codeword = 0xc2002000;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 7;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg6!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg6);
            argumentsPassed++;
        }
        if (arg5!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg5);
            argumentsPassed++;
        }
        if (arg4!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void aifollow(std::string arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3, Interpreter::Type_Float arg4, Interpreter::Type_Integer arg5, Interpreter::Type_Integer arg6, Interpreter::Type_Integer arg7, Interpreter::Type_Integer arg8, Interpreter::Type_Integer arg9, Interpreter::Type_Integer arg10, Interpreter::Type_Integer arg11, Interpreter::Type_Integer arg12)
    {
        Interpreter::Type_Code codeword = 0xc2002200;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 13;
        uint optionalArgCount = 8;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg12!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg12);
            argumentsPassed++;
        }
        if (arg11!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg11);
            argumentsPassed++;
        }
        if (arg10!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg10);
            argumentsPassed++;
        }
        if (arg9!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg9);
            argumentsPassed++;
        }
        if (arg8!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg8);
            argumentsPassed++;
        }
        if (arg7!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg7);
            argumentsPassed++;
        }
        if (arg6!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg6);
            argumentsPassed++;
        }
        if (arg5!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg5);
            argumentsPassed++;
        }
        if (arg4!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void aifollowcell(std::string arg0, std::string arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3, Interpreter::Type_Float arg4, Interpreter::Type_Float arg5, Interpreter::Type_Integer arg6)
    {
        Interpreter::Type_Code codeword = 0xc2002400;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 7;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg6!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg6);
            argumentsPassed++;
        }
        if (arg5!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg5);
            argumentsPassed++;
        }
        if (arg4!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void aitravel(Interpreter::Type_Float arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2, Interpreter::Type_Integer arg3)
    {
        Interpreter::Type_Code codeword = 0xc2000000;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 4;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg3!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void aiwander(Interpreter::Type_Float arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2, Interpreter::Type_Integer arg3, Interpreter::Type_Integer arg4, Interpreter::Type_Integer arg5, Interpreter::Type_Integer arg6, Interpreter::Type_Integer arg7, Interpreter::Type_Integer arg8, Interpreter::Type_Integer arg9, Interpreter::Type_Integer arg10, Interpreter::Type_Integer arg11, Interpreter::Type_Integer arg12)
    {
        Interpreter::Type_Code codeword = 0xc2001000;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 13;
        uint optionalArgCount = 10;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg12!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg12);
            argumentsPassed++;
        }
        if (arg11!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg11);
            argumentsPassed++;
        }
        if (arg10!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg10);
            argumentsPassed++;
        }
        if (arg9!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg9);
            argumentsPassed++;
        }
        if (arg8!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg8);
            argumentsPassed++;
        }
        if (arg7!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg7);
            argumentsPassed++;
        }
        if (arg6!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg6);
            argumentsPassed++;
        }
        if (arg5!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg5);
            argumentsPassed++;
        }
        if (arg4!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void bc(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000247;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void becomewerewolf()
    {
        Interpreter::Type_Code codeword = 0xca000217;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void betacomment(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000247;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void cast(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000227;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer cellchanged()
    {
        Interpreter::Type_Code codeword = 0xca000000;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    void centeroncell(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000026;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void centeronexterior(Interpreter::Type_Integer arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000226;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void changeweather(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000140;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void choice(std::string arg0, Interpreter::Type_Integer arg1, std::string arg2, Interpreter::Type_Integer arg3, std::string arg4, Interpreter::Type_Integer arg5, std::string arg6, Interpreter::Type_Integer arg7, std::string arg8, Interpreter::Type_Integer arg9, std::string arg10, Interpreter::Type_Integer arg11, std::string arg12, Interpreter::Type_Integer arg13, std::string arg14, Interpreter::Type_Integer arg15, std::string arg16, Interpreter::Type_Integer arg17, std::string arg18, Interpreter::Type_Integer arg19, std::string arg20, Interpreter::Type_Integer arg21, std::string arg22, Interpreter::Type_Integer arg23, std::string arg24, Interpreter::Type_Integer arg25, std::string arg26, Interpreter::Type_Integer arg27, std::string arg28, Interpreter::Type_Integer arg29, std::string arg30, Interpreter::Type_Integer arg31)
    {
        Interpreter::Type_Code codeword = 0xc2000a00;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 32;
        uint optionalArgCount = 32;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg31!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg31);
            argumentsPassed++;
        }
        if (arg30!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg30);
            argumentsPassed++;
        }
        if (arg29!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg29);
            argumentsPassed++;
        }
        if (arg28!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg28);
            argumentsPassed++;
        }
        if (arg27!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg27);
            argumentsPassed++;
        }
        if (arg26!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg26);
            argumentsPassed++;
        }
        if (arg25!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg25);
            argumentsPassed++;
        }
        if (arg24!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg24);
            argumentsPassed++;
        }
        if (arg23!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg23);
            argumentsPassed++;
        }
        if (arg22!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg22);
            argumentsPassed++;
        }
        if (arg21!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg21);
            argumentsPassed++;
        }
        if (arg20!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg20);
            argumentsPassed++;
        }
        if (arg19!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg19);
            argumentsPassed++;
        }
        if (arg18!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg18);
            argumentsPassed++;
        }
        if (arg17!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg17);
            argumentsPassed++;
        }
        if (arg16!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg16);
            argumentsPassed++;
        }
        if (arg15!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg15);
            argumentsPassed++;
        }
        if (arg14!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg14);
            argumentsPassed++;
        }
        if (arg13!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg13);
            argumentsPassed++;
        }
        if (arg12!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg12);
            argumentsPassed++;
        }
        if (arg11!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg11);
            argumentsPassed++;
        }
        if (arg10!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg10);
            argumentsPassed++;
        }
        if (arg9!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg9);
            argumentsPassed++;
        }
        if (arg8!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg8);
            argumentsPassed++;
        }
        if (arg7!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg7);
            argumentsPassed++;
        }
        if (arg6!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg6);
            argumentsPassed++;
        }
        if (arg5!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg5);
            argumentsPassed++;
        }
        if (arg4!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void clearforcejump()
    {
        Interpreter::Type_Code codeword = 0xca000258;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void clearforcemovejump()
    {
        Interpreter::Type_Code codeword = 0xca00025c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void clearforcerun()
    {
        Interpreter::Type_Code codeword = 0xca000154;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void clearforcesneak()
    {
        Interpreter::Type_Code codeword = 0xca000158;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void clearinfoactor()
    {
        Interpreter::Type_Code codeword = 0xca000245;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void coc(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000026;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void coe(Interpreter::Type_Integer arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000226;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void disablelevitation()
    {
        Interpreter::Type_Code codeword = 0xca000220;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void disableplayercontrols()
    {
        Interpreter::Type_Code codeword = 0xca000085;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void disableplayerfighting()
    {
        Interpreter::Type_Code codeword = 0xca000086;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void disableplayerjumping()
    {
        Interpreter::Type_Code codeword = 0xca000087;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void disableplayerlooking()
    {
        Interpreter::Type_Code codeword = 0xca000088;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void disableplayermagic()
    {
        Interpreter::Type_Code codeword = 0xca000089;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void disableplayerviewswitch()
    {
        Interpreter::Type_Code codeword = 0xca00008a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void disableteleporting()
    {
        Interpreter::Type_Code codeword = 0xca000215;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void disablevanitymode()
    {
        Interpreter::Type_Code codeword = 0xca00008b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void dontsaveobject()
    {
        Interpreter::Type_Code codeword = 0xca000153;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void drop(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001f8;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void dropsoulgem(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001fa;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enablebirthmenu()
    {
        Interpreter::Type_Code codeword = 0xca00000e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enableclassmenu()
    {
        Interpreter::Type_Code codeword = 0xca00000f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enableinventorymenu()
    {
        Interpreter::Type_Code codeword = 0xca000013;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enablelevelupmenu()
    {
        Interpreter::Type_Code codeword = 0xca000017;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enablelevitation()
    {
        Interpreter::Type_Code codeword = 0xca000221;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enablemagicmenu()
    {
        Interpreter::Type_Code codeword = 0xca000014;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enablemapmenu()
    {
        Interpreter::Type_Code codeword = 0xca000015;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enablenamemenu()
    {
        Interpreter::Type_Code codeword = 0xca000010;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enableplayercontrols()
    {
        Interpreter::Type_Code codeword = 0xca00007e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enableplayerfighting()
    {
        Interpreter::Type_Code codeword = 0xca00007f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enableplayerjumping()
    {
        Interpreter::Type_Code codeword = 0xca000080;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enableplayerlooking()
    {
        Interpreter::Type_Code codeword = 0xca000081;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enableplayermagic()
    {
        Interpreter::Type_Code codeword = 0xca000082;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enableplayerviewswitch()
    {
        Interpreter::Type_Code codeword = 0xca000083;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enableracemenu()
    {
        Interpreter::Type_Code codeword = 0xca000011;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enablerest()
    {
        Interpreter::Type_Code codeword = 0xca000017;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enablestatreviewmenu()
    {
        Interpreter::Type_Code codeword = 0xca000012;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enablestatsmenu()
    {
        Interpreter::Type_Code codeword = 0xca000016;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enableteleporting()
    {
        Interpreter::Type_Code codeword = 0xca000216;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void enablevanitymode()
    {
        Interpreter::Type_Code codeword = 0xca000084;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void equip(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001b3;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void explodespell(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000229;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void face(Interpreter::Type_Integer arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00024c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void fadein(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca00013c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void fadeout(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca00013d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void fadeto(Interpreter::Type_Float arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca00013e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void fall()
    {
        Interpreter::Type_Code codeword = 0xca00020a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void fillmap()
    {
        Interpreter::Type_Code codeword = 0xca0001a1;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void forcegreeting()
    {
        Interpreter::Type_Code codeword = 0xca00014f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void forcejump()
    {
        Interpreter::Type_Code codeword = 0xca00025a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void forcemovejump()
    {
        Interpreter::Type_Code codeword = 0xca00025e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void forcerun()
    {
        Interpreter::Type_Code codeword = 0xca000156;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void forcesneak()
    {
        Interpreter::Type_Code codeword = 0xca00015a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer getacrobatics()
    {
        Interpreter::Type_Code codeword = 0xca0000a2;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getagility()
    {
        Interpreter::Type_Code codeword = 0xca00002a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getaipackagedone()
    {
        Interpreter::Type_Code codeword = 0xca00007c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getalarm()
    {
        Interpreter::Type_Code codeword = 0xca0001c5;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getalchemy()
    {
        Interpreter::Type_Code codeword = 0xca00009e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getalteration()
    {
        Interpreter::Type_Code codeword = 0xca000099;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float getangle(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00016a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getarmorbonus()
    {
        Interpreter::Type_Code codeword = 0xca000274;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getarmorer()
    {
        Interpreter::Type_Code codeword = 0xca00008f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getarmortype(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001d1;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getathletics()
    {
        Interpreter::Type_Code codeword = 0xca000096;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getattackbonus()
    {
        Interpreter::Type_Code codeword = 0xca00027a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getattacked()
    {
        Interpreter::Type_Code codeword = 0xca0001d3;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getaxe()
    {
        Interpreter::Type_Code codeword = 0xca000094;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getblightdisease()
    {
        Interpreter::Type_Code codeword = 0xca0001aa;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getblindness()
    {
        Interpreter::Type_Code codeword = 0xca000277;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getblock()
    {
        Interpreter::Type_Code codeword = 0xca00008e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getbluntweapon()
    {
        Interpreter::Type_Code codeword = 0xca000092;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getbuttonpressed()
    {
        Interpreter::Type_Code codeword = 0xca000137;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getcastpenalty()
    {
        Interpreter::Type_Code codeword = 0xca000275;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getchameleon()
    {
        Interpreter::Type_Code codeword = 0xca00026f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getcollidingactor()
    {
        Interpreter::Type_Code codeword = 0xca000252;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getcollidingpc()
    {
        Interpreter::Type_Code codeword = 0xca000250;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getcommondisease()
    {
        Interpreter::Type_Code codeword = 0xca0001a8;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getconjuration()
    {
        Interpreter::Type_Code codeword = 0xca00009b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getcurrentaipackage()
    {
        Interpreter::Type_Code codeword = 0xca0001ef;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float getcurrenttime()
    {
        Interpreter::Type_Code codeword = 0xca0001dd;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getcurrentweather()
    {
        Interpreter::Type_Code codeword = 0xca00013f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getdeadcount(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001a3;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getdefendbonus()
    {
        Interpreter::Type_Code codeword = 0xca00027b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getdestruction()
    {
        Interpreter::Type_Code codeword = 0xca000098;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getdetected(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001f1;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getdisposition()
    {
        Interpreter::Type_Code codeword = 0xca0001a6;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer geteffect(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001cf;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getenchant()
    {
        Interpreter::Type_Code codeword = 0xca000097;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getendurance()
    {
        Interpreter::Type_Code codeword = 0xca00002c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getfactionreaction(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000243;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float getfatigue()
    {
        Interpreter::Type_Code codeword = 0xca000059;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float getfatiguegetratio()
    {
        Interpreter::Type_Code codeword = 0xca000071;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getfight()
    {
        Interpreter::Type_Code codeword = 0xca0001c1;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getflee()
    {
        Interpreter::Type_Code codeword = 0xca0001c3;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getflying()
    {
        Interpreter::Type_Code codeword = 0xca000273;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getforcejump()
    {
        Interpreter::Type_Code codeword = 0xca000260;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getforcemovejump()
    {
        Interpreter::Type_Code codeword = 0xca000262;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getforcerun()
    {
        Interpreter::Type_Code codeword = 0xca0001cb;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getforcesneak()
    {
        Interpreter::Type_Code codeword = 0xca0001cc;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer gethandtohand()
    {
        Interpreter::Type_Code codeword = 0xca0000a8;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float gethealth()
    {
        Interpreter::Type_Code codeword = 0xca000057;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float gethealthgetratio()
    {
        Interpreter::Type_Code codeword = 0xca00006f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getheavyarmor()
    {
        Interpreter::Type_Code codeword = 0xca000091;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer gethello()
    {
        Interpreter::Type_Code codeword = 0xca0001bf;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getillusion()
    {
        Interpreter::Type_Code codeword = 0xca00009a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getintelligence()
    {
        Interpreter::Type_Code codeword = 0xca000028;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getinterior()
    {
        Interpreter::Type_Code codeword = 0xca000131;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getinvisible()
    {
        Interpreter::Type_Code codeword = 0xca000279;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getitemcount(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000078;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getjournalindex(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000135;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getlevel()
    {
        Interpreter::Type_Code codeword = 0xca00018c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getlightarmor()
    {
        Interpreter::Type_Code codeword = 0xca0000a3;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getlineofsight(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000222;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getlocked()
    {
        Interpreter::Type_Code codeword = 0xca0001c7;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getlongblade()
    {
        Interpreter::Type_Code codeword = 0xca000093;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getlos(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000222;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getluck()
    {
        Interpreter::Type_Code codeword = 0xca00002e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float getmagicka()
    {
        Interpreter::Type_Code codeword = 0xca000058;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float getmagickagetratio()
    {
        Interpreter::Type_Code codeword = 0xca000070;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getmarksman()
    {
        Interpreter::Type_Code codeword = 0xca0000a5;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getmasserphase()
    {
        Interpreter::Type_Code codeword = 0xca000024;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getmediumarmor()
    {
        Interpreter::Type_Code codeword = 0xca000090;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getmercantile()
    {
        Interpreter::Type_Code codeword = 0xca0000a6;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getmysticism()
    {
        Interpreter::Type_Code codeword = 0xca00009c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getparalysis()
    {
        Interpreter::Type_Code codeword = 0xca000278;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getpccell(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000136;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float getpccrimelevel()
    {
        Interpreter::Type_Code codeword = 0xca0001ec;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getpcfacrep(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xc2001200;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getpcinjail()
    {
        Interpreter::Type_Code codeword = 0xca00023e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getpcjumping()
    {
        Interpreter::Type_Code codeword = 0xca000233;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getpcrank(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xc2000e00;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getpcrunning()
    {
        Interpreter::Type_Code codeword = 0xca0001c9;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getpcsleep()
    {
        Interpreter::Type_Code codeword = 0xca00019f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getpcsneaking()
    {
        Interpreter::Type_Code codeword = 0xca0001ca;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getpctraveling()
    {
        Interpreter::Type_Code codeword = 0xca00023f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getpersonality()
    {
        Interpreter::Type_Code codeword = 0xca00002d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getplayercontrolsdisabled()
    {
        Interpreter::Type_Code codeword = 0xca000175;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getplayerfightingdisabled()
    {
        Interpreter::Type_Code codeword = 0xca000176;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getplayerjumpingdisabled()
    {
        Interpreter::Type_Code codeword = 0xca000177;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getplayerlookingdisabled()
    {
        Interpreter::Type_Code codeword = 0xca000178;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getplayermagicdisabled()
    {
        Interpreter::Type_Code codeword = 0xca000179;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getplayerviewswitchdisabled()
    {
        Interpreter::Type_Code codeword = 0xca00017a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float getpos(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000190;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getrace(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001d9;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getreputation()
    {
        Interpreter::Type_Code codeword = 0xca0001b1;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getresistblight()
    {
        Interpreter::Type_Code codeword = 0xca000269;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getresistcorprus()
    {
        Interpreter::Type_Code codeword = 0xca00026a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getresistdisease()
    {
        Interpreter::Type_Code codeword = 0xca000268;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getresistfire()
    {
        Interpreter::Type_Code codeword = 0xca000265;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getresistfrost()
    {
        Interpreter::Type_Code codeword = 0xca000266;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getresistmagicka()
    {
        Interpreter::Type_Code codeword = 0xca000264;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getresistnormalweapons()
    {
        Interpreter::Type_Code codeword = 0xca00026d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getresistparalysis()
    {
        Interpreter::Type_Code codeword = 0xca00026c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getresistpoison()
    {
        Interpreter::Type_Code codeword = 0xca00026b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getresistshock()
    {
        Interpreter::Type_Code codeword = 0xca000267;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getrestoration()
    {
        Interpreter::Type_Code codeword = 0xca00009d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float getscale()
    {
        Interpreter::Type_Code codeword = 0xca000168;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getsecundaphase()
    {
        Interpreter::Type_Code codeword = 0xca000025;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getsecurity()
    {
        Interpreter::Type_Code codeword = 0xca0000a0;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getshortblade()
    {
        Interpreter::Type_Code codeword = 0xca0000a4;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getsilence()
    {
        Interpreter::Type_Code codeword = 0xca000276;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getsneak()
    {
        Interpreter::Type_Code codeword = 0xca0000a1;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getsoundplaying(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00000b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getspear()
    {
        Interpreter::Type_Code codeword = 0xca000095;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getspeechcraft()
    {
        Interpreter::Type_Code codeword = 0xca0000a7;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getspeed()
    {
        Interpreter::Type_Code codeword = 0xca00002b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getspell(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00014b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getspelleffects(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001db;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getspellreadied()
    {
        Interpreter::Type_Code codeword = 0xca000231;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float getsquareroot(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001e7;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getstandingactor()
    {
        Interpreter::Type_Code codeword = 0xca00020e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getstandingpc()
    {
        Interpreter::Type_Code codeword = 0xca00020c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float getstartingangle(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000210;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float getstartingpos(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000194;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getstat(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00024e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getstrength()
    {
        Interpreter::Type_Code codeword = 0xca000027;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getsuperjump()
    {
        Interpreter::Type_Code codeword = 0xca000272;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getswimspeed()
    {
        Interpreter::Type_Code codeword = 0xca000271;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer gettarget(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000238;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getunarmored()
    {
        Interpreter::Type_Code codeword = 0xca00009f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getvanitymodedisabled()
    {
        Interpreter::Type_Code codeword = 0xca00017b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getwaterbreathing()
    {
        Interpreter::Type_Code codeword = 0xca00026e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float getwaterlevel()
    {
        Interpreter::Type_Code codeword = 0xca000141;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getwaterwalking()
    {
        Interpreter::Type_Code codeword = 0xca000270;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getweapondrawn()
    {
        Interpreter::Type_Code codeword = 0xca0001d7;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getweapontype()
    {
        Interpreter::Type_Code codeword = 0xca0001e0;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getwerewolfkills()
    {
        Interpreter::Type_Code codeword = 0xca0001e2;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer getwillpower()
    {
        Interpreter::Type_Code codeword = 0xca000029;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Float getwindspeed()
    {
        Interpreter::Type_Code codeword = 0xca000212;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    void goodbye()
    {
        Interpreter::Type_Code codeword = 0xca000152;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void gotojail()
    {
        Interpreter::Type_Code codeword = 0xca000235;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer hasitemequipped(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001d5;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer hassoulgem(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001de;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer hitattemptonme(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002f9;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer hitonme(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000213;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    void hurtcollidingactor(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca000256;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void hurtstandingactor(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca000254;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer iswerewolf()
    {
        Interpreter::Type_Code codeword = 0xca0001fd;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    void journal(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000133;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void lock(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xc2000400;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void loopgroup(std::string arg0, Interpreter::Type_Integer arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xc2000800;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void lowerrank()
    {
        Interpreter::Type_Code codeword = 0xca0001ea;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void menutest(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xc2002c00;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modacrobatics(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00010e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modagility(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00004a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modalarm(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001bd;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modalchemy(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00010a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modalteration(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000105;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modarmorbonus(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002d4;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modarmorer(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000fb;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modathletics(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000102;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modattackbonus(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002da;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modaxe(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000100;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modblindness(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002d7;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modblock(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000fa;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modbluntweapon(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000fe;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modcastpenalty(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002d5;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modchameleon(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002cf;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modconjuration(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000107;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modcurrentfatigue(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca00006b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modcurrenthealth(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca000069;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modcurrentmagicka(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca00006a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void moddefendbonus(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002db;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void moddestruction(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000104;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void moddisposition(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00014d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modenchant(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000103;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modendurance(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00004c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modfactionreaction(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xca000242;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modfatigue(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca000065;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modfight(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001b9;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modflee(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001bb;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modflying(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002d3;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modhandtohand(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000114;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modhealth(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca000063;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modheavyarmor(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000fd;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modhello(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001b7;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modillusion(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000106;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modintelligence(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000048;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modinvisible(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002d9;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modlightarmor(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00010f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modlongblade(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000ff;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modluck(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00004e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modmagicka(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca000064;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modmarksman(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000111;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modmediumarmor(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000fc;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modmercantile(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000112;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modmysticism(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000108;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modparalysis(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002d8;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modpccrimelevel(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001ee;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modpcfacrep(Interpreter::Type_Integer arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xc2001600;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modpersonality(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00004d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modregion(std::string arg0, Interpreter::Type_Integer arg1, Interpreter::Type_Integer arg2, Interpreter::Type_Integer arg3, Interpreter::Type_Integer arg4, Interpreter::Type_Integer arg5, Interpreter::Type_Integer arg6, Interpreter::Type_Integer arg7, Interpreter::Type_Integer arg8, Interpreter::Type_Integer arg9, Interpreter::Type_Integer arg10)
    {
        Interpreter::Type_Code codeword = 0xc2002600;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 11;
        uint optionalArgCount = 10;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg10!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg10);
            argumentsPassed++;
        }
        if (arg9!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg9);
            argumentsPassed++;
        }
        if (arg8!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg8);
            argumentsPassed++;
        }
        if (arg7!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg7);
            argumentsPassed++;
        }
        if (arg6!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg6);
            argumentsPassed++;
        }
        if (arg5!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg5);
            argumentsPassed++;
        }
        if (arg4!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modreputation(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001ae;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modresistblight(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002c9;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modresistcorprus(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002ca;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modresistdisease(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002c8;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modresistfire(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002c5;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modresistfrost(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002c6;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modresistmagicka(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002c4;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modresistnormalweapons(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002cd;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modresistparalysis(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002cc;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modresistpoison(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002cb;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modresistshock(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002c7;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modrestoration(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000109;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modscale(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001e3;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modsecurity(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00010c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modshortblade(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000110;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modsilence(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002d6;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modsneak(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00010d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modspear(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000101;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modspeechcraft(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000113;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modspeed(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00004b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modstrength(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000047;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modsuperjump(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002d2;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modswimspeed(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002d1;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modunarmored(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00010b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modwaterbreathing(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002ce;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modwaterlevel(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca000143;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modwaterwalking(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002d0;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void modwillpower(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000049;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void move(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca000206;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void moveworld(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca000208;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer onactivate()
    {
        Interpreter::Type_Code codeword = 0xca00000d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer ondeath()
    {
        Interpreter::Type_Code codeword = 0xca0001fc;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer onknockout()
    {
        Interpreter::Type_Code codeword = 0xca000240;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    Interpreter::Type_Integer onmurder()
    {
        Interpreter::Type_Code codeword = 0xca000249;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    void payfine()
    {
        Interpreter::Type_Code codeword = 0xca000236;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void payfinethief()
    {
        Interpreter::Type_Code codeword = 0xca000237;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void pcclearexpelled(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xc2001c00;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void pcexpell(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xc2001a00;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer pcexpelled(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xc2001800;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    void pcforce1stperson()
    {
        Interpreter::Type_Code codeword = 0xca0002f6;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void pcforce3rdperson()
    {
        Interpreter::Type_Code codeword = 0xca0002f7;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer pcget3rdperson()
    {
        Interpreter::Type_Code codeword = 0xca0002f8;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    void pcjoinfaction(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xc2000d00;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void pclowerrank(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xc2000c00;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void pcraiserank(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xc2000b00;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void placeatme(std::string arg0, Interpreter::Type_Integer arg1, Interpreter::Type_Float arg2, Interpreter::Type_Integer arg3)
    {
        Interpreter::Type_Code codeword = 0xca00019d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 4;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg3!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void placeatpc(std::string arg0, Interpreter::Type_Integer arg1, Interpreter::Type_Float arg2, Interpreter::Type_Integer arg3)
    {
        Interpreter::Type_Code codeword = 0xca00019c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 4;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg3!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void placeitem(std::string arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3, Interpreter::Type_Float arg4)
    {
        Interpreter::Type_Code codeword = 0xca00019b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 5;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg4!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void placeitemcell(std::string arg0, std::string arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3, Interpreter::Type_Float arg4, Interpreter::Type_Float arg5)
    {
        Interpreter::Type_Code codeword = 0xca00019a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 6;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg5!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg5);
            argumentsPassed++;
        }
        if (arg4!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void playbink(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001f7;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void playgroup(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xc2000600;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void playloopsound3d(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000008;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void playloopsound3dvp(std::string arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2)
    {
        Interpreter::Type_Code codeword = 0xca000009;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void playsound(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000004;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void playsound3d(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000006;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void playsound3dvp(std::string arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2)
    {
        Interpreter::Type_Code codeword = 0xca000007;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void playsoundvp(std::string arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2)
    {
        Interpreter::Type_Code codeword = 0xca000005;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void position(Interpreter::Type_Float arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3)
    {
        Interpreter::Type_Code codeword = 0xca000196;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 4;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void positioncell(Interpreter::Type_Float arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3, std::string arg4)
    {
        Interpreter::Type_Code codeword = 0xca000198;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 5;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg4!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg4));
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void ra()
    {
        Interpreter::Type_Code codeword = 0xca0002f4;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void raiserank()
    {
        Interpreter::Type_Code codeword = 0xca0001e8;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void removeeffects(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00022d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void removefromlevcreature(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xca0002fc;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void removefromlevitem(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xca0002fe;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void removeitem(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00007a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void removesoulgem(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xc2002700;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void removespell(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000149;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void removespelleffects(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00022b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void resetactors()
    {
        Interpreter::Type_Code codeword = 0xca0002f4;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void resurrect()
    {
        Interpreter::Type_Code codeword = 0xca00022f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void rotate(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001ff;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void rotateworld(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca000201;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer samefaction()
    {
        Interpreter::Type_Code codeword = 0xca0001b5;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    void say(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000001;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer saydone()
    {
        Interpreter::Type_Code codeword = 0xca000002;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
    void setacrobatics(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000d8;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setagility(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00003a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setalarm(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000162;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setalchemy(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000d4;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setalteration(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000cf;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setangle(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca000166;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setarmorbonus(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002a4;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setarmorer(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000c5;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setathletics(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000cc;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setatstart()
    {
        Interpreter::Type_Code codeword = 0xca000203;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setattackbonus(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002aa;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setaxe(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000ca;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setblindness(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002a7;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setblock(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000c4;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setbluntweapon(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000c8;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setcastpenalty(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002a5;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setchameleon(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00029f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setconjuration(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000d1;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setdefendbonus(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002ab;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setdelete(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001e5;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setdestruction(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000ce;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setdisposition(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001a4;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setenchant(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000cd;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setendurance(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00003c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setfatigue(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca00005f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setfight(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00015e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setflee(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000160;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setflying(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002a3;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void sethandtohand(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000de;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void sethealth(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca00005d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setheavyarmor(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000c7;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void sethello(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00015c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setillusion(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000d0;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setintelligence(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000038;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setinvisible(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002a9;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setjournalindex(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000134;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setlevel(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00018e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setlightarmor(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000d9;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setlongblade(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000c9;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setluck(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00003e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setmagicka(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca00005e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setmarksman(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000db;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setmediumarmor(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000c6;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setmercantile(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000dc;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setmysticism(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000d2;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setparalysis(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002a8;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setpccrimelevel(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001ed;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setpcfacrep(Interpreter::Type_Integer arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xc2001400;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setpersonality(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00003d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setpos(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca000192;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setreputation(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001ad;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setresistblight(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000299;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setresistcorprus(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00029a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setresistdisease(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000298;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setresistfire(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000295;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setresistfrost(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000296;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setresistmagicka(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000294;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setresistnormalweapons(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00029d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setresistparalysis(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00029c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setresistpoison(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00029b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setresistshock(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000297;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setrestoration(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000d3;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setscale(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca000164;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setsecurity(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000d6;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setshortblade(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000da;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setsilence(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002a6;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setsneak(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000d7;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setspear(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000cb;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setspeechcraft(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000dd;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setspeed(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00003b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setstrength(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000037;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setsuperjump(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002a2;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setswimspeed(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002a1;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setunarmored(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000d5;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setwaterbreathing(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00029e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setwaterlevel(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca000142;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setwaterwalking(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca0002a0;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setwerewolfacrobatics()
    {
        Interpreter::Type_Code codeword = 0xca00021b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void setwillpower(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca000039;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void showmap(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001a0;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void showrestmenu()
    {
        Interpreter::Type_Code codeword = 0xca000018;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void showvars()
    {
        Interpreter::Type_Code codeword = 0xca00021d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void skipanim()
    {
        Interpreter::Type_Code codeword = 0xca000138;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void startcombat(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00023a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void stopcombat()
    {
        Interpreter::Type_Code codeword = 0xca00023c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void stopsound(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00000a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void streammusic(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000003;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void sv()
    {
        Interpreter::Type_Code codeword = 0xca00021d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void tai()
    {
        Interpreter::Type_Code codeword = 0xca000224;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void tcb()
    {
        Interpreter::Type_Code codeword = 0xca0001ac;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void tcg()
    {
        Interpreter::Type_Code codeword = 0xca000132;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void tcl()
    {
        Interpreter::Type_Code codeword = 0xca000130;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void tfh()
    {
        Interpreter::Type_Code codeword = 0xca000151;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void tfow()
    {
        Interpreter::Type_Code codeword = 0xca000145;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void tgm()
    {
        Interpreter::Type_Code codeword = 0xca00021f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void tm()
    {
        Interpreter::Type_Code codeword = 0xca00024b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void toggleai()
    {
        Interpreter::Type_Code codeword = 0xca000224;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void togglecollision()
    {
        Interpreter::Type_Code codeword = 0xca000130;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void togglecollisionboxes()
    {
        Interpreter::Type_Code codeword = 0xca0001ac;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void togglecollisiongrid()
    {
        Interpreter::Type_Code codeword = 0xca000132;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void togglefogofwar()
    {
        Interpreter::Type_Code codeword = 0xca000145;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void togglefullhelp()
    {
        Interpreter::Type_Code codeword = 0xca000151;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void togglegodmode()
    {
        Interpreter::Type_Code codeword = 0xca00021f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void togglemenus()
    {
        Interpreter::Type_Code codeword = 0xca00024b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void togglepathgrid()
    {
        Interpreter::Type_Code codeword = 0xca000146;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void togglesky()
    {
        Interpreter::Type_Code codeword = 0xca000021;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void togglevanitymode()
    {
        Interpreter::Type_Code codeword = 0xca000174;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void togglewater()
    {
        Interpreter::Type_Code codeword = 0xca000144;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void togglewireframe()
    {
        Interpreter::Type_Code codeword = 0xca00013b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void toggleworld()
    {
        Interpreter::Type_Code codeword = 0xca0002f5;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void tpg()
    {
        Interpreter::Type_Code codeword = 0xca000146;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void ts()
    {
        Interpreter::Type_Code codeword = 0xca000021;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void turnmoonred()
    {
        Interpreter::Type_Code codeword = 0xca000023;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void turnmoonwhite()
    {
        Interpreter::Type_Code codeword = 0xca000022;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void tvm()
    {
        Interpreter::Type_Code codeword = 0xca000174;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void tw()
    {
        Interpreter::Type_Code codeword = 0xca0002f5;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void twa()
    {
        Interpreter::Type_Code codeword = 0xca000144;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void twf()
    {
        Interpreter::Type_Code codeword = 0xca00013b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void undowerewolf()
    {
        Interpreter::Type_Code codeword = 0xca000219;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void unlock()
    {
        Interpreter::Type_Code codeword = 0xca00008c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    void wakeuppc()
    {
        Interpreter::Type_Code codeword = 0xca0001a2;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer xbox()
    {
        Interpreter::Type_Code codeword = 0xca00000c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        interpreter.run(&codeblock[0], codeblock.size(), context);//todo - get the runtime stack!
        return 1;
    }
}

