#ifndef CSM_FILTER_NOTNODE_H
#define CSM_FILTER_NOTNODE_H

#include <map>

#include "unarynode.hpp"

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
    class NotNode : public UnaryNode
    {
        public:

            NotNode (boost::shared_ptr<Node> child);

            virtual bool test (const CSMWorld::IdTableBase& table, int row,
                const std::map<int, int>& columns) const;
            ///< \return Can the specified table row pass through to filter?
            /// \param columns column ID to column index mapping
    };
}

#endif
