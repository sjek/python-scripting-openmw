#include <MyGUI_Button.h>
#include <stddef.h>
#include <vector>

#include "MyGUI_DelegateImplement.h"
#include "MyGUI_RTTI.h"
#include "MyGUI_Widget.h"
#include "MyGUI_WidgetDefines.h"
#include "MyGUI_WidgetInput.h"
#include "apps/openmw/mwgui/windowbase.hpp"
#include "exposedwindow.hpp"
#include "windowpinnablebase.hpp"

namespace MWGui
{
    WindowPinnableBase::WindowPinnableBase(const std::string& parLayout)
      : WindowBase(parLayout), mPinned(false)
    {
        ExposedWindow* window = mMainWidget->castType<ExposedWindow>();
        mPinButton = window->getSkinWidget ("Button");

        mPinButton->eventMouseButtonClick += MyGUI::newDelegate(this, &WindowPinnableBase::onPinButtonClicked);

        MyGUI::Button* button = NULL;
        MyGUI::VectorWidgetPtr widgets = window->getSkinWidgetsByName("Action");
        for (MyGUI::VectorWidgetPtr::iterator it = widgets.begin(); it != widgets.end(); ++it)
        {
            if ((*it)->isUserString("HideWindowOnDoubleClick"))
                button = (*it)->castType<MyGUI::Button>();
        }

        if (button)
            button->eventMouseButtonDoubleClick += MyGUI::newDelegate(this, &WindowPinnableBase::onDoubleClick);
    }

    void WindowPinnableBase::onPinButtonClicked(MyGUI::Widget* _sender)
    {
        mPinned = !mPinned;

        if (mPinned)
            mPinButton->changeWidgetSkin ("PinDown");
        else
            mPinButton->changeWidgetSkin ("PinUp");

        onPinToggled();
    }

    void WindowPinnableBase::onDoubleClick(MyGUI::Widget *_sender)
    {
        onTitleDoubleClicked();
    }

    void WindowPinnableBase::setPinned(bool pinned)
    {
        if (pinned != mPinned)
            onPinButtonClicked(mPinButton);
    }

    void WindowPinnableBase::setPinButtonVisible(bool visible)
    {
        mPinButton->setVisible(visible);
    }
}
