#ifndef MWGUI_TravelWINDOW_H
#define MWGUI_TravelWINDOW_H


#include <string>

#include "referenceinterface.hpp"
#include "windowbase.hpp"

namespace ESM {
struct Position;
}  // namespace ESM
namespace MWWorld {
class Ptr;
}  // namespace MWWorld
namespace MyGUI {
class Button;
class ScrollView;
class TextBox;
}  // namespace MyGUI

namespace MyGUI
{
  class Gui;
  class Widget;
}

namespace MWGui
{
    class WindowManager;
}


namespace MWGui
{
    class TravelWindow : public ReferenceInterface, public WindowBase
    {
        public:
            TravelWindow();

            virtual void exit();

            void startTravel(const MWWorld::Ptr& actor);

        protected:
            MyGUI::Button* mCancelButton;
            MyGUI::TextBox* mPlayerGold;
            MyGUI::TextBox* mDestinations;
            MyGUI::TextBox* mSelect;

            MyGUI::ScrollView* mDestinationsView;

            void onCancelButtonClicked(MyGUI::Widget* _sender);
            void onTravelButtonClick(MyGUI::Widget* _sender);
            void onMouseWheel(MyGUI::Widget* _sender, int _rel);
            void addDestination(const std::string& name, ESM::Position pos, bool interior);
            void clearDestinations();
            int mCurrentY;

            static const int sLineHeight;

            void updateLabels();

            virtual void onReferenceUnavailable();
    };
}

#endif
