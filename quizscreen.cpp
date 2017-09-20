#include "quizscreen.h"
#include "ui_quizscreen.h"
#include <QTimer>
#include <QDebug>

QuizScreen::QuizScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuizScreen)
{
    ui->setupUi(this);
}

QuizScreen::~QuizScreen()
{
    delete ui;
}

void QuizScreen::closeModal(){
    this->setFixedHeight(1500);
    this->setFixedWidth(1500);
    this->setModal(true);
    this->exec();

}


