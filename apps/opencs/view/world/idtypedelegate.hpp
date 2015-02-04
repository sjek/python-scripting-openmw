#ifndef IDTYPEDELEGATE_HPP
#define IDTYPEDELEGATE_HPP

#include "../../model/world/universalid.hpp"
#include "datadisplaydelegate.hpp"
#include "enumdelegate.hpp"
#include "util.hpp"

class QObject;
namespace CSMDoc {
class Document;
}  // namespace CSMDoc
namespace CSVWorld {
class CommandDelegate;
}  // namespace CSVWorld

namespace CSVWorld
{
    class IdTypeDelegate : public DataDisplayDelegate
    {
        public:
            IdTypeDelegate (const ValueList &mValues, const IconList &icons, CSMDoc::Document& document, QObject *parent);
    };

    class IdTypeDelegateFactory : public DataDisplayDelegateFactory
    {
        public:

            IdTypeDelegateFactory();

            virtual CommandDelegate *makeDelegate (CSMDoc::Document& document, QObject *parent) const;
            ///< The ownership of the returned CommandDelegate is transferred to the caller.
    };
}

#endif // REFIDTYPEDELEGATE_HPP
