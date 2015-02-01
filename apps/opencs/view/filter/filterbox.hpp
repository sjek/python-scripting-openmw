#ifndef CSV_FILTER_FILTERBOX_H
#define CSV_FILTER_FILTERBOX_H

#include <QtCore/qnamespace.h>
#include <qobjectdefs.h>
#include <qwidget.h>
#include <QWidget>
#include <string>
#include <utility>
#include <vector>

#include "../../model/filter/node.hpp"
#include "../../model/world/universalid.hpp"

class QDragEnterEvent;
class QDragMoveEvent;
class QDropEvent;
namespace CSMFilter {
class Node;
}  // namespace CSMFilter
namespace CSMWorld {
class UniversalId;
}  // namespace CSMWorld
namespace boost {
template <class Y> class shared_ptr;
}  // namespace boost

namespace CSMWorld
{
    class Data;
}

namespace CSVFilter
{
    class RecordFilterBox;

    class FilterBox : public QWidget
    {
            Q_OBJECT

            RecordFilterBox *mRecordFilterBox;

        public:
            FilterBox (CSMWorld::Data& data, QWidget *parent = 0);

            void setRecordFilter (const std::string& filter);

            void createFilterRequest(std::vector<std::pair<std::string, std::vector<std::string> > >& filterSource,
                                     Qt::DropAction action);


        private:
            void dragEnterEvent (QDragEnterEvent* event);

            void dropEvent (QDropEvent* event);

            void dragMoveEvent(QDragMoveEvent *event);

        signals:
            void recordFilterChanged (boost::shared_ptr<CSMFilter::Node> filter);
            void recordDropped (std::vector<CSMWorld::UniversalId>& types, Qt::DropAction action);
    };

}

#endif

