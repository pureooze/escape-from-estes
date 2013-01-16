#include "dun1.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>

dun1::dun1(Ui::Dialog*& ui)
{
    ui->label->setText(readFile(ui));
//    while(ui->label->text() != '1' || ui->label->text() != '2')
//    {
//        if(ui->label->text() == '1'){

//        }else if (ui->label->text() == '2') {
//            ui->label->setText("You go back to sleep. Suddenly, you feel a blade touch you on the throat, but before you"
//                               " can react, it's too late. You have died.\n\nGAME OVER");
//        }
//    }

//    switch(a){
//        case '1':
//            break;
//        case '2':
//            std::cout << "You go back to sleep. Suddenly, you feel a blade touch you on the throat, but before you" <<
//                          " can react, it's too late. You have died.\n\nGAME OVER";
//            textPlace(17);
//            exit(0);
//            break;
//        default:
//            std::cout << "ERROR: SWITCHCASE ON DEFAULT CASE [LINE 39]\n" << a;
//            exit(0);
//    }

}

QString dun1::readFile(Ui::Dialog *&ui)
{
    QFile file(":/1.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::information(0, "ERROR", "CANNOT OPEN FILE");
        return "";
    }

    QTextStream in(&file);
    QString line = in.readAll();
    file.close();
    return line;

}
