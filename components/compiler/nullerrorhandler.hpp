
#ifndef COMPILER_NULLERRORHANDLER_H_INCLUDED
#define COMPILER_NULLERRORHANDLER_H_INCLUDED

#include <string>

#include "errorhandler.hpp"

namespace Compiler {
struct TokenLoc;
}  // namespace Compiler

namespace Compiler
{
    /// \brief Error handler implementation: Ignore all error messages

    class NullErrorHandler : public ErrorHandler
    {
            virtual void report (const std::string& message, const TokenLoc& loc, Type type);
            ///< Report error to the user.

            virtual void report (const std::string& message, Type type);
            ///< Report a file related error
    };
}

#endif
