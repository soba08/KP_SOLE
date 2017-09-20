#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql/QSqlDatabase>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
     QSqlDatabase connect_to_DB();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    QString login(QString name,QString pass);



private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
