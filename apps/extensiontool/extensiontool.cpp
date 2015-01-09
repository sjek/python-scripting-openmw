#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include <components/compiler/extensions.hpp>
#include <components/compiler/extensions0.hpp>

class CodeGenerator
{
    Compiler::Extensions mExtensions;
    std::vector<std::string> mKeywords;
    void test2(std::string keyword);
    std::ofstream mHeaderfile;
public:
    CodeGenerator()
    {
        mHeaderfile.open ("openmw_bindings.hpp");
        Compiler::registerExtensions(mExtensions);
        mExtensions.listKeywords(mKeywords);
        mHeaderfile << "#include <string>\n\n#include <components/interpreter/types.hpp>\n\n";
        for_each(mKeywords.begin(), mKeywords.end(), bind1st(mem_fun(&CodeGenerator::test2), this) );
    }
    ~CodeGenerator()
    {
        mHeaderfile.close ();
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
            std::cerr << "error generating " << keyword << " not function or instruction\n";
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
            argcount++;
        }
        else if (*c=='s')
        {
            arguments += commas + "Interpreter::Type_Short arg" + convert.str()+optionalstr;
            argcount++;
        }
        else if (*c=='S' || *c=='c')
        {
            arguments += commas + "std::string arg" + convert.str()+optionalstr;
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
            arguments += commas + "Interpreter::Type_Integer arg" + convert.str()+optional;
            argcount++;
        }
        else if (*c=='/')
        {
            optional= "=-123456";
            optionalstr= "=\"OPTIONAL_FLAG\"";

        }
        else
        {
            std::cerr << "ERROR IN ARG TYPE for keyword: " << keyword;
        }
    }

    declaration += "("+arguments+");\n";
    mHeaderfile << declaration << "\n";
    return;
}

int main(int argc, char**argv)
{
    CodeGenerator codeGen;
    return 0;
}

