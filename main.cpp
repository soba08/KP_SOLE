#include "mainwindow.h"
#include <QApplication>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QLineEdit l;
//    l.setEchoMode(QLineEdit::Password);
//    l.show();
    MainWindow w;

    w.show();

    return a.exec();
}
