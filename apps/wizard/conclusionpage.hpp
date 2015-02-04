#ifndef CONCLUSIONPAGE_HPP
#define CONCLUSIONPAGE_HPP

#include <qobjectdefs.h>
#include <qwizard.h>
#include <QWizardPage>

#include "ui_conclusionpage.h"

class QWidget;

namespace Wizard
{
    class MainWizard;

    class ConclusionPage : public QWizardPage, private Ui::ConclusionPage
    {
        Q_OBJECT
    public:
        ConclusionPage(QWidget *parent);

        int nextId() const;

    private:
        MainWizard *mWizard;

    protected:
        void initializePage();

    };

}

#endif // CONCLUSIONPAGE_HPP
