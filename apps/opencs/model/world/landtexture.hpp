#ifndef CSM_WORLD_LANDTEXTURE_H
#define CSM_WORLD_LANDTEXTURE_H

#include <components/esm/loadltex.hpp>
#include <string>

namespace ESM {
class ESMReader;
}  // namespace ESM

namespace CSMWorld
{
    /// \brief Wrapper for LandTexture record. Encodes mIndex and the plugin index (obtained from ESMReader)
    /// in the ID.
    ///
    /// \attention The mId field of the ESM::LandTexture struct is not used.
    struct LandTexture : public ESM::LandTexture
    {
        std::string mId;

        void load (ESM::ESMReader &esm);
    };
}

#endif
