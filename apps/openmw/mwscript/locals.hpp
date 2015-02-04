#ifndef GAME_SCRIPT_LOCALS_H
#define GAME_SCRIPT_LOCALS_H

#include <components/interpreter/types.hpp>
#include <string>
#include <vector>

namespace ESM
{
    struct Locals;
    struct Script;
}

namespace MWScript
{
    class Locals
    {
        public:
            std::vector<Interpreter::Type_Short> mShorts;
            std::vector<Interpreter::Type_Integer> mLongs;
            std::vector<Interpreter::Type_Float> mFloats;

            /// Are there any locals?
            bool isEmpty() const;

            void configure (const ESM::Script& script);
            /// @note var needs to be in lowercase
            bool setVarByInt(const std::string& script, const std::string& var, int val);
            int getIntVar (const std::string& script, const std::string& var);
            ///< if var does not exist, returns 0
            /// @note var needs to be in lowercase

            void write (ESM::Locals& locals, const std::string& script) const;

            void read (const ESM::Locals& locals, const std::string& script);
    };
}

#endif

