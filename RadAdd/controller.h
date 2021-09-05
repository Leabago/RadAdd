#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <radiomodel.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QQmlContext>
#include <vector>
#include "testobject.h"
#include <basscontroller.h>

class Controller : public QObject
{
    Q_OBJECT

    QSqlDatabase db ;

    bool getTrue = true;

public:

    RadioModel stations;
    RadioModel favorite;
    RadioModel my;
    RadioModel test;
    QHash<QString, Radio*> stationsHash;
    QHash<QString, Radio*> favoriteHash;
    QHash<QString, Radio*> myHash;

    QQmlContext *context ;

     BassController *bassController;

    ~Controller(){};
    Controller(BassController &bassController, QObject* parent = 0)  ;

    int createDateBase();
    int inserDBinRadio(const QString &link, const QString &name, const QString &icon,const int &listeningHours);
    int insertList(const QString &link, const QString &name, const QString &image, const int &listeningHours);

    int insert(const QString &link, const QString &name, const QString &image, const int &listeningHours);

    int readDB();
    int sortList();

    bool    variantLessThan(const Radio &left, const Radio &right);




public slots:
    void removeFromFavoriteByIndex(int index)
    {
        stations.removeByIndex(index);
    }

//    bool favoriteLinkExist(const QString link);
    //     void addToFavoite(const QVariant& var);
    void addToFavoite(const QString &link);
    bool addToFavoriteDB(const QString &link);
    void removeFromFavorite(const  QString &link);
    bool removeFromFavoriteDB(const  QString &link);

    void addMyRadio(const QString &link, const QString &name, const QString &icon);
    bool addMyRadioDB(const QString &link, const QString &name, const QString &icon);

      void addMyRadioTest();

//    bool removeMyRadio(const QString &link, const QString &name);
//    bool removeRadioDB(const QString &link, const QString &name);



      void checkRadio( const QString &link, const QString &name, const QString &icon){
    bassController->play(link);
    qDebug() << "streamState = " << *bassController->stateStream ;
      }

      void setValue(const HSTREAM &s){
          qDebug() <<  "setValue setValue" ;
      }

//    void addName(const QString &link, const QString &val)
//    {
//        if ( stationsHash.contains(link))
//        {
//            Radio *radio = stationsHash[link];
//            radio->setName(radio->name() + "A");
//            qDebug() << "addName ";
//            qDebug() << radio->name();
//        }
//    }

    Radio* getRadio(const QString &link)
    {
        //        qDebug() << "getRadio" ;
        if (stationsHash.contains(link))
        {
            qDebug() << "contains "  << link ;
            return  stationsHash[link];
        }
        //        qDebug() << "not contains " << link ;
    }


//    QString getName(const QString &link)
//    {
//        if (stationsHash.contains(link) )
//            return stationsHash[link]->name();
//    }




signals:
    void sentToQml();

    //    void sentToQmlFavorite(bool exist);
};



#endif // CONTROLLER_H
