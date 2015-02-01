#ifndef MWGUI_SPELLWINDOW_H
#define MWGUI_SPELLWINDOW_H

#include <string>

#include "../mwworld/ptr.hpp"
#include "apps/openmw/mwgui/windowbase.hpp"
#include "spellmodel.hpp"
#include "windowpinnablebase.hpp"

namespace MWGui {
class DragAndDrop;
}  // namespace MWGui
namespace MWWorld {
class Ptr;
}  // namespace MWWorld
namespace MyGUI {
class Widget;
}  // namespace MyGUI

namespace MWGui
{
    class SpellIcons;
    class SpellView;

    class SpellWindow : public WindowPinnableBase, public NoDrop
    {
    public:
        SpellWindow(DragAndDrop* drag);
        virtual ~SpellWindow();

        void updateSpells();

        void onFrame(float dt) { NoDrop::onFrame(dt); }

        /// Cycle to next/previous spell
        void cycle(bool next);

    protected:
        MyGUI::Widget* mEffectBox;

        std::string mSpellToDelete;

        void onEnchantedItemSelected(MWWorld::Ptr item, bool alreadyEquipped);
        void onSpellSelected(const std::string& spellId);
        void onModelIndexSelected(SpellModel::ModelIndex index);
        void onDeleteSpellAccept();

        virtual void onPinToggled();
        virtual void onTitleDoubleClicked();
        virtual void open();

        SpellView* mSpellView;
        SpellIcons* mSpellIcons;
    };
}

#endif
