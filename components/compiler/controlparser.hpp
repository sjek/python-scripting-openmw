#ifndef COMPILER_CONTROLPARSER_H_INCLUDED
#define COMPILER_CONTROLPARSER_H_INCLUDED

#include <components/interpreter/types.hpp>
#include <string>
#include <utility>
#include <vector>

#include "exprparser.hpp"
#include "lineparser.hpp"
#include "parser.hpp"

namespace Compiler {
class Context;
class ErrorHandler;
class Scanner;
struct TokenLoc;
}  // namespace Compiler

namespace Compiler
{
    class Literals;
    class Locals;

    // Control structure parser

    class ControlParser : public Parser
    {
            enum State
            {
                StartState,
                IfEndState, IfBodyState,
                IfElseifEndState, IfElseifBodyState,
                IfElseEndState, IfElseBodyState,
                IfEndifState,
                WhileEndState, WhileBodyState,
                WhileEndwhileState,
                IfElseJunkState
            };

            typedef std::vector<Interpreter::Type_Code> Codes;
            typedef std::vector<std::pair<Codes, Codes> > IfCodes;

            Locals& mLocals;
            Literals& mLiterals;
            Codes mCode;
            Codes mCodeBlock;
            IfCodes mIfCode; // condition, body
            LineParser mLineParser;
            ExprParser mExprParser;
            State mState;

            bool parseIfBody (int keyword, const TokenLoc& loc, Scanner& scanner);

            bool parseWhileBody (int keyword, const TokenLoc& loc, Scanner& scanner);

        public:

            ControlParser (ErrorHandler& errorHandler, const Context& context, Locals& locals,
                Literals& literals);

            void appendCode (std::vector<Interpreter::Type_Code>& code) const;
            ///< store generated code in \a code.

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

            void reset();
            ///< Reset parser to clean state.
    };
}

#endif
