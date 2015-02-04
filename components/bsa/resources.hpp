#ifndef BSA_BSA_RESOURCES_H
#define BSA_BSA_RESOURCES_H

#include <string>
#include <vector>

#include "../files/collections.hpp"

namespace Files {
class Collections;
}  // namespace Files

namespace Bsa
{
    void registerResources (const Files::Collections& collections,
        const std::vector<std::string>& archives, bool useLooseFiles, bool fsStrict);
    ///< Register resources directories and archives as OGRE resources groups
}

#endif
