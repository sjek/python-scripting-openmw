#ifndef SDL4OGRE_SDLINPUTWRAPPER_H
#define SDL4OGRE_SDLINPUTWRAPPER_H

#define NOMINMAX

#include <OgreRenderWindow.h>
#include <SDL_events.h>
#include <boost/functional/hash/hash.hpp>
#include <boost/unordered/unordered_map.hpp>
#include <boost/unordered_map.hpp>
#include <algorithm>
#include <functional>
#include <memory>

#include "OISCompat.h"
#include "SDL_keycode.h"
#include "SDL_scancode.h"
#include "SDL_stdinc.h"
#include "SDL_video.h"
#include "events.h"

namespace Ogre {
class RenderWindow;
}  // namespace Ogre



namespace SFO
{
    class InputWrapper
    {
    public:
        InputWrapper(SDL_Window *window, Ogre::RenderWindow* ogreWindow, bool grab);
        ~InputWrapper();

        void setMouseEventCallback(MouseListener* listen) { mMouseListener = listen; }
        void setKeyboardEventCallback(KeyListener* listen) { mKeyboardListener = listen; }
        void setWindowEventCallback(WindowListener* listen) { mWindowListener = listen; }
        void setJoyEventCallback(JoyListener* listen) { mJoyListener = listen; }

        void capture(bool windowEventsOnly);
		bool isModifierHeld(SDL_Keymod mod);
		bool isKeyDown(SDL_Scancode key);

        void setMouseVisible (bool visible);
        void setMouseRelative(bool relative);
        bool getMouseRelative() { return mMouseRelative; }
        void setGrabPointer(bool grab);

        OIS::KeyCode sdl2OISKeyCode(SDL_Keycode code);

        void warpMouse(int x, int y);

        void updateMouseSettings();

    private:

        void handleWindowEvent(const SDL_Event& evt);

        bool _handleWarpMotion(const SDL_MouseMotionEvent& evt);
        void _wrapMousePointer(const SDL_MouseMotionEvent &evt);
        MouseMotionEvent _packageMouseMotion(const SDL_Event& evt);

        void _setupOISKeys();

        SFO::MouseListener* mMouseListener;
        SFO::KeyListener* mKeyboardListener;
        SFO::WindowListener* mWindowListener;
        SFO::JoyListener* mJoyListener;

        typedef boost::unordered_map<SDL_Keycode, OIS::KeyCode> KeyMap;
        KeyMap mKeyMap;

        Uint16 mWarpX;
        Uint16 mWarpY;
        bool mWarpCompensate;
        bool mWrapPointer;

        bool mAllowGrab;
        bool mWantMouseVisible;
        bool mWantGrab;
        bool mWantRelative;
        bool mGrabPointer;
        bool mMouseRelative;

        bool mFirstMouseMove;

        Sint32 mMouseZ;
        Sint32 mMouseX;
        Sint32 mMouseY;

        bool mWindowHasFocus;
        bool mMouseInWindow;

        SDL_Window* mSDLWindow;
        Ogre::RenderWindow* mOgreWindow;
    };

}

#endif
