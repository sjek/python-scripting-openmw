#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <bitset>
#include <stack>

#include <components/compiler/extensions.hpp>
#include <components/compiler/extensions0.hpp>
#include <components/compiler/literals.hpp>

//TODO: set/get locals using get/setMemberFloat
//make new opcode for setlocal("object_or_global_script_name",value,global=0) and setglobal
//setlocal needs to know how to set self

//how about new extension "command("string")" which just compiles "string" like console does?
//problem: what interpreter to use? make new one?

//See: lineparser.cpp:

// check if local, global, or member variable
//char type = mLocals.getType (name2);
//if (type!=' ')
//{
//    mType = type;
//    mState = SetLocalVarState;
//    return true;
//}

//type = getContext().getGlobalType (name2);
//if (type!=' ')
//{
//    mType = type;
//    mState = SetGlobalVarState;
//    return true;
//}

//mState = SetPotentialMemberVarState;
//return true;
//}

//if (mState==SetMemberVarState)
//{
//mMemberName = Misc::StringUtils::lowerCase (name);
//std::pair<char, bool> type = getContext().getMemberType (mMemberName, mName);

//if (type.first!=' ')
//{
//    mState = SetMemberVarState2;
//    mType = type.first;
//    mReferenceMember = type.second;
//    return true;
//}


//then later on:
//    else if (mState==SetLocalVarState && keyword==Scanner::K_to)
//    {
//        mExprParser.reset();
//        scanner.scan (mExprParser);

//        std::vector<Interpreter::Type_Code> code;
//        char type = mExprParser.append (code);

//        Generator::assignToLocal (mCode, mLocals.getType (mName),
//            mLocals.getIndex (mName), code, type);

//        mState = EndState;
//        return true;
//    }
//    else if (mState==SetGlobalVarState && keyword==Scanner::K_to)
//    {
//        mExprParser.reset();
//        scanner.scan (mExprParser);

//        std::vector<Interpreter::Type_Code> code;
//        char type = mExprParser.append (code);

//        Generator::assignToGlobal (mCode, mLiterals, mType, mName, code, type);

//        mState = EndState;
//        return true;
//    }
//    else if (mState==SetMemberVarState2 && keyword==Scanner::K_to)
//    {
//        mExprParser.reset();
//        scanner.scan (mExprParser);

//        std::vector<Interpreter::Type_Code> code;
//        char type = mExprParser.append (code);

//        Generator::assignToMember (mCode, mLiterals, mType, mMemberName, mName, code, type,
//            !mReferenceMember);

//        mState = EndState;
//        return true;
//    }

class CodeGenerator
{
        Compiler::Extensions mExtensions;
        std::vector<std::string> mKeywords;
        void keywordParser(std::string keyword);
        void topGenerator();
        void bottomGenerator();
        std::ofstream mHeaderFile;
        std::ofstream mImpFile;
    public:
        CodeGenerator(std::string directory = "")
        {
            mHeaderFile.open (std::string(directory+"openmwbindings.hpp").c_str());
            mImpFile.open (std::string(directory+"openmwbindings.cpp").c_str());
            Compiler::registerExtensions(mExtensions);
            mExtensions.listKeywords(mKeywords);
        }
        void run()
        {
            topGenerator();
            for_each(mKeywords.begin(), mKeywords.end(), bind1st(mem_fun(&CodeGenerator::keywordParser), this) );
            bottomGenerator();
        }
};

void CodeGenerator::topGenerator()
{
    mHeaderFile << "#include <string>\n\n#include <components/interpreter/types.hpp>\n";
    mHeaderFile << "#include <components/interpreter/interpreter.hpp>\n";
    mHeaderFile << "#include <apps/openmw/mwscript/interpretercontext.hpp>\n\n";
    mHeaderFile << "namespace MWScriptExtensions\n{\n";
    mImpFile << "#include \"openmwbindings.hpp\"\n\n";
    mImpFile << "#include <components/compiler/literals.hpp>\n";
    mImpFile << "#include <components/compiler/generator.hpp>\n";
    mImpFile << "#include <components/interpreter/interpreter.hpp>\n";
    mImpFile << "#include <components/compiler/opcodes.hpp>\n";
    mImpFile << "#include <apps/openmw/mwscript/interpretercontext.hpp>\n\n";
    mImpFile << "#include <apps/openmw/mwbase/world.hpp>\n\n";
    mImpFile << "#include <apps/openmw/mwscript/extensions.hpp>\n\n";
    mImpFile << "#include <components/misc/stringops.hpp>\n\n";
    mImpFile << "namespace MWScriptExtensions\n{\n";
    mImpFile << "    Interpreter::Interpreter *interpreter=NULL;\n";
    mImpFile << "    MWScript::InterpreterContext *context=NULL;\n";
    mImpFile << "    Interpreter::Data stackReturn;\n\n";
    mHeaderFile << "    extern Interpreter::Interpreter *interpreter;\n";
    mHeaderFile << "    extern MWScript::InterpreterContext *context;\n";
    mHeaderFile << "    extern Interpreter::Data stackReturn;\n\n";
}
void CodeGenerator::bottomGenerator()
{
    mHeaderFile << "}\n";
    mImpFile << "}\n\n";
}


void CodeGenerator::keywordParser(std::string keyword)
{
    Compiler::ScriptReturn returnType;
    std::string returnDeclare="";
    std::string returnLocal="";
    std::string returnCommand="";
    std::string declaration="";
    std::string arguments="";
    std::string foursp ="    ";
    std::stack <std::string> pushArguments;
    int argcount=0;
    int optionalcount=-1;
    Compiler::ScriptArgs argumentType;
    std::vector<Interpreter::Type_Code> code;
    Compiler::Literals literals;
    int keywordint=mExtensions.searchKeyword(keyword);
    bool explicitReference=true;
    if(mExtensions.isFunction (keywordint, returnType, argumentType, explicitReference))
    {
        mExtensions.generateFunctionCode(keywordint,code,literals,"",0); //code[0] = implicitcode
        if(explicitReference==true) mExtensions.generateFunctionCode(keywordint,code,literals,"explicit",0); //code[2] = explicitcode

        if (returnType=='f')
        {
            mHeaderFile << foursp << "Interpreter::Type_Float";
            mImpFile << foursp << "Interpreter::Type_Float";
            returnCommand = "return stackReturn.mFloat;\n"; // maybe runtime.pop() as well?
            //returnCommand = "return 1;\n";//need to fix!
        }
        else if (returnType=='S')
        {
            //returnDeclare="std::string";
            //returnCommand = "return runtime.getStringLiteral(runtime[0].mInteger)";
            std::cerr << "String returns not supported in keyword  " << keyword;
        }
        else if (returnType=='l')
        {
            mHeaderFile << foursp << "Interpreter::Type_Integer";
            mImpFile << foursp << "Interpreter::Type_Integer";
            returnCommand = "return stackReturn.mInteger;\n";
            //returnCommand = "return 1;\n";//need to fix!
        }
        else
        {
            std::cerr << "error generating " << keyword << " no valid returnType\n";
        }
        mHeaderFile << " " << keyword << "(";
        mImpFile << " " << keyword << "(";
    }
    else if(mExtensions.isInstruction (keywordint, argumentType, explicitReference))
    {
        mExtensions.generateInstructionCode(keywordint,code,literals,"",0);//code[0]=implicit
        if(explicitReference==true) mExtensions.generateInstructionCode(keywordint,code,literals,"explicit",0);//code[2]=explicit
        mHeaderFile << foursp << "void " << keyword << "(";
        mImpFile << foursp << "void " << keyword<<"(";
        returnType='v';
        returnCommand = "return;\n";

    }
    else
    {
        std::cerr << "error generating " << keyword << " not function or instruction\n";
    }

    std::string commas = "";
    std::string optionalInt = "";
    std::string optionalStr = "";
    std::ostringstream convert;
    if(explicitReference) argumentType= 'S'+argumentType; //first argument is a referenceID
    for(const char* c = argumentType.c_str(); *c; ++c)
    {
        if(argcount > 0) commas=", ";
        /// Typedef for script arguments string
        /** Every character reperesents an argument to the command. All arguments are required until a /, after which
            every argument is optional. <BR>
            Eg: fff/f represents 3 required floats followed by one optional float <BR>
            f - Float <BR>
            c - String, case smashed <BR>
            l - Integer <BR>
            s - Short <BR>
            S - String, case preserved <BR>
            x - Optional, ignored string argument
            X - Optional, ignored numeric expression
            z - Optional, ignored string or numeric argument
            j - A piece of junk (either . or a specific keyword)
        **/
        if (*c=='f')
        {
            mHeaderFile << commas << "Interpreter::Type_Float arg" << argcount << optionalInt;
            mImpFile << commas << "Interpreter::Type_Float arg" << argcount;
            convert << "if (arg" << argcount << "!=-123456)\n";
            convert << foursp << foursp << "{\n";
            convert << foursp << foursp << foursp << "Compiler::Generator::pushFloat(code, literals, arg" << argcount <<");\n";
            convert << foursp << foursp << foursp << "argumentsPassed++;\n";
            convert << foursp << foursp << "}\n";
            pushArguments.push(convert.str());
            convert.str("");
            argcount++;
        }
        else if (*c=='s')
        {
            //mHeaderFile << commas << "Interpreter::Type_Short arg" << argcount<<optionalstr;
            //mImpFile << commas << "Interpreter::Type_Short arg" << argcount;
            //argcount++;
            std::cerr << "shorts not supported yet in keyword: " + keyword + "\n";
        }
        else if (*c=='S' || *c=='c')
        {
            mHeaderFile << commas << "std::string arg" << argcount<<optionalStr;
            mImpFile << commas << "std::string arg" << argcount;
            if (*c=='c')
            {
                convert << "if (arg" << argcount << "!=\"OPTIONAL_FLAG\")\n";
                convert << foursp << foursp << "{\n";
                convert << foursp << foursp << foursp << "Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg" << argcount << "));\n";
                convert << foursp << foursp << foursp << "argumentsPassed++;\n";
                convert << foursp << foursp << "}\n";
                pushArguments.push(convert.str());
                convert.str("");
            } else if (*c=='S')
            {
                if(explicitReference && argcount==0) convert << "if (arg0 !=\"self\")\n";
                else convert << foursp << foursp << "if (arg" << argcount << "!=\"OPTIONAL_FLAG\" )\n";
                convert << foursp << foursp << "{\n";
                convert << foursp << foursp << foursp << "Compiler::Generator::pushString(code, literals, arg" << argcount << ");\n";
                convert << foursp << foursp << foursp << "argumentsPassed++;\n";
                convert << foursp << foursp << "}\n";
                pushArguments.push(convert.str());
                convert.str("");
            }
            convert.str("");
            argcount++;
        }
        else if (*c=='j') //junk appears as a first argument but not used
        {
            continue;
        }
        else if (*c=='x' || *c=='X' || *c=='z' ) //these are only in optional arguments, but ignored
        {
            break;
        }
        else if (*c=='l')
        {
            mHeaderFile << commas << "Interpreter::Type_Integer arg" << argcount<<optionalInt;
            mImpFile << commas << "Interpreter::Type_Integer arg" << argcount;
            convert << "if (arg" << argcount << "!=-123456)\n";
            convert << foursp << foursp << "{\n";
            convert << foursp << foursp << foursp << "Compiler::Generator::pushInt(code, literals, arg" << argcount <<");\n";
            convert << foursp << foursp << foursp << "argumentsPassed++;\n";
            convert << foursp << foursp << "}\n";
            pushArguments.push(convert.str());
            convert.str("");
            argcount++;
        }
        else if (*c=='/')
        {
            optionalInt= "=-123456";
            optionalStr= "=\"OPTIONAL_FLAG\"";
            optionalcount=argcount;
        }
        else
        {
            std::cerr << "ERROR IN ARG TYPE for keyword: " << keyword;
        }
    }

    if (optionalcount==-1)
    {
        optionalcount =0;
    }
    else
    {
        optionalcount = argcount-optionalcount;
    }

    mHeaderFile << ");\n";
    mImpFile << ")\n    {\n";
    mImpFile << foursp << foursp << "Interpreter::Type_Code codeword = 0x" << std::hex << code[0] << std::dec <<";//codeword without arguments\n";
    mImpFile << foursp << foursp << "Compiler::Literals literals;\n";
    if(explicitReference)
        mImpFile << foursp << foursp << "if(arg0!=\"self\") codeword = 0x" << std::hex << code[3] << std::dec <<";//codeword without arguments\n";
    mImpFile << foursp << foursp << "std::vector<Interpreter::Type_Code> code;\n";
    mImpFile << foursp << foursp << "uint argCount = " << argcount << ";\n";
    mImpFile << foursp << foursp << "uint optionalArgCount = " << optionalcount << ";\n";
    mImpFile << foursp << foursp << "uint argumentsPassed = 0;\n";
    mImpFile << foursp << foursp << "uint optionalArgumentsPassed = 0;\n";
    for (uint i = pushArguments.size(); i >0; i--)
    {
        mImpFile << foursp << foursp << pushArguments.top();
        pushArguments.pop();
    }
    mImpFile << foursp << foursp << "optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);\n";
    mImpFile << foursp << foursp << "// adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it\n";
    mImpFile << foursp << foursp << "if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);\n";
    mImpFile << foursp << foursp << "code.push_back(codeword);\n";
    if (returnType=='f' || returnType=='l')
        mImpFile << foursp << foursp << "code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code\n";

    mImpFile << foursp << foursp << "//now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()\n";

    mImpFile << foursp << foursp << "std::vector<Interpreter::Type_Code> codeblock;\n";
    mImpFile << foursp << foursp << "codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));\n";
    mImpFile << foursp << foursp << "codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));\n";
    mImpFile << foursp << foursp << "codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));\n";
    mImpFile << foursp << foursp << "codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));\n";
    mImpFile << foursp << foursp << "std::copy (code.begin(), code.end(), std::back_inserter (codeblock));\n";
    mImpFile << foursp << foursp << "literals.append(codeblock);\n";
    mImpFile << foursp << foursp << "for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)\n";
    mImpFile << foursp << foursp << foursp << "std::cout << (std::bitset<32>) *i << \" \\n \";\n";

    mImpFile << foursp << foursp << "interpreter->run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!\n";
    mImpFile << foursp << foursp << "std::cout.flush();\n";
    mImpFile << foursp << foursp << returnCommand;
    mImpFile << foursp << "}\n";
    return;
}

int main(int argc, char**argv)
{
    std::string directory;
    if(argv[1]!=NULL) directory = std::string(argv[1])+"/";
    CodeGenerator codeGen(directory);
    codeGen.run();
    return 0;
}

