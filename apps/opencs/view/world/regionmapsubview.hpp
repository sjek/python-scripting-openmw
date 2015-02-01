#ifndef CSV_WORLD_REGIONMAPSUBVIEW_H
#define CSV_WORLD_REGIONMAPSUBVIEW_H

#include <qobjectdefs.h>
#include <string>

#include "../doc/subview.hpp"
#include "apps/opencs/view/world/../doc/../../model/doc/../world/universalid.hpp"

class QAction;

namespace CSMDoc
{
    class Document;
}

namespace CSVWorld
{
    class RegionMap;

    class RegionMapSubView : public CSVDoc::SubView
    {
            Q_OBJECT

            RegionMap *mRegionMap;

        public:

            RegionMapSubView (CSMWorld::UniversalId universalId, CSMDoc::Document& document);

            virtual void setEditLock (bool locked);

        private slots:

            void editRequest (const CSMWorld::UniversalId& id, const std::string& hint);
    };
}

#endif
