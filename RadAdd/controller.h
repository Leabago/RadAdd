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
#include <myobject.h>

class Controller : public QObject
{
    Q_OBJECT

    QSqlDatabase db ;

    bool getTrue = true;

public:
    QList<QString> genre;
    RadioModel stations;
    RadioModel favorite;
    RadioModel my;
    QHash<QString, Radio*> stationsHash;
    QHash<QString, Radio*> favoriteHash;
    QHash<QString, Radio*> myHash;
    //    QHash<QString, TestObject*> sfHash;

    QList<QObject*> stationsSet ;
    //     QList<QObject*> favoriteSetObj ;
    QQmlContext *context ;

    //     TestObject test ;
    MyModel *genreAll;
    MyModel *genreToAdd;


    TwoModels *twoModel;

    ~Controller(){};
    Controller(QObject* parent = 0)  ;

    int createDateBase();
    int inserDBinRadio(const QString &link, const QString &name, const QString &icon,const int &listening, const QList<QString> genre);
    int insertList(const QString &link, const QString &name, const QString &image, const int &listening, const QList<QString> genre);

    int insert(const QString &link, const QString &name, const QString &image, const int &listening, const QList<QString> genre);
    int inserDBinGenre(const QString genre);

    int readDB();
    int sortList();

    bool    variantLessThan(const Radio &left, const Radio &right);


public slots:
    void removeFromFavoriteByIndex(int index)
    {
        stations.removeByIndex(index);
    }

    bool favoriteLinkExist(const QString link);
    //     void addToFavoite(const QVariant& var);
    void addToFavoite(const QString &radioId);
    bool addToFavoriteDB(const QString &radioId);
    void removeFromFavorite(const  QString &radioId);
    bool removeFromFavoriteDB(const  QString &radioId);


    void addName(const QString &link, const QString &val)
    {
        if ( stationsHash.contains(link))
        {
            Radio *radio = stationsHash[link];
            radio->setName(radio->name() + "A");
            qDebug() << "addName ";
            qDebug() << radio->name();
        }
    }

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


    QString getName(const QString &link)
    {
        if (stationsHash.contains(link) )
            return stationsHash[link]->name();
    }

    //    void testFav(const QString &link, bool val)
    //    {
    //        if ( sfHash.contains(link))
    //        {
    //           TestObject *testObj = sfHash[link];
    //            testObj->setFavorite(val);
    //            qDebug() << "testFav ";
    //              qDebug() <<  testObj->favorite();
    //        }
    //    }

    //    TestObject* getTestObject(const QString &link)
    //    {
    //        if (sfHash.contains(link))
    //        {
    //            return  sfHash[link];
    //        }
    //    }



    //    void testPop()
    //    {
    //        myModel.addMyObject(MyObject("text3"));
    //        qDebug() << " listMy.size();" << myModel.m_data.size();
    //    }

    void prepearGenre()
    {
        //        qDebug() << " prepearGenre()";
        //        genreAll = new MyModel;
        //        genreToAdd = new MyModel;
    }

    MyModel* getGenreAll()
    {
        return  twoModel->getAllGenre();
    }

    QList<QString> getGenreToAdd()
    {
        QList<QString> qList;
        qList.push_back("1");
        qList.push_back("2");
        qList.push_back("3");
        qList.push_back("4");
        return  genre;
    }

signals:
    void sentToQml();

    //    void sentToQmlFavorite(bool exist);
};



#endif // CONTROLLER_H
