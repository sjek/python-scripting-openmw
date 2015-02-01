#ifndef MWGUI_QUICKKEYS_H
#define MWGUI_QUICKKEYS_H

#include <stdint.h>
#include <string>
#include <vector>

#include "../mwworld/ptr.hpp"
#include "spellmodel.hpp"
#include "windowbase.hpp"

namespace ESM {
class ESMReader;
class ESMWriter;
}  // namespace ESM
namespace MWWorld {
class Ptr;
}  // namespace MWWorld
namespace MyGUI {
class Button;
class EditBox;
class TextBox;
class Widget;
}  // namespace MyGUI

namespace MWGui
{

    class ItemSelectionDialog;
    class ItemWidget;
    class MagicSelectionDialog;
    class QuickKeysMenuAssign;
    class SpellView;

    class QuickKeysMenu : public WindowBase
    {
    public:
        QuickKeysMenu();
        ~QuickKeysMenu();

        virtual void exit();

        void onItemButtonClicked(MyGUI::Widget* sender);
        void onMagicButtonClicked(MyGUI::Widget* sender);
        void onUnassignButtonClicked(MyGUI::Widget* sender);
        void onCancelButtonClicked(MyGUI::Widget* sender);

        void onAssignItem (MWWorld::Ptr item);
        void onAssignItemCancel ();
        void onAssignMagicItem (MWWorld::Ptr item);
        void onAssignMagic (const std::string& spellId);
        void onAssignMagicCancel ();

        void activateQuickKey(int index);

        enum QuickKeyType
        {
            Type_Item,
            Type_Magic,
            Type_MagicItem,
            Type_Unassigned
        };


        void write (ESM::ESMWriter& writer);
        void readRecord (ESM::ESMReader& reader, uint32_t type);
        void clear();


    private:
        MyGUI::EditBox* mInstructionLabel;
        MyGUI::Button* mOkButton;

        std::vector<ItemWidget*> mQuickKeyButtons;
        std::vector<QuickKeyType> mAssigned;

        QuickKeysMenuAssign* mAssignDialog;
        ItemSelectionDialog* mItemSelectionDialog;
        MagicSelectionDialog* mMagicSelectionDialog;

        int mSelectedIndex;


        void onQuickKeyButtonClicked(MyGUI::Widget* sender);
        void onOkButtonClicked(MyGUI::Widget* sender);

        void unassign(ItemWidget* key, int index);
    };

    class QuickKeysMenuAssign : public WindowModal
    {
    public:
        QuickKeysMenuAssign(QuickKeysMenu* parent);
        virtual void exit();

    private:
        MyGUI::TextBox* mLabel;
        MyGUI::Button* mItemButton;
        MyGUI::Button* mMagicButton;
        MyGUI::Button* mUnassignButton;
        MyGUI::Button* mCancelButton;

        QuickKeysMenu* mParent;
    };

    class MagicSelectionDialog : public WindowModal
    {
    public:
        MagicSelectionDialog(QuickKeysMenu* parent);

        virtual void open();
        virtual void exit();

    private:
        MyGUI::Button* mCancelButton;
        SpellView* mMagicList;

        QuickKeysMenu* mParent;

        void onCancelButtonClicked (MyGUI::Widget* sender);
        void onModelIndexSelected(SpellModel::ModelIndex index);
    };
}


#endif
