#include "registration.h"
#include "ui_registration.h"
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "dialog.h"
#define STUDENT_LOGIN "STUDENT";
#define TEACHER_LOGIN "TEACHER";
#define GUEST_LOGIN "GUEST";

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
     ui->errorMsg->hide();
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_pushButton_clicked()
{
    this->close();
    Dialog dia;
    dia.setFixedHeight(1500);
    dia.setFixedWidth(1500);
    dia.setModal(true);
    dia.exec();

}

void Registration::on_pushButton_2_clicked()
{
    qDebug()<<"Register was clicked:::";

    //-----------------------------GETTING VALUES FROM UI--------------------------------------//
    int value =0;
    QString username=ui->userName->text();
    qDebug()<<"The value of username is ::"<<username;
    QString password=ui->passWord->text();
    qDebug()<<"The value of password is ::"<<password;
    QString reType=ui->reTypePwd->text();
    qDebug()<<"The value of reType password  is ::"<<reType;
    QString loginType="";
    if(ui->loginType->isChecked()){
        // Student
        loginType=STUDENT_LOGIN;
         value =1;
        qDebug()<<"Student clicked"<<value;
    }else if(ui->loginType_2->isChecked()){
        // teacher
        loginType=TEACHER_LOGIN;
        value =2;
       qDebug()<<"Teacher clicked"<<value;
    }else if(ui->loginType_3->isChecked()){
        // Guest
        loginType=GUEST_LOGIN;
        value =3;
       qDebug()<<"Guest clicked"<<value;
    }
//----------------------------VALIDATION START------------------------------------------------------//
    // validation if password and re type password are same

    bool valPassed=true;
    QString errorString="";

    if(password.size() == 0){
            valPassed=false;
            errorString="Password field is empty.";
    }else if(QString::compare(password,reType,Qt::CaseSensitive) != 0){
        valPassed=false;
        errorString="Passwords don't match.";
    }else if(value == 0){
        valPassed=false;
        errorString="Please choose Login Type";
    }else if(username.size() == 0){
        valPassed=false;
        errorString="Please enter username";
    }

  //--------------------------END OF VALIDATION---------------------------------------------------------//
    if(valPassed){
        // Then the strings are matched
        ui->errorMsg->setText("");
        ui->errorMsg->hide();
        qDebug()<<"Passwords match";

        // Proceed on with DB Insertion
       Dialog dial;
       QSqlDatabase db=dial.connect_to_DB();
           bool ok=db.open();
        if(ok){
            QSqlQuery insertQuery;

                   insertQuery.prepare("insert into \"KP_LOGIN\" VALUES (:user,:pass,:type)");
                   insertQuery.bindValue(":user",username);
                   insertQuery.bindValue(":pass",password);
                   insertQuery.bindValue(":type",loginType);

                   if(insertQuery.exec()){
                       // Records should be inserted...
                       qDebug()<<"records are inserted:::";
                   }else{
                       qDebug()<<"Error with the query due to :::"<<db.lastError().text();
                   }
        }else{

        }

    }else{
        // set error message
        ui->errorMsg->show();
        ui->errorMsg->setText(errorString);
    }

}
