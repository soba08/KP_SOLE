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

    ui->returnMsg->setText(login(userName,password));


}

QString MainWindow::login(QString name,QString pass)
{
    // This is where i give my DB configurations ...

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("postgres");
    bool ok = db.open();

    QString returnMsg="";

    if(ok){
        qDebug()<<"Connection Successfull";
//        QSqlQuery query;
//        QSqlQuery selectQuery;
//        query.prepare("insert into \"KP_LOGIN\" VALUES (3,:user,:pass)");
//        query.bindValue(":user",name);
//        query.bindValue(":pass",pass);
//        qDebug()<<"is the query valid"<<query.isValid();

//        if(query.exec()){
//            qDebug()<<"Hopefully data is inserted in the database....";
//            if(selectQuery.exec("select \"KP_LOGIN_NAME\",\"KP_LOGIN_ID\" from \"KP_LOGIN\"")){

//              qDebug()<<"Select has been processed successfully.";
//            }else{
//                qDebug()<<"Even select also not valid..."<<selectQuery.lastError();
//            }
//        }else{
////            qDebug()<<"Error happened"<<db.lastError().text();
//              qDebug()<< "Something wrong with this ....Trying select query now...";


//        }

        QSqlQuery loginQuery;

        loginQuery.prepare("select count(*) from \"KP_LOGIN\" where \"KP_LOGIN_NAME\"=:user AND \"KP_LOGIN_PASSWORD\"=:pass");
        loginQuery.bindValue(":user",name);
        loginQuery.bindValue(":pass",pass);

        if(loginQuery.exec()){
            // Access the results from my query.

                while(loginQuery.next()){
                    int result=loginQuery.value(0).toInt();

                    if(result == 1){
                        returnMsg="Logged in...";
                        qDebug()<<"Successfully logged in";
                    }else{
                        returnMsg="UserName or password doesn't match.";
                        qDebug()<<"UserName or password doesn't match.";
                    }
                }
        }else{
            qDebug()<<"Error while executing query due to :::"<<db.lastError().text();
        }



        qDebug()<<"Closing connection....";
        db.close();
    }else{
        qDebug()<<"Connection failed";
    }

return returnMsg;

}



