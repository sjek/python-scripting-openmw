#include <MyGUI_InputManager.h>
#include <boost/format/alt_sstream.hpp>
#include <boost/format/alt_sstream_impl.hpp>
#include <boost/format/format_class.hpp>
#include <boost/format/format_fwd.hpp>
#include <boost/format/format_implementation.hpp>
#include <boost/format/free_funcs.hpp>
#include <boost/optional/optional.hpp>
#include <stddef.h>
#include <ostream>
#include <stdexcept>
#include <utility>
#include <vector>

#include "../mwbase/environment.hpp"
#include "../mwbase/windowmanager.hpp"
#include "../mwbase/world.hpp"
#include "../mwmechanics/creaturestats.hpp"
#include "../mwmechanics/spellcasting.hpp"
#include "../mwmechanics/spells.hpp"
#include "../mwworld/class.hpp"
#include "../mwworld/esmstore.hpp"
#include "../mwworld/inventorystore.hpp"
#include "MyGUI_DelegateImplement.h"
#include "MyGUI_RTTI.h"
#include "MyGUI_Widget.h"
#include "apps/openmw/mwgui/../mwbase/../mwgui/mode.hpp"
#include "apps/openmw/mwgui/../mwworld/containerstore.hpp"
#include "apps/openmw/mwgui/../mwworld/ptr.hpp"
#include "apps/openmw/mwgui/../mwworld/store.hpp"
#include "apps/openmw/mwgui/spellmodel.hpp"
#include "apps/openmw/mwgui/windowpinnablebase.hpp"
#include "components/esm/loadspel.hpp"
#include "confirmationdialog.hpp"
#include "inventorywindow.hpp"
#include "spellicons.hpp"
#include "spellview.hpp"
#include "spellwindow.hpp"

namespace MWGui {
class DragAndDrop;
}  // namespace MWGui

namespace MWGui
{

    SpellWindow::SpellWindow(DragAndDrop* drag)
        : WindowPinnableBase("openmw_spell_window.layout")
        , NoDrop(drag, mMainWidget)
        , mSpellView(NULL)
    {
        mSpellIcons = new SpellIcons();

        getWidget(mSpellView, "SpellView");
        getWidget(mEffectBox, "EffectsBox");

        mSpellView->eventSpellClicked += MyGUI::newDelegate(this, &SpellWindow::onModelIndexSelected);

        setCoord(498, 300, 302, 300);
    }

    SpellWindow::~SpellWindow()
    {
        delete mSpellIcons;
    }

    void SpellWindow::onPinToggled()
    {
        MWBase::Environment::get().getWindowManager()->setSpellVisibility(!mPinned);
    }

    void SpellWindow::onTitleDoubleClicked()
    {
        if (!mPinned)
            MWBase::Environment::get().getWindowManager()->toggleVisible(GW_Magic);
    }

    void SpellWindow::open()
    {
        updateSpells();
    }

    void SpellWindow::updateSpells()
    {
        mSpellIcons->updateWidgets(mEffectBox, false);

        mSpellView->setModel(new SpellModel(MWBase::Environment::get().getWorld()->getPlayerPtr()));
        mSpellView->update();
    }

    void SpellWindow::onEnchantedItemSelected(MWWorld::Ptr item, bool alreadyEquipped)
    {
        MWWorld::Ptr player = MWBase::Environment::get().getWorld()->getPlayerPtr();
        MWWorld::InventoryStore& store = player.getClass().getInventoryStore(player);

        // retrieve ContainerStoreIterator to the item
        MWWorld::ContainerStoreIterator it = store.begin();
        for (; it != store.end(); ++it)
        {
            if (*it == item)
            {
                break;
            }
        }
        if (it == store.end())
            throw std::runtime_error("can't find selected item");

        // equip, if it can be equipped and is not already equipped
        if (!alreadyEquipped
            && !item.getClass().getEquipmentSlots(item).first.empty())
        {
            MWBase::Environment::get().getWindowManager()->getInventoryWindow()->useItem(item);
            // make sure that item was successfully equipped
            if (!store.isEquipped(item))
                return;
        }

        MWBase::Environment::get().getWindowManager()->unsetSelectedSpell();
        store.setSelectedEnchantItem(it);

        updateSpells();
    }

    void SpellWindow::onModelIndexSelected(SpellModel::ModelIndex index)
    {
        const Spell& spell = mSpellView->getModel()->getItem(index);
        if (spell.mType == Spell::Type_EnchantedItem)
        {
            onEnchantedItemSelected(spell.mItem, spell.mActive);
        }
        else
        {
            onSpellSelected(spell.mId);
        }
    }

    void SpellWindow::onSpellSelected(const std::string& spellId)
    {
        if (MyGUI::InputManager::getInstance().isShiftPressed())
        {
            // delete spell, if allowed
            const ESM::Spell* spell =
                MWBase::Environment::get().getWorld()->getStore().get<ESM::Spell>().find(spellId);

            if (spell->mData.mFlags & ESM::Spell::F_Always
                || spell->mData.mType == ESM::Spell::ST_Power)
            {
                MWBase::Environment::get().getWindowManager()->messageBox("#{sDeleteSpellError}");
            }
            else
            {
                // ask for confirmation
                mSpellToDelete = spellId;
                ConfirmationDialog* dialog = MWBase::Environment::get().getWindowManager()->getConfirmationDialog();
                std::string question = MWBase::Environment::get().getWindowManager()->getGameSettingString("sQuestionDeleteSpell", "Delete %s?");
                question = boost::str(boost::format(question) % spell->mName);
                dialog->open(question);
                dialog->eventOkClicked.clear();
                dialog->eventOkClicked += MyGUI::newDelegate(this, &SpellWindow::onDeleteSpellAccept);
                dialog->eventCancelClicked.clear();
            }
        }
        else
        {
            MWWorld::Ptr player = MWBase::Environment::get().getWorld()->getPlayerPtr();
            MWWorld::InventoryStore& store = player.getClass().getInventoryStore(player);
            store.setSelectedEnchantItem(store.end());
            MWBase::Environment::get().getWindowManager()->setSelectedSpell(spellId, int(MWMechanics::getSpellSuccessChance(spellId, player)));
        }

        updateSpells();
    }

    void SpellWindow::onDeleteSpellAccept()
    {
        MWWorld::Ptr player = MWBase::Environment::get().getWorld()->getPlayerPtr();
        MWMechanics::CreatureStats& stats = player.getClass().getCreatureStats(player);
        MWMechanics::Spells& spells = stats.getSpells();

        if (MWBase::Environment::get().getWindowManager()->getSelectedSpell() == mSpellToDelete)
            MWBase::Environment::get().getWindowManager()->unsetSelectedSpell();

        spells.remove(mSpellToDelete);

        updateSpells();
    }

    void SpellWindow::cycle(bool next)
    {
        mSpellView->setModel(new SpellModel(MWBase::Environment::get().getWorld()->getPlayerPtr()));
        mSpellView->getModel()->update();

        SpellModel::ModelIndex selected = 0;
        for (SpellModel::ModelIndex i = 0; i<int(mSpellView->getModel()->getItemCount()); ++i)
        {
            if (mSpellView->getModel()->getItem(i).mSelected)
                selected = i;
        }

        selected += next ? 1 : -1;
        int itemcount = mSpellView->getModel()->getItemCount();
        if (itemcount == 0)
            return;
        selected = (selected + itemcount) % itemcount;

        onModelIndexSelected(selected);
    }
}
