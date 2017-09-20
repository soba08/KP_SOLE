#ifndef QUIZSCREEN_H
#define QUIZSCREEN_H

#include <QDialog>

namespace Ui {
class QuizScreen;
}

class QuizScreen : public QDialog
{
    Q_OBJECT

public:
    explicit QuizScreen(QWidget *parent = 0);
    ~QuizScreen();
    void closeModal();

private:
    Ui::QuizScreen *ui;
};

#endif // QUIZSCREEN_H
