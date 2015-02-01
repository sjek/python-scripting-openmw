#ifndef MWGUI_IMAGEBUTTON_H
#define MWGUI_IMAGEBUTTON_H

#include <MyGUI_ImageBox.h>
#include <string>

#include "MyGUI_MouseButton.h"
#include "MyGUI_RTTI.h"
#include "MyGUI_Types.h"

namespace MyGUI {
class Widget;
}  // namespace MyGUI

namespace Gui
{

    /**
     * @brief allows using different image textures depending on the button state
     */
    class ImageButton : public MyGUI::ImageBox
    {
        MYGUI_RTTI_DERIVED(ImageButton)

    public:
        MyGUI::IntSize getRequestedSize(bool logError = true);

    protected:
        virtual void setPropertyOverride(const std::string& _key, const std::string& _value);
        virtual void onMouseLostFocus(MyGUI::Widget* _new);
        virtual void onMouseSetFocus(MyGUI::Widget* _old);
        virtual void onMouseButtonPressed(int _left, int _top, MyGUI::MouseButton _id);
        virtual void onMouseButtonReleased(int _left, int _top, MyGUI::MouseButton _id);

        std::string mImageHighlighted;
        std::string mImageNormal;
        std::string mImagePushed;
    };

}

#endif
