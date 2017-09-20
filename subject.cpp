#include "subject.h"
#include "ui_subject.h"
#define ENGLISH_CHOICE 1
#define SCIENCE_CHOICE 2
#define MATH_CHOICE 3
#define GEOGRAPHY_CHOICE 4
#include "videoplay.h"

Subject::Subject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Subject)
{
    ui->setupUi(this);
}

Subject::~Subject()
{
    delete ui;
}

void Subject::on_submitChoice_clicked()
{
    VideoPlay vid;
    this->close();
    if(ui->eng->isChecked()){
        // English is checked
   choices.append(ENGLISH_CHOICE);
    vid.playVideo(ENGLISH_CHOICE);

    }else if(ui->sci->isChecked()){
        choices.append(SCIENCE_CHOICE);
        vid.playVideo(SCIENCE_CHOICE);
    } else if(ui->mat->isChecked()){
        choices.append(MATH_CHOICE);
        vid.playVideo(MATH_CHOICE);
    }else if(ui->geo->isChecked()){
        choices.append(GEOGRAPHY_CHOICE);
        vid.playVideo(GEOGRAPHY_CHOICE);
    }else if(ui->rnd->isChecked()){
      int rndChoice = qrand() % ((4 + 1) - 1) + 1;
      if(rndChoice == 1){
          choices.append(ENGLISH_CHOICE);
           vid.playVideo(ENGLISH_CHOICE);
      }else if(rndChoice == 2){
          choices.append(SCIENCE_CHOICE);
          vid.playVideo(SCIENCE_CHOICE);
      }else if(rndChoice == 3){
          choices.append(MATH_CHOICE);
          vid.playVideo(MATH_CHOICE);
      }else {
          choices.append(GEOGRAPHY_CHOICE);
          vid.playVideo(GEOGRAPHY_CHOICE);
      }

    }





}
