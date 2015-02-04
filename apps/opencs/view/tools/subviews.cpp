
#include "../doc/subviewfactoryimp.hpp"
#include "apps/opencs/view/tools/../doc/../../model/doc/../world/universalid.hpp"
#include "apps/opencs/view/tools/../doc/subview.hpp"
#include "apps/opencs/view/tools/../doc/subviewfactory.hpp"
#include "reportsubview.hpp"
#include "subviews.hpp"

void CSVTools::addSubViewFactories (CSVDoc::SubViewFactoryManager& manager)
{
    manager.add (CSMWorld::UniversalId::Type_VerificationResults,
        new CSVDoc::SubViewFactory<ReportSubView>);
    manager.add (CSMWorld::UniversalId::Type_LoadErrorLog,
        new CSVDoc::SubViewFactory<ReportSubView>);
}
