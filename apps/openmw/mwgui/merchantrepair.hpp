#ifndef OPENMW_MWGUI_MERCHANTREPAIR_H
#define OPENMW_MWGUI_MERCHANTREPAIR_H

#include "../mwworld/ptr.hpp"
#include "windowbase.hpp"

namespace MyGUI {
class Button;
class ScrollView;
class TextBox;
class Widget;
}  // namespace MyGUI

namespace MWGui
{

class MerchantRepair : public WindowBase
{
public:
    MerchantRepair();

    virtual void open();

    virtual void exit();

    void startRepair(const MWWorld::Ptr& actor);

private:
    MyGUI::ScrollView* mList;
    MyGUI::Button* mOkButton;
    MyGUI::TextBox* mGoldLabel;

    MWWorld::Ptr mActor;

protected:
    void onMouseWheel(MyGUI::Widget* _sender, int _rel);
    void onRepairButtonClick(MyGUI::Widget* sender);
    void onOkButtonClick(MyGUI::Widget* sender);

};

}

#endif
