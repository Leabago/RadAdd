#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <radiomodel.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

class Controller : public QObject
{
    Q_OBJECT

    QSqlDatabase db ;
    QList<QString> genre;

    bool getTrue = true;

public:
    RadioModel stations;
    RadioModel favorite;
    QHash<QString, Radio*> favoriteHash;
    RadioModel my;

    ~Controller(){};
    Controller(QObject* parent = 0)  ;

    int createDateBase();
    int inserDBinRadio(const QString &link, const QString &name, const QString &icon,const int &listening, const QList<QString> genre);
    int insertList(const QString &link, const QString &name, const QString &image, const int &listening, const QList<QString> genre);

    int insert(const QString &link, const QString &name, const QString &image, const int &listening, const QList<QString> genre);
    int inserDBinGenre(const QString genre);

    int readDB();


public slots:
    void removeFromFavoriteByIndex(int index)
    {
        stations.removeByIndex(index);
    }

     bool favoriteLinkExist(const QString link);

signals:
    void sentToQml();

//    void sentToQmlFavorite(bool exist);
};



#endif // CONTROLLER_H
