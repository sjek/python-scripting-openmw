
#include <components/esm/objectstate.hpp>
#include <exception>
#include <iostream>

#include "../mwbase/environment.hpp"
#include "../mwbase/world.hpp"
#include "apps/openmw/mwworld/../mwscript/locals.hpp"
#include "apps/openmw/mwworld/cellref.hpp"
#include "apps/openmw/mwworld/refdata.hpp"
#include "apps/openmw/mwworld/store.hpp"
#include "class.hpp"
#include "components/esm/loadscpt.hpp"
#include "esmstore.hpp"
#include "livecellref.hpp"
#include "ptr.hpp"

MWWorld::LiveCellRefBase::LiveCellRefBase(std::string type, const ESM::CellRef &cref)
  : mClass(&Class::get(type)), mRef(cref), mData(cref)
{
}

void MWWorld::LiveCellRefBase::loadImp (const ESM::ObjectState& state)
{
    mRef = state.mRef;
    mData = RefData (state);

    Ptr ptr (this);

    if (state.mHasLocals)
    {
        std::string scriptId = mClass->getScript (ptr);
        // Make sure we still have a script. It could have been coming from a content file that is no longer active.
        if (!scriptId.empty())
        {
            if (const ESM::Script* script = MWBase::Environment::get().getWorld()->getStore().get<ESM::Script>().search (scriptId))
            {
                try
                {
                    mData.setLocals (*script);
                    mData.getLocals().read (state.mLocals, scriptId);
                }
                catch (const std::exception& exception)
                {
                    std::cerr
                        << "failed to load state for local script " << scriptId
                        << " because an exception has been thrown: " << exception.what()
                        << std::endl;
                }
            }
        }
    }

    mClass->readAdditionalState (ptr, state);
}

void MWWorld::LiveCellRefBase::saveImp (ESM::ObjectState& state) const
{
    mRef.writeState(state);

    /// \todo get rid of this cast once const-correct Ptr are available
    Ptr ptr (const_cast<LiveCellRefBase *> (this));

    mData.write (state, mClass->getScript (ptr));

    mClass->writeAdditionalState (ptr, state);
}

bool MWWorld::LiveCellRefBase::checkStateImp (const ESM::ObjectState& state)
{
    return true;
}
