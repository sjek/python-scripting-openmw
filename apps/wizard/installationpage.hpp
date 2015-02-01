#ifndef INSTALLATIONPAGE_HPP
#define INSTALLATIONPAGE_HPP

#include <qobjectdefs.h>
#include <qstring.h>
#include <qwizard.h>
#include <stdbool.h>
#include <QWizardPage>

#include "inisettings.hpp"
#include "ui_installationpage.h"
#include "unshield/unshieldworker.hpp"

class QThread;
class QWidget;

namespace Wizard
{
    class IniSettings;
    class MainWizard;
    class UnshieldWorker;

    class InstallationPage : public QWizardPage, private Ui::InstallationPage
    {
        Q_OBJECT
    public:
        InstallationPage(QWidget *parent);
        ~InstallationPage();

        int nextId() const;
         virtual bool isComplete() const;

    private:
        MainWizard *mWizard;
        bool mFinished;

        QThread* mThread;
        UnshieldWorker *mUnshield;

        void startInstallation();

    private slots:
        void showFileDialog(Wizard::Component component);

        void installationFinished();
        void installationError(const QString &text, const QString &details);

    protected:
        void initializePage();

    };

}

#endif // INSTALLATIONPAGE_HPP
