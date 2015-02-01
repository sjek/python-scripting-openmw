#ifndef MWRENDER_CHARACTERPREVIEW_H
#define MWRENDER_CHARACTERPREVIEW_H

#include <OgreMaterialManager.h>
#include <OgreRenderTarget.h>
#include <OgreVector3.h>
#include <components/esm/loadnpc.hpp>
#include <string>

#include "../mwworld/ptr.hpp"
#include "OgreMath.h"
#include "OgrePrerequisites.h"
#include "OgreResource.h"
#include "OgreSharedPtr.h"
#include "apps/openmw/mwrender/../mwworld/livecellref.hpp"

namespace Ogre {
class Camera;
class RenderTarget;
class SceneManager;
class SceneNode;
class Viewport;
}  // namespace Ogre

namespace OEngine
{
namespace Render
{
class SelectionBuffer;
}
}

namespace MWRender
{

    class NpcAnimation;

    class CharacterPreview : public Ogre::ManualResourceLoader
    {
    public:
        CharacterPreview(MWWorld::Ptr character, int sizeX, int sizeY, const std::string& name,
                         Ogre::Vector3 position, Ogre::Vector3 lookAt);
        virtual ~CharacterPreview();

        virtual void setup ();
        virtual void onSetup();

        virtual void rebuild();

        void onFrame();

        void loadResource(Ogre::Resource *resource);

    private:
        bool mRecover; // Texture content was lost and needs to be re-rendered

    private:
        CharacterPreview(const CharacterPreview&);
        CharacterPreview& operator=(const CharacterPreview&);

    protected:
        virtual bool renderHeadOnly() { return false; }

        virtual void setupRenderTarget();

        Ogre::TexturePtr mTexture;
        Ogre::RenderTarget* mRenderTarget;
        Ogre::Viewport* mViewport;

        Ogre::Camera* mCamera;

        Ogre::SceneManager* mSceneMgr;
        Ogre::SceneNode* mNode;

        Ogre::Vector3 mPosition;
        Ogre::Vector3 mLookAt;

        MWWorld::Ptr mCharacter;

        MWRender::NpcAnimation* mAnimation;
        std::string mCurrentAnimGroup;

        std::string mName;

        int mSizeX;
        int mSizeY;
    };

    class InventoryPreview : public CharacterPreview
    {
    public:

        InventoryPreview(MWWorld::Ptr character);
        virtual ~InventoryPreview();
        virtual void onSetup();

        void update(); // Render preview again, e.g. after changed equipment
        void resize(int sizeX, int sizeY);

        int getSlotSelected(int posX, int posY);

    protected:
        virtual void setupRenderTarget();

    private:
        int mSizeX;
        int mSizeY;

        OEngine::Render::SelectionBuffer* mSelectionBuffer;
    };

    class RaceSelectionPreview : public CharacterPreview
    {
        ESM::NPC                        mBase;
        MWWorld::LiveCellRef<ESM::NPC>  mRef;

    protected:

        virtual bool renderHeadOnly() { return true; }

        void updateCamera();

    public:
        RaceSelectionPreview();

        virtual void onSetup();
        void render();

        void update(float angle);

        const ESM::NPC &getPrototype() const {
            return mBase;
        }

        void setPrototype(const ESM::NPC &proto);

    private:

        Ogre::Radian mPitch;
    };

}

#endif
