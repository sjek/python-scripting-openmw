#ifndef COMPILER_QUICKFILEPARSER_H_INCLUDED
#define COMPILER_QUICKFILEPARSER_H_INCLUDED

#include <string>

#include "declarationparser.hpp"
#include "parser.hpp"

namespace Compiler {
class Context;
class ErrorHandler;
class Scanner;
struct TokenLoc;
}  // namespace Compiler

namespace Compiler
{
    class Locals;

    /// \brief File parser variant that ignores everything but variable declarations
    class QuickFileParser : public Parser
    {
            DeclarationParser mDeclarationParser;

        public:

            QuickFileParser (ErrorHandler& errorHandler, const Context& context, Locals& locals);

            virtual bool parseName (const std::string& name, const TokenLoc& loc,
                Scanner& scanner);
            ///< Handle a name token.
            /// \return fetch another token?

            virtual bool parseKeyword (int keyword, const TokenLoc& loc, Scanner& scanner);
            ///< Handle a keyword token.
            /// \return fetch another token?

            virtual bool parseSpecial (int code, const TokenLoc& loc, Scanner& scanner);
            ///< Handle a special character token.
            /// \return fetch another token?

            virtual void parseEOF (Scanner& scanner);
            ///< Handle EOF token.
    };
}

#endif

