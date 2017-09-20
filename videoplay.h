#ifndef VIDEOPLAY_H
#define VIDEOPLAY_H

#include <QDialog>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QGraphicsVideoItem>
#include <QGraphicsScene>

namespace Ui {
class VideoPlay;
}

class VideoPlay : public QDialog
{
    Q_OBJECT

public:
    explicit VideoPlay(QWidget *parent = 0);
    ~VideoPlay();
    void playVideo(int subId);
    QString lastPlayedFileName;
    int lastChoice;
    QMediaPlayer * player;
    QGraphicsVideoItem *item;
    QGraphicsScene * scene;


private slots:







    void on_lastVideo_clicked();

    void on_subjectScreen_clicked();

    void on_quizScreen_clicked();

private:
    Ui::VideoPlay *ui;
    QVBoxLayout *layout;
};

#endif // VIDEOPLAY_H
