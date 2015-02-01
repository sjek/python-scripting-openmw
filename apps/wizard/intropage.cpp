#include <qobject.h>
#include <qpixmap.h>
#include <qstring.h>
#include <qwidget.h>

#include "intropage.hpp"
#include "mainwizard.hpp"

Wizard::IntroPage::IntroPage(QWidget *parent) :
    QWizardPage(parent)
{
    mWizard = qobject_cast<MainWizard*>(parent);

    setupUi(this);
    setPixmap(QWizard::WatermarkPixmap, QPixmap(QLatin1String(":/images/intropage-background.png")));
}

int Wizard::IntroPage::nextId() const
{
    return MainWizard::Page_MethodSelection;
}
