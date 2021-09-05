#include "basscontroller.h"

#include <QTimer>

BassController::BassController(QObject *parent)
    : QObject(parent)
{
    initBass();
    bassPlay.setStream(&stream);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &BassController::metadata);
}


void BassController::play(const QString &currentRadioUrl)
{
//    if (check)
//    {
//        bassPlay.setUrl(currentRadioUrl);
//        bassPlay.start();
//        metadata();

//        if (!timerStart)
//        {
//            timer->start(5000);
//            timerStart = true;
//        }
//    } else
//    {
//        BASS_ChannelPlay(stream, false);
//    }

//    check = false;
    if ( bassPlay.getUrl() !=  currentRadioUrl )
    {
        bassPlay.setUrl(currentRadioUrl);
        bassPlay.start();
        metadata();
    } else
    {
        BASS_ChannelPlay(stream, false);
    }

  stateStream = bassPlay.getStream();


    if (!timerStart)
    {
        timer->start(5000);
        timerStart = true;
    }
}

void BassController::pasue()
{
    BASS_ChannelPause(stream);

}

void BassController::stop()
{
    BASS_ChannelStop(stream);
}

void BassController::metadata()
{
    QString currSong ;
    QString meta = BASS_ChannelGetTags(stream, BASS_TAG_META);
    if (meta.size()) { // got Shoutcast metadata

        currSong =  meta.replace("StreamTitle='", "" ) ;
        currSong = currSong.replace( "';", "" );
    }
    emit sendToQmlCurrSong(currSong) ;
}


int BassController::initBass()
{
    if (HIWORD(BASS_GetVersion()) != BASSVERSION) {
        qDebug() << ("An incorrect version of BASS was loaded");
        return -1;
    }

    // initialize default output device
    if (!BASS_Init(-1, 44100, 0, NULL, NULL)) {
        qDebug() << ("Can't initialize device");
        return -2;
    }

    BASS_SetConfig(BASS_CONFIG_NET_PLAYLIST, 1); // enable playlist processing
    BASS_SetConfig(BASS_CONFIG_NET_PREBUF_WAIT, 0); // disable BASS_StreamCreateURL pre-buffering

    BASS_PluginLoad("libbass_aac.so", 0); // load BASS_AAC (if present) for AAC support
    BASS_PluginLoad("libbassflac.so", 0); // load BASSFLAC (if present) for FLAC support
    BASS_PluginLoad("libbasshls.so", 0); // load BASSHLS (if present) for HLS support

    return 0;
}

void BassController::freeStream(){
    BASS_StreamFree(stream); // close old stream
}


