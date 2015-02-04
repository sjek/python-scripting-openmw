#ifndef GAME_RENDER_ACTIVATORANIMATION_H
#define GAME_RENDER_ACTIVATORANIMATION_H

#include <string>

#include "animation.hpp"

namespace ESM {
struct Light;
}  // namespace ESM

namespace MWWorld
{
    class Ptr;
}

namespace MWRender
{
    class ActivatorAnimation : public Animation
    {
    public:
        ActivatorAnimation(const MWWorld::Ptr& ptr, const std::string &model);
        virtual ~ActivatorAnimation();

        void addLight(const ESM::Light *light);
        void removeParticles();
    };
}

#endif
