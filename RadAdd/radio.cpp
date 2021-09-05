#include "radio.h"

Radio::Radio(QObject *parent)
    :QObject(parent)
{
    connect(this, SIGNAL(nameChanged()), this, SLOT(nameChangedSlot()));
}

Radio:: Radio(const QString &link, const QString &name,  const QString &icon, const  unsigned int& listeningHours,  QObject *parent )
    :QObject(parent), m_link(link), m_name(name), m_icon(icon), m_listeningHours(listeningHours)
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


unsigned int Radio::listeningHours() const
{
    return m_listeningHours;
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

void  Radio::setlisteningHours(const unsigned   int& listeningHours)
{
    if (m_listeningHours != listeningHours)
    {
        m_listeningHours = listeningHours;
        emit listeningHoursChanged();
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


