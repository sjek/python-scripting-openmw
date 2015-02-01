#ifndef MWGUI_TRAININGWINDOW_H
#define MWGUI_TRAININGWINDOW_H

#include "referenceinterface.hpp"
#include "windowbase.hpp"

namespace MWWorld {
class Ptr;
}  // namespace MWWorld
namespace MyGUI {
class Button;
class TextBox;
class Widget;
}  // namespace MyGUI

namespace MWGui
{

    class TrainingWindow : public WindowBase, public ReferenceInterface
    {
    public:
        TrainingWindow();

        virtual void open();

        virtual void exit();

        void startTraining(MWWorld::Ptr actor);

        void onFrame(float dt);

    protected:
        virtual void onReferenceUnavailable ();

        void onCancelButtonClicked (MyGUI::Widget* sender);
        void onTrainingSelected(MyGUI::Widget* sender);

        MyGUI::Widget* mTrainingOptions;
        MyGUI::Button* mCancelButton;
        MyGUI::TextBox* mPlayerGold;

        float mFadeTimeRemaining;
    };

}

#endif
