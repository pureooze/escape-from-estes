#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    QString readFile(Ui::Dialog *&ui);
    ~Dialog();
    
private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
