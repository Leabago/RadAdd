#include "radio.h"

Radio::Radio(QObject *parent)
    :QObject(parent)
{
    connect(this, SIGNAL(nameChanged()), this, SLOT(nameChangedSlot()));
}

Radio:: Radio(const QString &link, const QString &name,  const QString &icon, const  unsigned int& listening,  const QList<QString> &genre, QObject *parent )
    :QObject(parent), m_link(link), m_name(name), m_icon(icon), m_listening(listening), m_genre(genre)
{
    connect(this, SIGNAL(nameChanged()), this, SLOT(nameChangedSlot()));
}


QString Radio::link() const{
    return m_link;
}

QString Radio::name() const {
    return m_name;
}

QString Radio::icon() const {
    return m_icon;
}
QList<QString> Radio::genre() const{
    return m_genre;
}

unsigned int Radio::listening() const
{
    return m_listening;
}

bool Radio::favorite() const
{
    return m_favorite;
}


void Radio::setLink(const QString &link){
    if(m_link != link ){
        m_link = link;
        emit linkChanged();
    }
}

void Radio::setName(const QString& name){
    if(name != m_name){
        m_name = name;
        emit nameChanged();
    }
}


void Radio::setIcon(const QString &icon)
{
    if (m_icon != icon)
    {
        m_icon = icon;
        emit iconChanged();
    }
}

void  Radio::setListening(const unsigned   int& listening)
{
    if (m_listening != listening)
    {
        m_listening = listening;
        emit listeningChanged();
    }
}

void Radio::setGenre(const QList<QString> &genre)
{
    if (m_genre != genre)
    {
        m_genre = genre;
        emit genreChanged();
    }
}

void Radio::setFavorite(const bool &favorite)
{
    if ( m_favorite != favorite  )
    {
        m_favorite = favorite ;
        emit favoriteChanged();
    }
}


