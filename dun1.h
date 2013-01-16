#ifndef DUN1_H
#define DUN1_H
#include "dialog.h"
#include "ui_dialog.h"
#include <QDialog>

class dun1
{
    public:
        dun1(Ui::Dialog*&);
        void textPlace(int mag);
        QString readFile(Ui::Dialog*& ui);
    protected:
    private:
};

#endif // DUN1_H
