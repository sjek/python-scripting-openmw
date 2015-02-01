#ifndef ADDPROPERTYDIALOG_H
#define ADDPROPERTYDIALOG_H

#include <qdialog.h>
#include <qobjectdefs.h>
#include <qstring.h>
#include <QDialog>

class QWidget;

namespace Ui {
class AddPropertyDialog;
}

class AddPropertyDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddPropertyDialog(QWidget *parent = 0);
    ~AddPropertyDialog();

	int mType;
	QString mName;

public slots:
	void accepted();
	void rejected();
    
private:
    Ui::AddPropertyDialog *ui;
};

#endif // ADDPROPERTYDIALOG_H
