#include <MyGUI_Button.h>
#include <MyGUI_TextBox.h>
#include <stddef.h>

#include "MyGUI_RTTI.h"
#include "MyGUI_WidgetInput.h"
#include "apps/openmw/mwgui/itemmodel.hpp"
#include "apps/openmw/mwgui/windowbase.hpp"
#include "inventoryitemmodel.hpp"
#include "itemselection.hpp"
#include "itemview.hpp"
#include "sortfilteritemmodel.hpp"

namespace MyGUI {
class Widget;
}  // namespace MyGUI

namespace MWGui
{

    ItemSelectionDialog::ItemSelectionDialog(const std::string &label)
        : WindowModal("openmw_itemselection_dialog.layout")
        , mSortModel(NULL)
        , mModel(NULL)
    {
        getWidget(mItemView, "ItemView");
        mItemView->eventItemClicked += MyGUI::newDelegate(this, &ItemSelectionDialog::onSelectedItem);

        MyGUI::TextBox* l;
        getWidget(l, "Label");
        l->setCaptionWithReplacing (label);

        MyGUI::Button* cancelButton;
        getWidget(cancelButton, "CancelButton");
        cancelButton->eventMouseButtonClick += MyGUI::newDelegate(this, &ItemSelectionDialog::onCancelButtonClicked);

        center();
    }

    void ItemSelectionDialog::exit()
    {
        eventDialogCanceled();
    }

    void ItemSelectionDialog::openContainer(const MWWorld::Ptr& container)
    {
        mModel = new InventoryItemModel(container);
        mSortModel = new SortFilterItemModel(mModel);
        mItemView->setModel(mSortModel);
    }

    void ItemSelectionDialog::setCategory(int category)
    {
        mSortModel->setCategory(category);
        mItemView->update();
    }

    void ItemSelectionDialog::setFilter(int filter)
    {
        mSortModel->setFilter(filter);
        mItemView->update();
    }

    void ItemSelectionDialog::onSelectedItem(int index)
    {
        ItemStack item = mSortModel->getItem(index);
        eventItemSelected(item.mBase);
    }

    void ItemSelectionDialog::onCancelButtonClicked(MyGUI::Widget* sender)
    {
        exit();
    }

}
