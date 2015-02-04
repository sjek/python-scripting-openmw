#ifndef OPENMW_WIDGETS_WINDOWCAPTION_H
#define OPENMW_WIDGETS_WINDOWCAPTION_H

#include <MyGUI_EditBox.h>
#include <MyGUI_RTTI.h>
#include <MyGUI_Types.h>
#include <MyGUI_UString.h>
#include <string>

namespace MyGUI {
class Widget;
}  // namespace MyGUI

namespace Gui
{

    /// Window caption that automatically adjusts "Left" and "Right" widgets in its skin
    /// based on the text size of the caption in the middle
    class WindowCaption : public MyGUI::EditBox
    {
        MYGUI_RTTI_DERIVED(WindowCaption)
    public:
        WindowCaption();

        virtual void setCaption(const MyGUI::UString &_value);
        virtual void initialiseOverride();

        virtual void setSize(const MyGUI::IntSize& _value);
        virtual void setCoord(const MyGUI::IntCoord& _value);

    private:
        MyGUI::Widget* mLeft;
        MyGUI::Widget* mRight;

        void align();
    };

}

#endif
