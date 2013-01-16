#include "intro.h"
#include "ui_dialog.h"
#include "dun1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>

intro::intro(Ui::Dialog*& ui)
{
    ui->label->setText(readFile(ui));
    while(true)
    {
        if(ui->lineEdit->text() == "1"){
            dun1 gameNew(ui);
        }else
            ui->label->setText(readFile(ui));
    }
}

QString intro::readFile(Ui::Dialog *&ui)
{
    QFile file(":/intro.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::information(0, "ERROR", "CANNOT OPEN FILE");
        return "";
    }

    QTextStream in(&file);
    QString line = in.readAll();
    file.close();
    return line;

}
