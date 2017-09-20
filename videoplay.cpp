#include "videoplay.h"
#include "ui_videoplay.h"
#define SUBTEXT1 "Story Time....Learn  "
#define SUBTEXT2 "the fun way"
#define ENGLISH "English "
#define SCIENCE "Science "
#define MATH "Math "
#define GEOGRAPHY "Geography "
#include <QDebug>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QGraphicsVideoItem>
#include "subject.h"
#include <QFileInfo>
#include "quizscreen.h"




VideoPlay::VideoPlay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VideoPlay)
{
    ui->setupUi(this);
    ui->subMsg->hide();
    ui->subName->hide();
    this->setFixedHeight(1500);
    this->setFixedWidth(1500);


}

VideoPlay::~VideoPlay()
{
    delete ui;
}
void VideoPlay::playVideo(int subId)
{
    QString chosenFileName="";
    QString convMsg="";
    lastChoice=subId;
    if(subId == 1)
    {
        // English
        ui->subMsg->show();
        std::string msg=std::string(SUBTEXT1)+std::string(ENGLISH)+std::string(SUBTEXT2);
        convMsg=QString::fromUtf8(msg.c_str());

        qDebug()<<"msg is :::"<<convMsg;
        ui->subMsg->setText(convMsg);
        ui->subName->show();
        ui->subName->setText(ENGLISH);
        chosenFileName="./resources/videos/Quad Crew Intro 10 sec.mp4";
//
    }else if(subId == 2){
        // Science
        ui->subMsg->show();
        //ui->subMsg->setText(SUBTEXT1+SCIENCE+SUBTEXT2);
        std::string msg=std::string(SUBTEXT1)+std::string(SCIENCE)+std::string(SUBTEXT2);
        convMsg=QString::fromUtf8(msg.c_str());
        ui->subMsg->setText(convMsg);
        ui->subName->show();
        ui->subName->setText(SCIENCE);
        chosenFileName="./resources/videos/GB 10sec video.mp4";
    } else if(subId == 3){
        // Math
        ui->subMsg->show();
        //ui->subMsg->setText(SUBTEXT1+MATH+SUBTEXT2);
        std::string msg=std::string(SUBTEXT1)+std::string(MATH)+std::string(SUBTEXT2);
        convMsg=QString::fromUtf8(msg.c_str());
        ui->subMsg->setText(convMsg);
        ui->subName->show();
        ui->subName->setText(MATH);
        chosenFileName="./resources/videos/The funniest 10 second video ever.mp4";
    } else if(subId == 4){
        // Geography
        ui->subMsg->show();
        //ui->subMsg->setText(SUBTEXT1+GEOGRAPHY+SUBTEXT2);
        std::string msg=std::string(SUBTEXT1)+std::string(GEOGRAPHY)+std::string(SUBTEXT2);
        convMsg=QString::fromUtf8(msg.c_str());
        ui->subMsg->setText(convMsg);
        ui->subName->show();
        ui->subName->setText(GEOGRAPHY);
        chosenFileName="./resources/videos/DigitalMedia 10sec video.mp4";
    }

//-------------------------------------CREATE A VIDEO PLAYER AND RENDER CONTENT BASED ON FILE NAME-----------------------------------------//
    QVBoxLayout *layout = new QVBoxLayout;

        layout->addWidget(ui->videoWidget);
        setLayout(layout);



            //ui->videoWidget->setStyleSheet("background: transparent");


        player = new QMediaPlayer();
        item = new QGraphicsVideoItem;
        scene = new QGraphicsScene;
       // item->setSize(QSize(ui->videoWidget->width(),ui->videoWidget->height()));
//        qreal x=130;
//        item->setX(x);
//        item->setY(x);
        ui->videoWidget->setScene(scene);

        player->setVideoOutput(item);
        qDebug() << ui->videoWidget->width();
        qDebug() << ui->videoWidget->height();
        ui->videoWidget->scene()->addItem(item);
        lastPlayedFileName=chosenFileName;
        player->setMedia(QUrl::fromLocalFile(QFileInfo(chosenFileName).absoluteFilePath()));
        player->play();
        ui->videoWidget->show();
       this->setFixedHeight(1500);
       this->setFixedWidth(1500);
        this->setModal(true);
        this->exec();

}









void VideoPlay::on_lastVideo_clicked()
{
    //playVideo(lastChoice);
    player->play();

}

void VideoPlay::on_subjectScreen_clicked()
{
    this->close();
    Subject sub;
    sub.setFixedHeight(1500);
    sub.setFixedWidth(1500);
    sub.setModal(true);
    sub.exec();

}

void VideoPlay::on_quizScreen_clicked()
{
    this->close();
    QuizScreen qz;
    qz.closeModal();
}
