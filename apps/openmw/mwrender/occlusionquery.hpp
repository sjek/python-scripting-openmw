#ifndef GAME_OCCLUSION_QUERY_H
#define GAME_OCCLUSION_QUERY_H

#include <OgreCommon.h>
#include <OgrePlatform.h>
#include <OgrePrerequisites.h>
#include <OgreRenderObjectListener.h>
#include <OgreRenderQueueListener.h>

namespace Ogre
{
    class Entity;
    class HardwareOcclusionQuery;
    class SceneNode;
}

#include <openengine/ogre/renderer.hpp>

namespace OEngine {
namespace Render {
class OgreRenderer;
}  // namespace Render
}  // namespace OEngine
namespace Ogre {
class AutoParamDataSource;
class Pass;
class Renderable;
}  // namespace Ogre

namespace MWRender
{
    ///
    /// \brief Implements hardware occlusion queries on the GPU
    ///
    class OcclusionQuery : public Ogre::RenderObjectListener, public Ogre::RenderQueueListener
    {
    public:
        OcclusionQuery(OEngine::Render::OgreRenderer*, Ogre::SceneNode* sunNode);
        ~OcclusionQuery();

        /**
         * @return true if occlusion queries are supported on the user's hardware
         */
        bool supported();

        /**
         * make sure to disable occlusion queries before updating unrelated render targets
         * @param active
         */
        void setActive (bool active) { mActive = active; }

        /**
         * per-frame update
         */
        void update(float duration);

        float getSunVisibility() const {return mSunVisibility;};

        void setSunNode(Ogre::SceneNode* node);

    private:
        Ogre::HardwareOcclusionQuery* mSunTotalAreaQuery;
        Ogre::HardwareOcclusionQuery* mSunVisibleAreaQuery;
        Ogre::HardwareOcclusionQuery* mActiveQuery;

        Ogre::Entity* mBBQueryVisible;
        Ogre::Entity* mBBQueryTotal;

        Ogre::SceneNode* mSunNode;
        Ogre::SceneNode* mBBNodeReal;
        float mSunVisibility;

        bool mWasVisible;

        bool mActive;
        bool mFirstFrame;

        bool mSupported;
        bool mDoQuery;

        OEngine::Render::OgreRenderer* mRendering;

    protected:
        virtual void notifyRenderSingleObject(Ogre::Renderable* rend, const Ogre::Pass* pass, const Ogre::AutoParamDataSource* source, 
			const Ogre::LightList* pLightList, bool suppressRenderStateChanges);

        virtual void renderQueueEnded(Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& repeatThisInvocation);
    };
}

#endif
