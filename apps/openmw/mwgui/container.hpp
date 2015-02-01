#ifndef MGUI_CONTAINER_H
#define MGUI_CONTAINER_H

#include "MyGUI_KeyCode.h"
#include "MyGUI_Types.h"
#include "itemmodel.hpp"
#include "referenceinterface.hpp"
#include "windowbase.hpp"

namespace MWGui {
class DragAndDrop;
class ItemModel;
struct ItemStack;
}  // namespace MWGui
namespace MWWorld {
class Ptr;
}  // namespace MWWorld
namespace MyGUI {
class Button;
}  // namespace MyGUI

namespace MWWorld
{
    class Environment;
}

namespace MyGUI
{
    class Gui;
    class Widget;
}

namespace MWGui
{
    class ContainerWindow;
    class ItemView;
    class SortFilterItemModel;
    class WindowManager;
}


namespace MWGui
{
    class ContainerWindow : public WindowBase, public ReferenceInterface
    {
    public:
        ContainerWindow(DragAndDrop* dragAndDrop);

        void open(const MWWorld::Ptr& container, bool loot=false);
        virtual void close();

        virtual void resetReference();

        virtual void exit();

    private:
        DragAndDrop* mDragAndDrop;

        bool mPickpocketDetected;

        MWGui::ItemView* mItemView;
        SortFilterItemModel* mSortModel;
        ItemModel* mModel;
        int mSelectedItem;

        MyGUI::Button* mDisposeCorpseButton;
        MyGUI::Button* mTakeButton;
        MyGUI::Button* mCloseButton;

        void onItemSelected(int index);
        void onBackgroundSelected();
        void dragItem(MyGUI::Widget* sender, int count);
        void dropItem();
        void onCloseButtonClicked(MyGUI::Widget* _sender);
        void onTakeAllButtonClicked(MyGUI::Widget* _sender);
        void onDisposeCorpseButtonClicked(MyGUI::Widget* sender);
        void onKeyPressed(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char);

        /// @return is taking the item allowed?
        bool onTakeItem(const ItemStack& item, int count);

        virtual void onReferenceUnavailable();
    };
}
#endif // CONTAINER_H
