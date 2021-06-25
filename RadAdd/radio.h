#ifndef RADIO_H
#define RADIO_H

#include <QObject>
#include <QList>

class Radio: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString link READ link WRITE setLink NOTIFY linkChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(unsigned int listening READ listening WRITE setListening NOTIFY listeningChanged)
    Q_PROPERTY(QList<QString> genre READ genre WRITE setGenre NOTIFY genreChanged)

public:
    QString m_link;
    QString m_name;
    QString m_icon;
    unsigned int m_listening; // in minutes
    QList<QString> m_genre;


public:
    Radio(QObject *paren = 0);
    Radio(const QString &link, const QString &name,  const QString &icon, const  unsigned int& listening, const QList<QString> &genre,  QObject *parent = 0);

    QString link() const;
    QString name() const;
    QString icon() const;
    unsigned int listening() const ;
    QList<QString> genre() const;

    void setLink(const QString& link);
    void setName(const QString& name);
    void setIcon(const QString& icon);
    void setListening(const unsigned int& listening);
    void setGenre(const QList<QString> &genre);

    QString toString()  {
        QString toString = "[" ;
        toString += "link:" + link() + "\n";
        toString += "name:" + name() + "\n";
        toString += "icon:" + icon() + "\n";
        toString += "listening:" +    QString::number(listening())+ "\n" ;
        toString += "genre [" ;
        for (int i = 0; i < m_genre.size()-1; ++i)
            toString += " " + m_genre[i] + ",";
        toString += " " + m_genre[m_genre.size()-1] + " ]\n";

        return   toString  ;
    }

signals:
    void linkChanged();
    void nameChanged();
    void iconChanged();
    void listeningChanged();
    void genreChanged();
};

#endif // RADIO_H
