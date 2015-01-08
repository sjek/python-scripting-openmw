#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

#include <components/compiler/extensions.hpp>
#include <components/compiler/extensions0.hpp>

class CodeGenerator
{
    Compiler::Extensions mExtensions;
    std::vector<std::string> mKeywords;
    void test2(std::string keyword);
public:
    CodeGenerator()
    {
        Compiler::registerExtensions(mExtensions);
        mExtensions.listKeywords(mKeywords);
        std::cout << "#include <string>\n\n#include <components/interpreter/types.hpp>\n\n";
        for_each(mKeywords.begin(), mKeywords.end(), bind1st(mem_fun(&CodeGenerator::test2), this) );
    }
};


void CodeGenerator::test2(std::string keyword)
{
    Compiler::ScriptReturn returnType;
    std::string return_declare="";
    std::string return_command="";
    std::string declaration="";
    std::string arguments="";
    int argcount=0;
    Compiler::ScriptArgs argumentType;
    int keywordint=mExtensions.searchKeyword(keyword);
    bool explicitReference=0;
    if(mExtensions.isFunction (keywordint, returnType, argumentType, explicitReference))
    {
        if (returnType=='f')
        {
            return_declare="Interpreter::Type_Float";
            return_command = "return runtime[0].mFloat"; // maybe runtime.pop() as well?
        }
        else if (returnType=='S')
        {
            return_declare="std::string";
            return_command = "return runtime.getStringLiteral(runtime[0].mInteger)";
        }
        else if (returnType=='l')
        {
            return_declare="Interpreter::Type_Integer";
            return_command = "return runtime[0].mInteger";
        }
        else
        {
            std::cout << "error generating " << keyword << " no valid returnType\n";
            //return_declare="void ";
            //return_command = "return";
         }
        declaration= return_declare + " " + keyword;
    }
    else if(mExtensions.isInstruction (keywordint, argumentType, explicitReference))
    {
        declaration= "void " + keyword;
    }
    else
    {
            std::cout << "error generating " << keyword << " not function or instruction\n";
    }

    std::string commas = "";
    std::string optional = "";
    std::string optionalstr = "";
    std::ostringstream convert;
    for(const char* c = argumentType.c_str(); *c; ++c)
    {
        convert.str("");
        convert << argcount;
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
            arguments += commas + "Interpreter::Type_Float arg" + convert.str()+optional;
        }
        else if (*c=='s')
        {
            arguments += commas + "Interpreter::Type_Short arg" + convert.str()+optionalstr;
        }
        else if (*c=='S' || *c=='c')
        {
            arguments += commas + "std::string arg" + convert.str()+optionalstr;
        }
        else if (*c=='x' || *c=='X' || *c=='z' || *c=='j')
        {
            continue;
        }
        else if (*c=='l')
        {
            arguments += commas + "Interpreter::Type_Integer arg" + convert.str()+optional;
        }
        else if (*c=='/')
        {
            optional= "=-123456";
            optionalstr= "=\"OPTIONAL_FLAG\"";
            argcount--;
        }
        else
        {
            arguments= commas + "ERROR IN ARG TYPE";
         }
        argcount++;
    }

    declaration += "("+arguments+");\n";
    std::cout << declaration << "\n";
    return;
}

int main(int argc, char**argv)
{
    CodeGenerator codeGen;
    return 0;
}

