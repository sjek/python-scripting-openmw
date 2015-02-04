#ifndef METHODSELECTIONPAGE_HPP
#define METHODSELECTIONPAGE_HPP

#include <qobjectdefs.h>
#include <qwizard.h>
#include <QWizardPage>

#include "ui_methodselectionpage.h"

class QWidget;

namespace Wizard
{
    class MainWizard;

    class MethodSelectionPage : public QWizardPage, private Ui::MethodSelectionPage
    {
        Q_OBJECT
    public:
        MethodSelectionPage(QWidget *parent);

        int nextId() const;

    private:
        MainWizard *mWizard;

    };

}

#endif // METHODSELECTIONPAGE_HPP
