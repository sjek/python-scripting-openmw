#ifndef MWGUI_ALCHEMY_H
#define MWGUI_ALCHEMY_H

#include <memory>
#include <string>
#include <vector>

#include "apps/openmw/mwgui/../mwmechanics/alchemy.hpp"
#include "widgets.hpp"
#include "windowbase.hpp"

namespace MyGUI {
class Button;
class EditBox;
class Widget;
}  // namespace MyGUI

namespace MWMechanics
{
    class Alchemy;
}

namespace MWGui
{
    class ItemView;
    class ItemWidget;
    class SortFilterItemModel;

    class AlchemyWindow : public WindowBase
    {
    public:
        AlchemyWindow();

        virtual void open();
        virtual void exit();

    private:
        std::string mSuggestedPotionName;

        ItemView* mItemView;
        SortFilterItemModel* mSortModel;

        MyGUI::Button* mCreateButton;
        MyGUI::Button* mCancelButton;

        MyGUI::Widget* mEffectsBox;

        MyGUI::EditBox* mNameEdit;

        void onCancelButtonClicked(MyGUI::Widget* _sender);
        void onCreateButtonClicked(MyGUI::Widget* _sender);
        void onIngredientSelected(MyGUI::Widget* _sender);

        void onSelectedItem(int index);

        void removeIngredient(MyGUI::Widget* ingredient);

        void update();

        std::auto_ptr<MWMechanics::Alchemy> mAlchemy;

        std::vector<ItemWidget*> mApparatus;
        std::vector<ItemWidget*> mIngredients;
    };
}

#endif
