
#include "components/compiler/errorhandler.hpp"
#include "nullerrorhandler.hpp"

namespace Compiler {
struct TokenLoc;
}  // namespace Compiler

void Compiler::NullErrorHandler::report (const std::string& message, const TokenLoc& loc, Type type) {}

void Compiler::NullErrorHandler::report (const std::string& message, Type type) {}
