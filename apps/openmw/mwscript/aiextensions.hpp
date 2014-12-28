#ifndef GAME_SCRIPT_AIEXTENSIONS_H
#define GAME_SCRIPT_AIEXTENSIONS_H

#include <string>

namespace Compiler
{
    class Extensions;
}

namespace Interpreter
{
    class Interpreter;
}

namespace MWScript
{
    /// \brief AI-related script functionality
    namespace Ai
    {
        void installOpcodes (Interpreter::Interpreter& interpreter);
        void AiActivate (const std::string & actorID, const std::string & objectID);
    }
}

#endif
