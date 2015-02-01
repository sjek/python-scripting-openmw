#include <MyGUI_InputManager.h>
#include <stddef.h>
#include <string>
#include <typeinfo>
#include <vector>

#include "../mwbase/environment.hpp"
#include "../mwbase/windowmanager.hpp"
#include "../mwmechanics/npcstats.hpp"
#include "../mwworld/class.hpp"
#include "MyGUI_Button.h"
#include "MyGUI_DelegateImplement.h"
#include "MyGUI_RTTI.h"
#include "MyGUI_StringUtility.h"
#include "MyGUI_TextBox.h"
#include "MyGUI_WidgetInput.h"
#include "apps/openmw/mwgui/../mwbase/../mwgui/mode.hpp"
#include "apps/openmw/mwgui/../mwworld/../mwscript/locals.hpp"
#include "apps/openmw/mwgui/../mwworld/ptr.hpp"
#include "apps/openmw/mwgui/../mwworld/refdata.hpp"
#include "apps/openmw/mwgui/itemmodel.hpp"
#include "apps/openmw/mwgui/referenceinterface.hpp"
#include "apps/openmw/mwgui/widgets.hpp"
#include "apps/openmw/mwgui/windowbase.hpp"
#include "companionitemmodel.hpp"
#include "companionwindow.hpp"
#include "components/esm/loadnpc.hpp"
#include "countdialog.hpp"
#include "draganddrop.hpp"
#include "itemview.hpp"
#include "messagebox.hpp"
#include "sortfilteritemmodel.hpp"

namespace MyGUI {
class Widget;
}  // namespace MyGUI

namespace MWGui
{

CompanionWindow::CompanionWindow(DragAndDrop *dragAndDrop, MessageBoxManager* manager)
    : WindowBase("openmw_companion_window.layout")
    , mDragAndDrop(dragAndDrop)
    , mMessageBoxManager(manager)
    , mSelectedItem(-1)
    , mModel(NULL)
    , mSortModel(NULL)
{
    getWidget(mCloseButton, "CloseButton");
    getWidget(mProfitLabel, "ProfitLabel");
    getWidget(mEncumbranceBar, "EncumbranceBar");
    getWidget(mItemView, "ItemView");
    mItemView->eventBackgroundClicked += MyGUI::newDelegate(this, &CompanionWindow::onBackgroundSelected);
    mItemView->eventItemClicked += MyGUI::newDelegate(this, &CompanionWindow::onItemSelected);

    mCloseButton->eventMouseButtonClick += MyGUI::newDelegate(this, &CompanionWindow::onCloseButtonClicked);

    setCoord(200,0,600,300);
}

void CompanionWindow::onItemSelected(int index)
{
    if (mDragAndDrop->mIsOnDragAndDrop)
    {
        mDragAndDrop->drop(mModel, mItemView);
        updateEncumbranceBar();
        return;
    }

    const ItemStack& item = mSortModel->getItem(index);

    // We can't take conjured items from a companion NPC
    if (item.mFlags & ItemStack::Flag_Bound)
    {
        MWBase::Environment::get().getWindowManager()->messageBox("#{sBarterDialog12}");
        return;
    }

    MWWorld::Ptr object = item.mBase;
    int count = item.mCount;
    bool shift = MyGUI::InputManager::getInstance().isShiftPressed();
    if (MyGUI::InputManager::getInstance().isControlPressed())
        count = 1;

    mSelectedItem = mSortModel->mapToSource(index);

    if (count > 1 && !shift)
    {
        CountDialog* dialog = MWBase::Environment::get().getWindowManager()->getCountDialog();
        dialog->open(object.getClass().getName(object), "#{sTake}", count);
        dialog->eventOkClicked.clear();
        dialog->eventOkClicked += MyGUI::newDelegate(this, &CompanionWindow::dragItem);
    }
    else
        dragItem (NULL, count);
}

void CompanionWindow::dragItem(MyGUI::Widget* sender, int count)
{
    mDragAndDrop->startDrag(mSelectedItem, mSortModel, mModel, mItemView, count);
}

void CompanionWindow::onBackgroundSelected()
{
    if (mDragAndDrop->mIsOnDragAndDrop)
    {
        mDragAndDrop->drop(mModel, mItemView);
        updateEncumbranceBar();
    }
}

void CompanionWindow::open(const MWWorld::Ptr& npc)
{
    mPtr = npc;
    updateEncumbranceBar();

    mModel = new CompanionItemModel(npc);
    mSortModel = new SortFilterItemModel(mModel);
    mItemView->setModel(mSortModel);

    setTitle(npc.getClass().getName(npc));
}

void CompanionWindow::onFrame()
{
    updateEncumbranceBar();
}

void CompanionWindow::updateEncumbranceBar()
{
    if (mPtr.isEmpty())
        return;
    float capacity = mPtr.getClass().getCapacity(mPtr);
    float encumbrance = mPtr.getClass().getEncumbrance(mPtr);
    mEncumbranceBar->setValue(encumbrance, capacity);

    if (mPtr.getTypeName() != typeid(ESM::NPC).name())
        mProfitLabel->setCaption("");
    else
    {
        MWMechanics::NpcStats& stats = mPtr.getClass().getNpcStats(mPtr);
        mProfitLabel->setCaptionWithReplacing("#{sProfitValue} " + MyGUI::utility::toString(stats.getProfit()));
    }
}

void CompanionWindow::onCloseButtonClicked(MyGUI::Widget* _sender)
{
    exit();
}

void CompanionWindow::exit()
{
    if (mPtr.getTypeName() == typeid(ESM::NPC).name() && mPtr.getClass().getNpcStats(mPtr).getProfit() < 0)
    {
        std::vector<std::string> buttons;
        buttons.push_back("#{sCompanionWarningButtonOne}");
        buttons.push_back("#{sCompanionWarningButtonTwo}");
        mMessageBoxManager->createInteractiveMessageBox("#{sCompanionWarningMessage}", buttons);
        mMessageBoxManager->eventButtonPressed += MyGUI::newDelegate(this, &CompanionWindow::onMessageBoxButtonClicked);
    }
    else
        MWBase::Environment::get().getWindowManager()->removeGuiMode(GM_Companion);
}

void CompanionWindow::onMessageBoxButtonClicked(int button)
{
    if (button == 0)
    {
        mPtr.getRefData().getLocals().setVarByInt(mPtr.getClass().getScript(mPtr),
            "minimumprofit", mPtr.getClass().getNpcStats(mPtr).getProfit());

        MWBase::Environment::get().getWindowManager()->removeGuiMode(GM_Companion);
        // Important for Calvus' contract script to work properly
        MWBase::Environment::get().getWindowManager()->removeGuiMode(GM_Dialogue);
    }
}

void CompanionWindow::onReferenceUnavailable()
{
    MWBase::Environment::get().getWindowManager()->removeGuiMode(GM_Companion);
}

void CompanionWindow::resetReference()
{
    ReferenceInterface::resetReference();
    mItemView->setModel(NULL);
    mModel = NULL;
    mSortModel = NULL;
}


}
