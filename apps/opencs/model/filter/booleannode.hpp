#ifndef CSM_FILTER_BOOLEANNODE_H
#define CSM_FILTER_BOOLEANNODE_H

#include <map>
#include <string>

#include "leafnode.hpp"

namespace CSMWorld {
class IdTableBase;
}  // namespace CSMWorld

namespace CSMFilter
{
    class BooleanNode : public LeafNode
    {
            bool mTrue;

        public:

            BooleanNode (bool true_);

            virtual bool test (const CSMWorld::IdTableBase& table, int row,
                const std::map<int, int>& columns) const;
            ///< \return Can the specified table row pass through to filter?
            /// \param columns column ID to column index mapping

            virtual std::string toString (bool numericColumns) const;
            ///< Return a string that represents this node.
            ///
            /// \param numericColumns Use numeric IDs instead of string to represent columns.

    };
}

#endif
