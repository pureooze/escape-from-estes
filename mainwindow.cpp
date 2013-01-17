#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QState>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QStateMachine>
#include <QFinalState>
#include <QWidget>
#include <QLineEdit>
#include <QDebug>
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupStateMachine();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupStateMachine()
{
    QStateMachine *machine = new QStateMachine(this);
    QState *s1 = new QState();
    QState *s2 = new QState();
    QState *s3 = new QState();

    s1->assignProperty(ui->label, "text", readFile("intro.txt"));
    s2->assignProperty(ui->label, "text", "In state s2");
    s3->assignProperty(ui->label, "text", "In state s3");

    s1->addTransition(this->ui->pushButton, SIGNAL(clicked()), s2);
    s2->addTransition(this->ui->pushButton, SIGNAL(clicked()), s3);
    s3->addTransition(this->ui->pushButton, SIGNAL(clicked()), s1);

    machine->addState(s1);
    machine->addState(s2);
    machine->addState(s3);
    machine->setInitialState(s1);

    machine->start();

    qDebug() << "State Machine Created";
}

QString MainWindow::readFile(QString data)
{
    QFile file(":/" + data);
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::information(0, "ERROR", "CANNOT OPEN FILE");
        return "";
    }

    QTextStream in(&file);
    QString line = in.readAll();
    file.close();
    return line;

}