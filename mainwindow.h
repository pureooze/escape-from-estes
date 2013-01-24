#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QMap>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT
    
public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
        void setupStateMachine();
        void readSQL();

signals:
        void one();
        void two();
        void three();
        void four();

private slots:
        void someSlot();

private:
        Ui::MainWindow *ui;
        QString readFile(QString file);
        QMap <int, QList<int> > tiles;
        int tile;
};

#endif // MAINWINDOW_H
