#include "dialog.h"
#include "ui_dialog.h"
#include "intro.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    intro game(ui);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lineEdit_returnPressed()
{

}
