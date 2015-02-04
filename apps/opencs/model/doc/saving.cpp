
#include "../world/data.hpp"
#include "../world/idcollection.hpp"
#include "apps/opencs/model/doc/../world/record.hpp"
#include "apps/opencs/model/doc/../world/scope.hpp"
#include "apps/opencs/model/doc/operation.hpp"
#include "components/esm/debugprofile.hpp"
#include "components/esm/filter.hpp"
#include "components/esm/loadbody.hpp"
#include "components/esm/loadbsgn.hpp"
#include "components/esm/loadclas.hpp"
#include "components/esm/loadench.hpp"
#include "components/esm/loadfact.hpp"
#include "components/esm/loadglob.hpp"
#include "components/esm/loadgmst.hpp"
#include "components/esm/loadmgef.hpp"
#include "components/esm/loadrace.hpp"
#include "components/esm/loadregn.hpp"
#include "components/esm/loadscpt.hpp"
#include "components/esm/loadskil.hpp"
#include "components/esm/loadsndg.hpp"
#include "components/esm/loadsoun.hpp"
#include "components/esm/loadspel.hpp"
#include "components/to_utf8/to_utf8.hpp"
#include "document.hpp"
#include "saving.hpp"
#include "savingstages.hpp"
#include "state.hpp"

CSMDoc::Saving::Saving (Document& document, const boost::filesystem::path& projectPath,
    ToUTF8::FromType encoding)
: Operation (State_Saving, true, true), mDocument (document), mState (*this, projectPath, encoding)
{
    // save project file
    appendStage (new OpenSaveStage (mDocument, mState, true));

    appendStage (new WriteHeaderStage (mDocument, mState, true));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::Filter> > (
        mDocument.getData().getFilters(), mState, CSMWorld::Scope_Project));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::DebugProfile> > (
        mDocument.getData().getDebugProfiles(), mState, CSMWorld::Scope_Project));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::Script> > (
        mDocument.getData().getScripts(), mState, CSMWorld::Scope_Project));

    appendStage (new CloseSaveStage (mState));

    // save content file
    appendStage (new OpenSaveStage (mDocument, mState, false));

    appendStage (new WriteHeaderStage (mDocument, mState, false));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::Global> >
        (mDocument.getData().getGlobals(), mState));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::GameSetting> >
        (mDocument.getData().getGmsts(), mState));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::Skill> >
        (mDocument.getData().getSkills(), mState));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::Class> >
        (mDocument.getData().getClasses(), mState));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::Faction> >
        (mDocument.getData().getFactions(), mState));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::Race> >
        (mDocument.getData().getRaces(), mState));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::Sound> >
        (mDocument.getData().getSounds(), mState));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::Script> >
        (mDocument.getData().getScripts(), mState));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::Region> >
        (mDocument.getData().getRegions(), mState));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::BirthSign> >
        (mDocument.getData().getBirthsigns(), mState));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::Spell> >
        (mDocument.getData().getSpells(), mState));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::Enchantment> >
        (mDocument.getData().getEnchantments(), mState));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::BodyPart> >
        (mDocument.getData().getBodyParts(), mState));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::SoundGenerator> >
        (mDocument.getData().getSoundGens(), mState));

    appendStage (new WriteCollectionStage<CSMWorld::IdCollection<ESM::MagicEffect> >
        (mDocument.getData().getMagicEffects(), mState));

    appendStage (new WriteDialogueCollectionStage (mDocument, mState, false));

    appendStage (new WriteDialogueCollectionStage (mDocument, mState, true));

    appendStage (new WriteRefIdCollectionStage (mDocument, mState));

    appendStage (new CollectionReferencesStage (mDocument, mState));

    appendStage (new WriteCellCollectionStage (mDocument, mState));

    appendStage (new WritePathgridCollectionStage (mDocument, mState));

    // close file and clean up
    appendStage (new CloseSaveStage (mState));

    appendStage (new FinalSavingStage (mDocument, mState));
}
