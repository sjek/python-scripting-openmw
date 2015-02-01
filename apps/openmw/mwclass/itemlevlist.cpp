
#include <boost/smart_ptr/shared_ptr.hpp>
#include <components/esm/loadlevlist.hpp>
#include <typeinfo>

#include "apps/openmw/mwclass/../mwworld/livecellref.hpp"
#include "apps/openmw/mwclass/../mwworld/ptr.hpp"
#include "itemlevlist.hpp"

namespace MWWorld {
class Class;
}  // namespace MWWorld

namespace MWClass
{
    std::string ItemLevList::getId (const MWWorld::Ptr& ptr) const
    {
        return ptr.get<ESM::ItemLevList>()->mBase->mId;
    }

    std::string ItemLevList::getName (const MWWorld::Ptr& ptr) const
    {
        return "";
    }

    void ItemLevList::registerSelf()
    {
        boost::shared_ptr<Class> instance (new ItemLevList);

        registerClass (typeid (ESM::ItemLevList).name(), instance);
    }
}
