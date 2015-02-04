
#include <components/compiler/locals.hpp>
#include <components/esm/loaddial.hpp>

#include "../mwbase/environment.hpp"
#include "../mwbase/scriptmanager.hpp"
#include "../mwbase/world.hpp"
#include "../mwworld/class.hpp"
#include "../mwworld/esmstore.hpp"
#include "../mwworld/ptr.hpp"
#include "apps/openmw/mwscript/../mwworld/store.hpp"
#include "compilercontext.hpp"
#include "components/esm/loadacti.hpp"
#include "components/esm/loadalch.hpp"
#include "components/esm/loadappa.hpp"
#include "components/esm/loadarmo.hpp"
#include "components/esm/loadbook.hpp"
#include "components/esm/loadclot.hpp"
#include "components/esm/loadcont.hpp"
#include "components/esm/loadcrea.hpp"
#include "components/esm/loaddoor.hpp"
#include "components/esm/loadingr.hpp"
#include "components/esm/loadlevlist.hpp"
#include "components/esm/loadligh.hpp"
#include "components/esm/loadlock.hpp"
#include "components/esm/loadmisc.hpp"
#include "components/esm/loadnpc.hpp"
#include "components/esm/loadprob.hpp"
#include "components/esm/loadrepa.hpp"
#include "components/esm/loadscpt.hpp"
#include "components/esm/loadstat.hpp"
#include "components/esm/loadweap.hpp"
#include "components/misc/stringops.hpp"

namespace MWScript
{
    CompilerContext::CompilerContext (Type type)
    : mType (type)
    {}

    bool CompilerContext::canDeclareLocals() const
    {
        return mType==Type_Full;
    }

    char CompilerContext::getGlobalType (const std::string& name) const
    {
        return MWBase::Environment::get().getWorld()->getGlobalVariableType (name);
    }

    std::pair<char, bool> CompilerContext::getMemberType (const std::string& name,
        const std::string& id) const
    {
        std::string script;
        bool reference = false;

        if (const ESM::Script *scriptRecord =
            MWBase::Environment::get().getWorld()->getStore().get<ESM::Script>().search (id))
        {
            script = scriptRecord->mId;
        }
        else
        {
            MWWorld::Ptr ptr = MWBase::Environment::get().getWorld()->getPtr (id, false);

            script = ptr.getClass().getScript (ptr);
            reference = true;
        }

        char type = ' ';

        if (!script.empty())
            type = MWBase::Environment::get().getScriptManager()->getLocals (script).getType (
                Misc::StringUtils::lowerCase (name));

        return std::make_pair (type, reference);
    }

    bool CompilerContext::isId (const std::string& name) const
    {
        const MWWorld::ESMStore &store =
            MWBase::Environment::get().getWorld()->getStore();

        return
            store.get<ESM::Activator>().search (name) ||
            store.get<ESM::Potion>().search (name) ||
            store.get<ESM::Apparatus>().search (name) ||
            store.get<ESM::Armor>().search (name) ||
            store.get<ESM::Book>().search (name) ||
            store.get<ESM::Clothing>().search (name) ||
            store.get<ESM::Container>().search (name) ||
            store.get<ESM::Creature>().search (name) ||
            store.get<ESM::Door>().search (name) ||
            store.get<ESM::Ingredient>().search (name) ||
            store.get<ESM::CreatureLevList>().search (name) ||
            store.get<ESM::ItemLevList>().search (name) ||
            store.get<ESM::Light>().search (name) ||
            store.get<ESM::Lockpick>().search (name) ||
            store.get<ESM::Miscellaneous>().search (name) ||
            store.get<ESM::NPC>().search (name) ||
            store.get<ESM::Probe>().search (name) ||
            store.get<ESM::Repair>().search (name) ||
            store.get<ESM::Static>().search (name) ||
            store.get<ESM::Weapon>().search (name);
    }

    bool CompilerContext::isJournalId (const std::string& name) const
    {
        const MWWorld::ESMStore &store =
            MWBase::Environment::get().getWorld()->getStore();

        const ESM::Dialogue *topic = store.get<ESM::Dialogue>().search (name);

        return topic && topic->mType==ESM::Dialogue::Journal;
    }
}
