#ifndef MWGUI_LOADINGSCREEN_H
#define MWGUI_LOADINGSCREEN_H

#include <OgreStringVector.h>
#include <OgreTimer.h>
#include <components/loadinglistener/loadinglistener.hpp>
#include <stddef.h>
#include <string>

#include "GLX/OgreTimerImp.h"
#include "windowbase.hpp"

namespace MyGUI {
class ScrollBar;
class TextBox;
class Widget;
}  // namespace MyGUI
namespace Ogre {
class RenderWindow;
}  // namespace Ogre

namespace Ogre
{
    class SceneManager;
}

namespace MWGui
{
    class BackgroundImage;

    class LoadingScreen : public WindowBase, public Loading::Listener
    {
    public:
        virtual void setLabel (const std::string& label);

        /// Indicate that some progress has been made, without specifying how much
        virtual void indicateProgress ();

        virtual void loadingOn();
        virtual void loadingOff();

        virtual void setProgressRange (size_t range);
        virtual void setProgress (size_t value);
        virtual void increaseProgress (size_t increase=1);

        virtual void setVisible(bool visible);

        LoadingScreen(Ogre::SceneManager* sceneMgr, Ogre::RenderWindow* rw);
        virtual ~LoadingScreen();

        void setLoadingProgress (const std::string& stage, int depth, int current, int total);
        void loadingDone();

        void updateWindow(Ogre::RenderWindow* rw) { mWindow = rw; }

    private:
        Ogre::SceneManager* mSceneMgr;
        Ogre::RenderWindow* mWindow;

        unsigned long mLastWallpaperChangeTime;
        unsigned long mLastRenderTime;
        Ogre::Timer mTimer;

        size_t mProgress;

        MyGUI::Widget* mLoadingBox;

        MyGUI::TextBox* mLoadingText;
        MyGUI::ScrollBar* mProgressBar;
        BackgroundImage* mBackgroundImage;

        Ogre::StringVector mResources;

        bool mVSyncWasEnabled;

        void changeWallpaper();

        void draw();
    };

}


#endif
