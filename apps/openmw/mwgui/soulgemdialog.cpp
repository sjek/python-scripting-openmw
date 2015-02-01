#include <string>
#include <vector>

#include "../mwbase/environment.hpp"
#include "../mwbase/windowmanager.hpp"
#include "MyGUI_DelegateImplement.h"
#include "apps/openmw/mwgui/../mwbase/../mwgui/mode.hpp"
#include "apps/openmw/mwgui/../mwworld/ptr.hpp"
#include "messagebox.hpp"
#include "soulgemdialog.hpp"

namespace MWGui
{

    void SoulgemDialog::show(const MWWorld::Ptr &soulgem)
    {
        mSoulgem = soulgem;
        std::vector<std::string> buttons;
        buttons.push_back("#{sRechargeEnchantment}");
        buttons.push_back("#{sMake Enchantment}");
        mManager->createInteractiveMessageBox("#{sDoYouWantTo}", buttons);
        mManager->eventButtonPressed += MyGUI::newDelegate(this, &SoulgemDialog::onButtonPressed);
    }

    void SoulgemDialog::onButtonPressed(int button)
    {
        if (button == 0)
        {
            MWBase::Environment::get().getWindowManager()->pushGuiMode(GM_Recharge);
            MWBase::Environment::get().getWindowManager()->startRecharge(mSoulgem);
        }
        else
        {
            MWBase::Environment::get().getWindowManager()->pushGuiMode(GM_Enchanting);
            MWBase::Environment::get().getWindowManager()->startSelfEnchanting(mSoulgem);
        }
    }

}
