#include "../mwmechanics/npcstats.hpp"
#include "../mwworld/class.hpp"
#include "apps/openmw/mwgui/inventoryitemmodel.hpp"
#include "apps/openmw/mwgui/itemmodel.hpp"
#include "companionitemmodel.hpp"

namespace MWGui
{
    CompanionItemModel::CompanionItemModel(const MWWorld::Ptr &actor)
        : InventoryItemModel(actor)
    {
    }

    MWWorld::Ptr CompanionItemModel::copyItem (const ItemStack& item, size_t count, bool setNewOwner=false)
    {
        if (mActor.getClass().isNpc())
        {
            MWMechanics::NpcStats& stats = mActor.getClass().getNpcStats(mActor);
            stats.modifyProfit(item.mBase.getClass().getValue(item.mBase) * count);
        }

        return InventoryItemModel::copyItem(item, count, setNewOwner);
    }

    void CompanionItemModel::removeItem (const ItemStack& item, size_t count)
    {
        if (mActor.getClass().isNpc())
        {
            MWMechanics::NpcStats& stats = mActor.getClass().getNpcStats(mActor);
            stats.modifyProfit(-item.mBase.getClass().getValue(item.mBase) * count);
        }

        InventoryItemModel::removeItem(item, count);
    }
}
