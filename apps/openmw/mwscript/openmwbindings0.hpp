#ifndef OPENMWBINDINGS0_HPP
#define OPENMWBINDINGS0_HPP

#include <string>

namespace MWScriptExtensions
{
    void omwset(std::string name, float value);
    float omwget(std::string name);
    void omwcall(std::string command);
}
#endif // OPENMWBINDINGS0_HPP
