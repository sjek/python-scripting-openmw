#include "NewMaterialDialog.hpp"
#include "ui_newmaterialdialog.h"

class QWidget;

NewMaterialDialog::NewMaterialDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMaterialDialog)
{
    ui->setupUi(this);
}

NewMaterialDialog::~NewMaterialDialog()
{
    delete ui;
}
