#ifndef NEWMATERIALDIALOG_HPP
#define NEWMATERIALDIALOG_HPP

#include <qdialog.h>
#include <qobjectdefs.h>
#include <QDialog>

class QWidget;

namespace Ui {
class NewMaterialDialog;
}

class NewMaterialDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewMaterialDialog(QWidget *parent = 0);
    ~NewMaterialDialog();
    
private:
    Ui::NewMaterialDialog *ui;
};

#endif // NEWMATERIALDIALOG_HPP
