#ifndef RECORDSTATUSDELEGATE_H
#define RECORDSTATUSDELEGATE_H

#include <QFont>
#include <QTextOption>

#include "../../model/world/record.hpp"
#include "datadisplaydelegate.hpp"
#include "util.hpp"

class QFont;
class QIcon;
class QObject;
namespace CSMDoc {
class Document;
}  // namespace CSMDoc
namespace CSVWorld {
class CommandDelegate;
}  // namespace CSVWorld

namespace CSVWorld
{
    class RecordStatusDelegate : public DataDisplayDelegate
    {
    public:

        explicit RecordStatusDelegate(const ValueList& values,
                                      const IconList& icons,
                                      CSMDoc::Document& document, QObject *parent = 0);
    };

    class RecordStatusDelegateFactory : public DataDisplayDelegateFactory
    {
        public:

            RecordStatusDelegateFactory();

            virtual CommandDelegate *makeDelegate (CSMDoc::Document& document, QObject *parent) const;
            ///< The ownership of the returned CommandDelegate is transferred to the caller.

    };
}
#endif // RECORDSTATUSDELEGATE_HPP

