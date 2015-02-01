#ifndef OPENCS_VIEW_LIGHTING_DAY_H
#define OPENCS_VIEW_LIGHTING_DAY_H

#include "lighting.hpp"

namespace Ogre {
class ColourValue;
class SceneManager;
}  // namespace Ogre

namespace Ogre
{
    class Light;
}

namespace CSVRender
{
    class LightingDay : public Lighting
    {
            Ogre::SceneManager *mSceneManager;
            Ogre::Light *mLight;

        public:

            LightingDay();

            virtual void activate (Ogre::SceneManager *sceneManager,
                const Ogre::ColourValue *defaultAmbient = 0);

            virtual void deactivate();

            virtual void setDefaultAmbient (const Ogre::ColourValue& colour);
    };
}

#endif
