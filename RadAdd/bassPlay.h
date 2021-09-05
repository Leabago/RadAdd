#ifndef BASSPLAY_H
#define BASSPLAY_H

#include "bass/bass.h"
#include <QThread>
#include <QDebug>

class BassPlay : public QThread
{
    Q_OBJECT

private:
    HSTREAM* stream;
    QString url = "";
public:

    HSTREAM* getStream(){
        qDebug() << "getStream "  << *stream;
        return stream;
    }

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
       BASS_ChannelPlay(*stream, false);
         qDebug() << "stream ++++" << *stream ;
           qDebug() << "stream ---" << *stream ;
//         streamState = *stream ;

     emit resultReady(*stream );
    }

signals:
    void resultReady(const HSTREAM &s);

};

#endif // BASSPLAY_H
