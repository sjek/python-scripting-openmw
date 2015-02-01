#ifndef CSV_WORLD_TABLESUBVIEW_H
#define CSV_WORLD_TABLESUBVIEW_H

#include <QtCore/qnamespace.h>
#include <qobjectdefs.h>
#include <qstring.h>
#include <qstringlist.h>
#include <string>
#include <vector>

#include "../doc/subview.hpp"
#include "apps/opencs/view/world/../doc/../../model/doc/../world/universalid.hpp"

class QEvent;
class QModelIndex;
class QObject;

namespace CSMWorld
{
    class IdTable;
}

namespace CSMDoc
{
    class Document;
}

namespace CSVFilter
{
    class FilterBox;
}

namespace CSVWorld
{
    class CreatorFactoryBase;
    class Table;
    class TableBottomBox;

    class TableSubView : public CSVDoc::SubView
    {
            Q_OBJECT

            Table *mTable;
            TableBottomBox *mBottom;
            CSVFilter::FilterBox *mFilterBox;

        public:

            TableSubView (const CSMWorld::UniversalId& id, CSMDoc::Document& document,
                const CreatorFactoryBase& creatorFactory, bool sorting);

            virtual void setEditLock (bool locked);

            virtual void updateUserSetting
                                (const QString& name, const QStringList &list);

            virtual void setStatusBar (bool show);

            virtual void useHint (const std::string& hint);

        protected:
            bool eventFilter(QObject* object, QEvent *event);

        signals:
            void cloneRequest(const std::string&,
                              const CSMWorld::UniversalId::Type);

        private slots:

            void editRequest (const CSMWorld::UniversalId& id, const std::string& hint);
            void cloneRequest (const CSMWorld::UniversalId& toClone);
            void createFilterRequest(std::vector< CSMWorld::UniversalId >& types,
                                     Qt::DropAction action);
    };
}

#endif
