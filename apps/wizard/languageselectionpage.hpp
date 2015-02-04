#ifndef LANGUAGESELECTIONPAGE_HPP
#define LANGUAGESELECTIONPAGE_HPP

#include <qobjectdefs.h>
#include <qwizard.h>
#include <QWizardPage>

#include "ui_languageselectionpage.h"

class QWidget;

namespace Wizard
{
    class MainWizard;

    class LanguageSelectionPage : public QWizardPage, private Ui::LanguageSelectionPage
    {
        Q_OBJECT
    public:
        LanguageSelectionPage(QWidget *parent);

        int nextId() const;

    private:
        MainWizard *mWizard;

    protected:
        void initializePage();
    };
}

#endif // LANGUAGESELECTIONPAGE_HPP
