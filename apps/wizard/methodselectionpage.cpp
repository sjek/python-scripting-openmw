#include <qobject.h>
#include <qstring.h>
#include <qvariant.h>
#include <qwidget.h>

#include "mainwizard.hpp"
#include "methodselectionpage.hpp"

Wizard::MethodSelectionPage::MethodSelectionPage(QWidget *parent) :
    QWizardPage(parent)
{
    mWizard = qobject_cast<MainWizard*>(parent);

    setupUi(this);

#ifndef OPENMW_USE_UNSHIELD
    newLocationRadioButton->setEnabled(false);
    existingLocationRadioButton->setChecked(true);
#endif

    registerField(QLatin1String("installation.new"), newLocationRadioButton);
}

int Wizard::MethodSelectionPage::nextId() const
{
    if (field(QLatin1String("installation.new")).toBool() == true) {
        return MainWizard::Page_InstallationTarget;
    } else {
        return MainWizard::Page_ExistingInstallation;
    }
}
