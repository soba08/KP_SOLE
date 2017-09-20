#ifndef SUBJECT_H
#define SUBJECT_H

#include <QDialog>
#include <QVector>

namespace Ui {
class Subject;
}

class Subject : public QDialog
{
    Q_OBJECT

public:
    explicit Subject(QWidget *parent = 0);
    ~Subject();
     QVector<int> choices;

private slots:
    void on_submitChoice_clicked();

private:
    Ui::Subject *ui;
};

#endif // SUBJECT_H
