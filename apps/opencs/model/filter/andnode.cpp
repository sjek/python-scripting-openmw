
#include "andnode.hpp"
#include "apps/opencs/model/filter/narynode.hpp"
#include "apps/opencs/model/filter/node.hpp"

namespace CSMWorld {
class IdTableBase;
}  // namespace CSMWorld
namespace boost {
template <class Y> class shared_ptr;
}  // namespace boost

CSMFilter::AndNode::AndNode (const std::vector<boost::shared_ptr<Node> >& nodes)
: NAryNode (nodes, "and")
{}

bool CSMFilter::AndNode::test (const CSMWorld::IdTableBase& table, int row,
    const std::map<int, int>& columns) const
{
    int size = getSize();

    for (int i=0; i<size; ++i)
        if (!(*this)[i].test (table, row, columns))
            return false;

    return true;
}
