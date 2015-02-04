#ifndef IMPORTPAGE_HPP
#define IMPORTPAGE_HPP

#include <qobjectdefs.h>
#include <qwizard.h>
#include <QWizardPage>

#include "ui_importpage.h"

class QWidget;

namespace Wizard
{
    class MainWizard;

    class ImportPage : public QWizardPage, private Ui::ImportPage
    {
        Q_OBJECT
    public:
        ImportPage(QWidget *parent);

        int nextId() const;

    private:
        MainWizard *mWizard;

    };

}

#endif // IMPORTPAGE_HPP
