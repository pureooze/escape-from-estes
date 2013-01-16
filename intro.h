#ifndef INTRO_H
#define INTRO_H
#include "dialog.h"
#include "ui_dialog.h"
#include <QDialog>

class intro
{
public:
    intro(Ui::Dialog*& ui);
    QString readFile(Ui::Dialog *&ui);
};

#endif // INTRO_H
