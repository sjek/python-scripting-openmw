#include <components/esm/esmreader.hpp>
#include <ostream>

#include "components/esm/loadltex.hpp"
#include "landtexture.hpp"

namespace CSMWorld
{

    void LandTexture::load(ESM::ESMReader &esm)
    {
        ESM::LandTexture::load(esm);

        int plugin = esm.getIndex();

        std::ostringstream stream;

        stream << mIndex << "_" << plugin;

        mId = stream.str();
    }

}
