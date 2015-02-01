#ifndef CSV_TOOLS_REPORTSUBVIEW_H
#define CSV_TOOLS_REPORTSUBVIEW_H

#include <qobjectdefs.h>
#include <qstring.h>
#include <qstringlist.h>

#include "../doc/subview.hpp"
#include "apps/opencs/view/tools/../doc/../../model/doc/../world/universalid.hpp"

class QModelIndex;
class QTableView;

namespace CSMDoc
{
    class Document;
}

namespace CSVTools
{
    class ReportTable;

    class ReportSubView : public CSVDoc::SubView
    {
            Q_OBJECT

            ReportTable *mTable;

        public:

            ReportSubView (const CSMWorld::UniversalId& id, CSMDoc::Document& document);

            virtual void setEditLock (bool locked);

            virtual void updateUserSetting (const QString &, const QStringList &);
    };
}

#endif
