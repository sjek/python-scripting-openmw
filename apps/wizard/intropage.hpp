#ifndef INTROPAGE_HPP
#define INTROPAGE_HPP

#include <qobjectdefs.h>
#include <qwizard.h>
#include <QWizardPage>

#include "ui_intropage.h"

class QWidget;

namespace Wizard
{
    class MainWizard;

    class IntroPage : public QWizardPage, private Ui::IntroPage
    {
        Q_OBJECT
    public:
        IntroPage(QWidget *parent);

        int nextId() const;

    private:
        MainWizard *mWizard;
    };

}

#endif // INTROPAGE_HPP
