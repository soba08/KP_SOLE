#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    qDebug()<< "The submit button has been clicked";
    QString userName = ui->userName->text();
    qDebug()<<"The userName is :::"<<userName;

    QString password=ui->password->text();
    qDebug()<< "The password is :::"<<password;

    login(userName,password);


}

void MainWindow::connect_to_db(QString name,QString pass)
{
    // This is where i give my DB configurations ...

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("postgres");
    bool ok = db.open();


    if(ok){
        qDebug()<<"Connection Successfull";
        QSqlQuery query;
        QSqlQuery selectQuery;
        query.prepare("insert into \"KP_LOGIN\" VALUES (3,:user,:pass)");
        query.bindValue(":user",name);
        query.bindValue(":pass",pass);
        qDebug()<<"is the query valid"<<query.isValid();

        if(query.exec()){
            qDebug()<<"Hopefully data is inserted in the database....";
            if(selectQuery.exec("select \"KP_LOGIN_NAME\",\"KP_LOGIN_ID\" from \"KP_LOGIN\"")){
              qDebug()<<"Select has been processed successfully.";
            }else{
                qDebug()<<"Even select also not valid..."<<selectQuery.lastError();
            }
        }else{
//            qDebug()<<"Error happened"<<db.lastError().text();
              qDebug()<< "Something wrong with this ....Trying select query now...";


        }
        qDebug()<<"Closing connection....";
        db.close();
    }else{
        qDebug()<<"Connection failed";
//        qDebug()<<"Error happened"<<db.lastError().text();
    }



}

QString MainWindow::login(QString name,QString pass)
{
    // Call connect to DB
    qDebug()<<"username is "<<name<<"password is "<<pass;
              connect_to_db(name,pass);

    // use the string name and pass and check it in the query and return whether the condition is passed or not.

//    QSqlQuery query;
//    QSqlQuery selectQuery;


//    query.prepare("insert into KP_LOGIN VALUES (2,:user,:pass)");
//    query.bindValue(":user",name);
//    query.bindValue(":pass",pass);
//    query.exec();

//    selectQuery.exec("select KP_LOGIN_NAME,KP_LOGIN_ID from KP_LOGIN");



//          while (selectQuery.next()) {
//                      QString name = selectQuery.value(0).toString();
//                      int loginId = selectQuery.value(1).toInt();
//                      qDebug() << name << loginId;
//                  }


//    qDebug()<<"IS THIS EXECUTED ???"<<name<<pass;

    QString msg="connection is successfull";

return msg;

}

