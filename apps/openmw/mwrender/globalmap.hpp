#ifndef GAME_RENDER_GLOBALMAP_H
#define GAME_RENDER_GLOBALMAP_H

#include <OgreTexture.h>
#include <string>
#include <utility>
#include <vector>

#include "OgreImage.h"
#include "OgrePrerequisites.h"
#include "OgreResource.h"
#include "OgreSharedPtr.h"

namespace Loading
{
    class Listener;
}

namespace ESM
{
    class GlobalMap;
}

namespace MWRender
{

    class GlobalMap : public Ogre::ManualResourceLoader
    {
    public:
        GlobalMap(const std::string& cacheDir);
        ~GlobalMap();

        void render(Loading::Listener* loadingListener);

        int getWidth() const { return mWidth; }
        int getHeight() const { return mHeight; }

        int getCellSize() const { return mCellSize; }

        void worldPosToImageSpace(float x, float z, float& imageX, float& imageY);

        void cellTopLeftCornerToImageSpace(int x, int y, float& imageX, float& imageY);

        void exploreCell (int cellX, int cellY);

        virtual void loadResource(Ogre::Resource* resource);

        /// Clears the overlay
        void clear();

        void write (ESM::GlobalMap& map);
        void read (ESM::GlobalMap& map);

    private:
        std::string mCacheDir;

        int mCellSize;

        std::vector< std::pair<int,int> > mExploredCells;

        Ogre::TexturePtr mOverlayTexture;
        Ogre::Image mOverlayImage; // Backup in system memory

        int mWidth;
        int mHeight;

        int mMinX, mMaxX, mMinY, mMaxY;
    };

}

#endif

