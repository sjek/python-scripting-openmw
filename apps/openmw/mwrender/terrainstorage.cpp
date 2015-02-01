#include <stddef.h>

#include "../mwbase/environment.hpp"
#include "../mwbase/world.hpp"
#include "../mwworld/esmstore.hpp"
#include "apps/openmw/mwrender/../mwbase/../mwworld/store.hpp"
#include "components/esm/loadcell.hpp"
#include "components/esm/loadland.hpp"
#include "components/esm/loadltex.hpp"
#include "terrainstorage.hpp"

namespace MWRender
{

    TerrainStorage::TerrainStorage(bool preload)
    {
        if (preload)
        {
            const MWWorld::ESMStore &esmStore =
                MWBase::Environment::get().getWorld()->getStore();

            MWWorld::Store<ESM::Land>::iterator it = esmStore.get<ESM::Land>().begin();
            for (; it != esmStore.get<ESM::Land>().end(); ++it)
            {
                ESM::Land* land = const_cast<ESM::Land*>(&*it); // TODO: fix store interface
                land->loadData(ESM::Land::DATA_VCLR|ESM::Land::DATA_VHGT|ESM::Land::DATA_VNML|ESM::Land::DATA_VTEX);
            }
        }
    }

    void TerrainStorage::getBounds(float& minX, float& maxX, float& minY, float& maxY)
    {
        minX = 0, minY = 0, maxX = 0, maxY = 0;

        const MWWorld::ESMStore &esmStore =
            MWBase::Environment::get().getWorld()->getStore();

        MWWorld::Store<ESM::Cell>::iterator it = esmStore.get<ESM::Cell>().extBegin();
        for (; it != esmStore.get<ESM::Cell>().extEnd(); ++it)
        {
            if (it->getGridX() < minX)
                minX = it->getGridX();
            if (it->getGridX() > maxX)
                maxX = it->getGridX();
            if (it->getGridY() < minY)
                minY = it->getGridY();
            if (it->getGridY() > maxY)
                maxY = it->getGridY();
        }

        // since grid coords are at cell origin, we need to add 1 cell
        maxX += 1;
        maxY += 1;
    }

    ESM::Land* TerrainStorage::getLand(int cellX, int cellY)
    {
        const MWWorld::ESMStore &esmStore =
            MWBase::Environment::get().getWorld()->getStore();
        ESM::Land* land = esmStore.get<ESM::Land>().search(cellX, cellY);
        if (!land)
            return NULL;

        const int flags = ESM::Land::DATA_VCLR|ESM::Land::DATA_VHGT|ESM::Land::DATA_VNML|ESM::Land::DATA_VTEX;
        if (!land->isDataLoaded(flags))
            land->loadData(flags);
        return land;
    }

    const ESM::LandTexture* TerrainStorage::getLandTexture(int index, short plugin)
    {
        const MWWorld::ESMStore &esmStore =
            MWBase::Environment::get().getWorld()->getStore();
        return esmStore.get<ESM::LandTexture>().find(index, plugin);
    }

}
