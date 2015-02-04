#ifndef COMPILER_LINEPARSER_H_INCLUDED
#define COMPILER_LINEPARSER_H_INCLUDED

#include <components/interpreter/types.hpp>
#include <string>
#include <vector>

#include "exprparser.hpp"
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

    /// \brief Line parser, to be used in console scripts and as part of ScriptParser

    class LineParser : public Parser
    {
            enum State
            {
                BeginState,
                SetState, SetLocalVarState, SetGlobalVarState, SetPotentialMemberVarState,
                SetMemberVarState, SetMemberVarState2,
                MessageState, MessageCommaState, MessageButtonState, MessageButtonCommaState,
                EndState, PotentialEndState /* may have a stray string argument */,
                PotentialExplicitState, ExplicitState, MemberState
            };

            Locals& mLocals;
            Literals& mLiterals;
            std::vector<Interpreter::Type_Code>& mCode;
            State mState;
            std::string mName;
            std::string mMemberName;
            bool mReferenceMember;
            int mButtons;
            std::string mExplicit;
            char mType;
            ExprParser mExprParser;
            bool mAllowExpression;

            void parseExpression (Scanner& scanner, const TokenLoc& loc);

        public:

            LineParser (ErrorHandler& errorHandler, const Context& context, Locals& locals,
                Literals& literals, std::vector<Interpreter::Type_Code>& code,
                bool allowExpression = false);
            ///< \param allowExpression Allow lines consisting of a naked expression
            /// (result is send to the messagebox interface)

            virtual bool parseInt (int value, const TokenLoc& loc, Scanner& scanner);
            ///< Handle an int token.
            /// \return fetch another token?

            virtual bool parseFloat (float value, const TokenLoc& loc, Scanner& scanner);
            ///< Handle a float token.
            /// \return fetch another token?

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
