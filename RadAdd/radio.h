#ifndef RADIO_H
#define RADIO_H

#include <QObject>
#include <QList>
#include <QDebug>

class Radio: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString link READ link WRITE setLink NOTIFY linkChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(unsigned int listeningHours READ listeningHours WRITE setlisteningHours NOTIFY listeningHoursChanged)
    Q_PROPERTY(bool favorite READ favorite WRITE setFavorite NOTIFY favoriteChanged)

public:
    QString m_link;
    QString m_name;
    QString m_icon;
    unsigned int m_listeningHours; // in minutes
    bool m_favorite  = false;


public:
    Radio(QObject *paren = 0);
    Radio(const QString &link, const QString &name,  const QString &icon, const  unsigned int& listeningHours, QObject *parent = 0);

    QString link() const;
    QString name() const;
    QString icon() const;
    unsigned int listeningHours() const ;
    bool favorite() const;

    void setLink(const QString& link);
    void setName(const QString& name);
    void setIcon(const QString& icon);
    void setlisteningHours(const unsigned int& listeningHours);
    void setFavorite(const bool &favorite);

    QString toString()  {
        QString toString = "[" ;
        toString += "link:" + link() + "\n";
        toString += "name:" + name() + "\n";
        toString += "icon:" + icon() + "\n";
        toString += "listeningHours:" +    QString::number(listeningHours())+ "\n" ;
        if (favorite())
            toString += "favorite: true\n";
        else  toString += "favorite: false\n";
        return   toString  ;
    }

    Radio& operator = (Radio right)
    {
        setLink(right.link());
        setName(right.name());
        setIcon(right.icon());
        setlisteningHours(right.listeningHours());
        setFavorite(right.favorite());
        return *this;
    }

public slots:
    void nameChangedSlot()
    {
        qDebug() << "nameChangedSlot name: " + name();
    }


signals:
    void linkChanged();
    void nameChanged();
    void iconChanged();
    void listeningHoursChanged();
    void favoriteChanged();
};



#endif // RADIO_H
