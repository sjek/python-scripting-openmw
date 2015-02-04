#ifndef CSV_TOOLS_REPORTTABLE_H
#define CSV_TOOLS_REPORTTABLE_H

#include <qobjectdefs.h>
#include <qstring.h>
#include <qstringlist.h>
#include <string>
#include <vector>

#include "../world/dragrecordtable.hpp"
#include "apps/opencs/view/tools/../../model/tools/../world/universalid.hpp"

class QAction;
class QContextMenuEvent;
class QMouseEvent;
class QWidget;
namespace CSMDoc {
class Document;
}  // namespace CSMDoc

namespace CSMTools
{
    class ReportModel;
}

namespace CSVWorld
{
    class CommandDelegate;
}

namespace CSVTools
{
    class ReportTable : public CSVWorld::DragRecordTable
    {
            Q_OBJECT

            CSMTools::ReportModel *mModel;
            CSVWorld::CommandDelegate *mIdTypeDelegate;
            QAction *mShowAction;
            QAction *mRemoveAction;

        private:

            void contextMenuEvent (QContextMenuEvent *event);

            void mouseMoveEvent (QMouseEvent *event);

            virtual void mouseDoubleClickEvent (QMouseEvent *event);

        public:

            ReportTable (CSMDoc::Document& document, const CSMWorld::UniversalId& id,
                QWidget *parent = 0);

            virtual std::vector<CSMWorld::UniversalId> getDraggedRecords() const;

            void updateUserSetting (const QString& name, const QStringList& list);

        private slots:

            void showSelection();

            void removeSelection();

        signals:

            void editRequest (const CSMWorld::UniversalId& id, const std::string& hint);
    };
}

#endif
