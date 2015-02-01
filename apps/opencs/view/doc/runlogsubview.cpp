
#include <qtextedit.h>

#include "apps/opencs/view/doc/../../model/doc/document.hpp"
#include "apps/opencs/view/doc/subview.hpp"
#include "runlogsubview.hpp"

CSVDoc::RunLogSubView::RunLogSubView (const CSMWorld::UniversalId& id,
    CSMDoc::Document& document)
: SubView (id)
{
    QTextEdit *edit = new QTextEdit (this);
    edit->setDocument (document.getRunLog());
    edit->setReadOnly (true);

    setWidget (edit);
}

void CSVDoc::RunLogSubView::setEditLock (bool locked)
{
    // ignored since this SubView does not have editing
}
