#ifndef CSM_FILTER_ORNODE_H
#define CSM_FILTER_ORNODE_H

#include <map>
#include <vector>

#include "narynode.hpp"

namespace CSMFilter {
class Node;
}  // namespace CSMFilter
namespace CSMWorld {
class IdTableBase;
}  // namespace CSMWorld
namespace boost {
template <class Y> class shared_ptr;
}  // namespace boost

namespace CSMFilter
{
    class OrNode : public NAryNode
    {
        public:

            OrNode (const std::vector<boost::shared_ptr<Node> >& nodes);

            virtual bool test (const CSMWorld::IdTableBase& table, int row,
                const std::map<int, int>& columns) const;
            ///< \return Can the specified table row pass through to filter?
            /// \param columns column ID to column index mapping
    };
}

#endif
