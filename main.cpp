#include "dialog.h"
#include <QApplication>
#include <QResource>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setFixedHeight(1500);
    w.setFixedWidth(1500);
    w.show();

    return a.exec();
}
