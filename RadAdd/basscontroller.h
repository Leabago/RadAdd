#ifndef BASSCONTROLLER_H
#define BASSCONTROLLER_H

#include <QObject>
#include "bassPlay.h"
#include <QDebug>
#include <QTimer>

class BassController  : public QObject
{
    Q_OBJECT
    BassPlay bassPlay;
    QTimer *timer ;

    bool check = true;
    bool timerStart = false;

public:
    HSTREAM stream;

    explicit BassController(QObject *parent = 0);

public slots:

    void play(const QString &currentRadioUrl);
    void pasue();
    void stop();
    void metadata();
    void freeStream();

    int initBass();

signals:
    void sendToQmlCurrSong(QString currSong);
};

#endif // BASSCONTROLLER_H
