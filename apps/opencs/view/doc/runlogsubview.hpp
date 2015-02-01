#ifndef CSV_DOC_RUNLOGSUBVIEW_H
#define CSV_DOC_RUNLOGSUBVIEW_H

#include <qobjectdefs.h>

#include "apps/opencs/view/doc/../../model/doc/../world/universalid.hpp"
#include "subview.hpp"

namespace CSMDoc {
class Document;
}  // namespace CSMDoc

namespace CSVDoc
{
    class RunLogSubView : public SubView
    {
            Q_OBJECT

        public:

            RunLogSubView (const CSMWorld::UniversalId& id, CSMDoc::Document& document);

            virtual void setEditLock (bool locked);
    };
}

#endif
