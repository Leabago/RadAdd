#ifndef BASSPLAY_H
#define BASSPLAY_H

#include "bass/bass.h"
#include <QThread>
#include <QDebug>

class BassPlay : public QThread
{
    Q_OBJECT

private:
    HSTREAM *stream;
    QString url = "";
public:

    QString getUrl(){ return url;}

    void setUrl(const QString &url) {
          this->url = url;
    }
    void setStream(HSTREAM *stream) {
        this->stream = stream;
    }

    void run() override {
        BASS_ChannelStop(*stream);
          BASS_StreamFree(*stream);

        *stream = BASS_StreamCreateURL(url.toLatin1(), 0, 0, 0, 0);
          qDebug() << "stream ++++" << *stream ;
       BASS_ChannelPlay(*stream, false);
    }
};

#endif // BASSPLAY_H
