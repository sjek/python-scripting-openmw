#ifndef CSM_TOOLS_REPORTMODEL_H
#define CSM_TOOLS_REPORTMODEL_H

#include <qabstractitemmodel.h>
#include <qnamespace.h>
#include <qobjectdefs.h>
#include <qvariant.h>
#include <QAbstractTableModel>
#include <string>
#include <utility>
#include <vector>

#include "../world/universalid.hpp"

namespace CSMTools
{
    class ReportModel : public QAbstractTableModel
    {
            Q_OBJECT

            std::vector<std::pair<CSMWorld::UniversalId, std::pair<std::string, std::string> > > mRows;

        public:

            virtual int rowCount (const QModelIndex & parent = QModelIndex()) const;

            virtual int columnCount (const QModelIndex & parent = QModelIndex()) const;

            virtual QVariant data (const QModelIndex & index, int role = Qt::DisplayRole) const;

            virtual QVariant headerData (int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

            virtual bool removeRows (int row, int count, const QModelIndex& parent = QModelIndex());

            void add (const CSMWorld::UniversalId& id, const std::string& message,
                const std::string& hint = "");

            const CSMWorld::UniversalId& getUniversalId (int row) const;

            std::string getHint (int row) const;
    };
}

#endif
