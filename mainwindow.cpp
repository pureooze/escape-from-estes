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
#include <QtSql/QtSql>
#include <QList>
#include <QMap>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
        ui->setupUi(this);

        // slot that is used to determine what the user typed in and if it is a valid command
        connect(ui->lineEdit, SIGNAL(editingFinished()), this, SLOT(someSlot()));

        // sets up the state machine so that later in the program, we just have to move between states
        // instead of having to figure out what to do every time
        setupStateMachine();

        // load data from the SQL database, this is mostly information that is easier to manage in
        // SQL. Things like adjacent tiles to every tile, tile/room descriptions and so on.
        readSQL();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupStateMachine()
{
        // set title bar text
        this->setWindowTitle(QString("Excape From Estes"));

        // create the state machine object and its states
        QStateMachine *machine = new QStateMachine(this);
        QState *s1 = new QState();
        QState *s2 = new QState();
        QState *s3 = new QState();

        // assign an event for every state
        s1->assignProperty(ui->label, "text", readFile("intro.txt"));
        s2->assignProperty(ui->label, "text", "In state s2");
        s3->assignProperty(ui->label, "text", "In state s3");

        // set up a trigger to end every state
        s1->addTransition(this, SIGNAL(one()), s2);
        s2->addTransition(this, SIGNAL(two()), s3);
        s3->addTransition(this->ui->pushButton, SIGNAL(clicked()), s1);

        // add the states to the state machine and set a starting state
        machine->addState(s1);
        machine->addState(s2);
        machine->addState(s3);
        machine->setInitialState(s1);

        // enable the machine and print out a message to show that we are done
        machine->start();
        qDebug() << "State Machine Created";
}

QString MainWindow::readFile(QString data)
{
        // create a file object that is associated with the file data
        QFile file(":/" + data);

        // attempt to read the file, to prevent any errors that may occur, return a blank string and
        // display an error message to indicate that something went wrong
        if(!file.open(QFile::ReadOnly | QFile::Text)){
                QMessageBox::information(0, "ERROR", "CANNOT OPEN FILE");
                return "";
        }

        // Everything has gone fine, read the file and store it in the string line
        QTextStream in(&file);
        QString line = in.readAll();
        file.close();
        return line;

}

void MainWindow::readSQL()
{
        // create a database object, give it the appropriate location and password
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setDatabaseName("gameData");
        db.setUserName("root");
        db.setPassword("inane");

        // atempt to open the database
        bool ok = db.open();

        if(ok){
                // if the database opens properly, read it for the data we need
                QSqlQuery query("SELECT * FROM gameData.new_table");
                QList<int> data;
                int id;
                while(query.next()){
                        // loop through every element in the table
                        id = query.value(0).toInt();
                        for(int i=1; i<=query.size(); i++){
                                // make a list for the values in the 2nd to 5th column of the table
                                data.append(query.value(i).toInt());
                        }
                        // insert the id,data as a key,value pair into the map tiles, then clear data
                        // so that we can use it again
                        this->tiles.insert(id, data);
                        data.clear();
                }
                this->tile = 1;
                qDebug() << this->tile;
                return;
        }else
                // if there is an error, display an error message and close the program
                qDebug() << "ERROR: " << db.lastError();
                this->close();
                exit(0);
}

void MainWindow::someSlot()
{
        if((ui->lineEdit->text() == "move north") && (this->tiles.value(1).value(0) == 1)){
                qDebug() << "north";
                emit one();
        }else if((ui->lineEdit->text() == "move east") && (this->tiles.value(1).value(1) == 1)){
                qDebug() << "east";
                emit two();
        }else if((ui->lineEdit->text() == "move south") && (this->tiles.value(1).value(2) == 1)){
                qDebug() << "south";
                emit three();
        }else if((ui->lineEdit->text() == "move west") && (this->tiles.value(1).value(3) == 1)){
                qDebug() << "west";
                emit four();
        }else
                qDebug() << "ERROR: INVALID COMMAND";
}
