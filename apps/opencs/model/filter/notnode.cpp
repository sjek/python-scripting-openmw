
#include <boost/smart_ptr/shared_ptr.hpp>

#include "apps/opencs/model/filter/node.hpp"
#include "apps/opencs/model/filter/unarynode.hpp"
#include "notnode.hpp"

namespace CSMWorld {
class IdTableBase;
}  // namespace CSMWorld

CSMFilter::NotNode::NotNode (boost::shared_ptr<Node> child) : UnaryNode (child, "not") {}

bool CSMFilter::NotNode::test (const CSMWorld::IdTableBase& table, int row,
    const std::map<int, int>& columns) const
{
    return !getChild().test (table, row, columns);
}
