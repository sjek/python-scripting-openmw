#ifndef MWGUI_MESSAGE_BOX_H
#define MWGUI_MESSAGE_BOX_H

#include <string>
#include <vector>

#include "MyGUI_DelegateImplement.h"
#include "MyGUI_KeyCode.h"
#include "MyGUI_Types.h"
#include "openengine/gui/layout.hpp"
#include "windowbase.hpp"

#undef MessageBox

namespace MyGUI
{
    class Button;
    class EditBox;
    class Widget;
}

namespace MWGui
{
    class InteractiveMessageBox;
    class MessageBox;
    class MessageBoxManager;

    class MessageBoxManager
    {
        public:
            MessageBoxManager (float timePerChar);
            ~MessageBoxManager ();
            void onFrame (float frameDuration);
            void createMessageBox (const std::string& message, bool stat = false);
            void removeStaticMessageBox ();
            bool createInteractiveMessageBox (const std::string& message, const std::vector<std::string>& buttons);
            bool isInteractiveMessageBox ();

            /// Remove all message boxes
            void clear();

            bool removeMessageBox (MessageBox *msgbox);

            /// @param reset Reset the pressed button to -1 after reading it.
            int readPressedButton (bool reset=true);

            typedef MyGUI::delegates::CMultiDelegate1<int> EventHandle_Int;

            // Note: this delegate unassigns itself after it was fired, i.e. works once.
            EventHandle_Int eventButtonPressed;

            void onButtonPressed(int button) { eventButtonPressed(button); eventButtonPressed.clear(); }

        private:
            std::vector<MessageBox*> mMessageBoxes;
            InteractiveMessageBox* mInterMessageBoxe;
            MessageBox* mStaticMessageBox;
            float mMessageBoxSpeed;
            int mLastButtonPressed;
    };

    class MessageBox : public OEngine::GUI::Layout
    {
        public:
            MessageBox (MessageBoxManager& parMessageBoxManager, const std::string& message);
            void setMessage (const std::string& message);
            int getHeight ();
            void update (int height);

            float mCurrentTime;
            float mMaxTime;

        protected:
            MessageBoxManager& mMessageBoxManager;
            const std::string& mMessage;
            MyGUI::EditBox* mMessageWidget;
            int mBottomPadding;
            int mNextBoxPadding;
    };

    class InteractiveMessageBox : public WindowModal
    {
        public:
            InteractiveMessageBox (MessageBoxManager& parMessageBoxManager, const std::string& message, const std::vector<std::string>& buttons);
            void mousePressed (MyGUI::Widget* _widget);
            int readPressedButton ();

            bool mMarkedToDelete;

        private:
            void buttonActivated (MyGUI::Widget* _widget);
            void onKeyPressed(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char);

            MessageBoxManager& mMessageBoxManager;
            MyGUI::EditBox* mMessageWidget;
            MyGUI::Widget* mButtonsWidget;
            std::vector<MyGUI::Button*> mButtons;

            int mTextButtonPadding;
            int mButtonPressed;
    };

}

#endif
