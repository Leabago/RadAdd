#include "controller.h"

Controller::Controller(BassController &_bassController,QObject * parent)
    : QObject(parent)
{
     this->bassController = &_bassController;
    QObject::connect(bassController, SIGNAL(*bassController->bassPlay.resultReady),
            this, SLOT(setValue)
            );



    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("RadioDB");

    if( !db.open() ) {
        qDebug() << "DataBaseController " <<  db.lastError().text();
        qDebug() << "can not opened" ;
    } else   qDebug() << "opened DB" ;
}

const QString createRadio = "CREATE TABLE IF NOT EXISTS radio ("
                "link TEXT NOT NULL PRIMARY KEY,"
                "name TEXT NOT NULL,"
                "icon TEXT,"
                "listening_hours INTEGER NOT NULL"
                ")";

const QString createRadioFavorite = "CREATE TABLE  IF NOT EXISTS favorite"
                "("
                "link TEXT,"
                "FOREIGN KEY(link) REFERENCES radio(link),"
                "PRIMARY KEY (link)"
                ")";

const QString createRadioMy = "CREATE TABLE IF NOT EXISTS my ("
                "link TEXT NOT NULL PRIMARY KEY,"
                "name TEXT NOT NULL,"
                "icon TEXT"
                ")";

const QString insertRadio =
        "INSERT INTO radio (link, name, icon, listening_hours) "
"SELECT * FROM (SELECT :link, :name, :icon, :listening_hours) AS tmp "
"WHERE NOT EXISTS ( "
"SELECT link FROM radio WHERE link = :link "
") LIMIT 1; ";

const QString insertMyRadio =
        "INSERT INTO my (link, name, icon) "
"SELECT * FROM (SELECT :link, :name, :icon) AS tmp "
"WHERE NOT EXISTS ( "
"SELECT link FROM radio WHERE link = :link "
") LIMIT 1; ";

const QString insertFavorite =
        "INSERT INTO favorite (link) "
"SELECT * FROM (SELECT :link) AS tmp "
"WHERE NOT EXISTS ( "
"SELECT * FROM favorite WHERE link = :link "
") LIMIT 1";

const QString deleteFavorite =
        "DELETE FROM favorite "
"WHERE link = :link ";


int Controller::createDateBase()
{
    qDebug() << "createDateBase" ;

    QSqlQuery query( db );
    if( !query.exec( createRadio)) {
        qDebug() << "Error CREATE TABLE radio " << db.lastError().text();
        return 1;
    }   qDebug() << "CREATE TABLE IF NOT EXISTS radio" ;


    if( !query.exec(createRadioFavorite)) {
        qDebug() << "Error CREATE TABLE  IF NOT EXISTS favorite " << db.lastError().text();
        return 1;
    } qDebug() <<  "CREATE TABLE  IF NOT EXISTS favorite" ;

    if( !query.exec(createRadioMy)) {
        qDebug() << "Error CREATE TABLE  IF NOT EXISTS my " << db.lastError().text();
        return 1;
    } qDebug() <<  "CREATE TABLE  IF NOT EXISTS my";

    insert("http://ic4.101.ru:8000/region_avto_237" , "name1", "icon1", 0);
    insert("http://air.radiorecord.ru:8101/rr_320" , "name2", "icon2", 0);
    insert("http://air.radiorecord.ru:8102/sd90_320" , "name3", "icon3", 0);
    insert("link4" , "name4", "icon4", 0);

    return 0;
}

int Controller::readDB()
{
    QSqlQuery query( db );

    //    read all rows from favorite
    if( !query.exec("SELECT * FROM favorite")){
        qDebug() << "read DB favorite" << db.lastError().text();
        //        return 1;
    }
    QSqlRecord record = query.record();
    //    favoriteSet - set with rows from favorite
    QSet<QString> favoriteSet;

    while (query.next() ) {
        const int link = record.indexOf("link");
        QString linkStr = query.value(link).toString();
        favoriteSet.insert(linkStr);
    }
    record.clear();

    //    read all radiostations
    qDebug() << "read all radiostations";
    if( !query.exec("SELECT * FROM radio")){
        qDebug() << "read DB radio" << db.lastError().text();
        //        return 1;
    }
    record = query.record();
    while (query.next() ) {
        const int linkR = record.indexOf("link");
        const int nameR = record.indexOf("name");
        const int iconR = record.indexOf("icon");
        const int listening_hoursR = record.indexOf("listening_hours");

        QString link_str = query.value(linkR).toString();
        qDebug() << "read link_str" << link_str ;

        Radio *newRadio = new Radio(query.value(linkR).toString(),
                                    query.value(nameR).toString(),
                                    query.value(iconR).toString(),
                                    query.value(listening_hoursR).toInt());

        if (favoriteSet.contains(link_str))
        {
            newRadio->setFavorite(true);
            favorite.addRadio( newRadio);
            favoriteHash.insert(link_str, newRadio);
        }

        stationsHash.insert(newRadio->link(), newRadio);
        stations.addRadio( newRadio  );

        my.addRadio(newRadio);
    }
    record.clear();


    //    read all my radiostation
    qDebug() << "read all my radiostation";
    if( !query.exec("SELECT * FROM my")){
        qDebug() << "read DB my" << db.lastError().text();
        //        return 1;
    }
    record = query.record();
    while (query.next() ) {
        const int linkR = record.indexOf("link");
        const int nameR = record.indexOf("name");
        const int iconR = record.indexOf("icon");

        QString link_str = query.value(linkR).toString();
        qDebug() << link_str ;

        Radio *newRadio = new Radio(query.value(linkR).toString(),
                                    query.value(nameR).toString(),
                                    query.value(iconR).toString(),
                                    0);

        myHash.insert(newRadio->link(), newRadio);
        my.addRadio( newRadio  );
    }

    //    qDebug() << "allRadiosHash check point stations";

    //    for (int i = 0; i < stations.getModelData().size(); ++i  )
    //    {
    //        qDebug() <<  stations.getModelData()[i]->link() << "|"  << stations.getModelData()[i];
    //    }
    //    qDebug() << "allRadiosHash check point favorite";
    //    for (int i = 0; i < favorite.getModelData().size(); ++i  )
    //    {
    //        qDebug() <<  favorite.getModelData()[i]->link() << "|"  << favorite.getModelData()[i];
    //    }
    return 0;
}

//bool Controller::favoriteLinkExist(const QString link )
//{
//    //    emit sentToQmlFavorite(favoriteHash.contains(link));
//    return favoriteHash.contains(link);
//}

int Controller::inserDBinRadio(const QString &link, const QString &name, const QString &icon, const int &listening_hours)
{
    QSqlQuery query(db);
    query.prepare(
                insertRadio
                );
    query.bindValue( ":link", link );
    query.bindValue( ":name", name );
    query.bindValue( ":icon",  icon);
    query.bindValue( ":listening_hours",  listening_hours);
    if( !query.exec() ) {
        qDebug() << "insertInto radio " << db.lastError().text();
        return -1;
    }
    return 0;
}

int Controller::insertList(const QString &link, const QString &name, const QString &icon, const int &listening_hours)
{
    Radio *rad =  new Radio(link, name, icon, listening_hours);
    stations.addRadio( rad);
    return 0;
}

int Controller::insert(const QString &link, const QString &name, const QString &icon, const int &listening_hours)
{
    inserDBinRadio(link, name, icon, listening_hours);
    return 0;
}

void Controller::addToFavoite(const QString &link){
    if (stationsHash.contains(link))
    {
        if (addToFavoriteDB(link))
        {
            Radio *addToFavorite = stationsHash[link];
            addToFavorite->setFavorite(true);
            favorite.addRadio(addToFavorite);
            favoriteHash.insert(link, addToFavorite);
            emit sentToQml();
        }
        emit sentToQml();
    }
}

bool Controller::addToFavoriteDB(const QString &link)
{
    QSqlQuery query(db);
    query.prepare(insertFavorite);
    query.bindValue( ":link", link );

    if( !query.exec() ) {
        qDebug() << "insertInto favorite " << db.lastError().text();
        return false;
    } else return true;
}

void Controller::removeFromFavorite(const  QString &link)
{
    if (favoriteHash.contains(link))
    {
        qDebug() <<  "contain";
        if (  removeFromFavoriteDB(link) )
        {
            Radio *removeFromFavorite = favoriteHash[link];
            removeFromFavorite->setFavorite(false);
            favorite.removeRadio(removeFromFavorite);
            favoriteHash.remove(link);
            emit sentToQml();
        }
    } else  qDebug() <<  "does no contain";
    qDebug() <<  "| removeFromFavorite " ;
}

bool Controller::removeFromFavoriteDB(const  QString &link)
{
    QSqlQuery query(db);
    query.prepare(deleteFavorite);
    query.bindValue( ":link", link );

    if( !query.exec() ) {
        qDebug() << "delete favorite " << db.lastError().text();
        return false;
    } else return true;
}


void Controller::addMyRadio(const QString &link, const QString &name, const QString &icon)
{
            Radio *newRadio = new Radio(link, name, icon, 10);
            my.addRadio(newRadio);

    qDebug() << "addMyRadio"  +  newRadio->link();
////    if (addMyRadioDB(link, name, icon))
//     if (true)
//    {
//        Radio *newRadio = new Radio(link, name, icon, 0);
//        my.addRadio(newRadio);
////        myHash.insert(newRadio->link(), newRadio);
//         qDebug() << "addMyRadio added" ;
//    }
}

bool Controller::addMyRadioDB(const QString &link, const QString &name, const QString &icon)
{
     qDebug() << "addMyRadioDB" ;
    QSqlQuery query(db);
    query.prepare(
                insertMyRadio
                );
    query.bindValue( ":link", link );
    query.bindValue( ":name", name );
    query.bindValue( ":icon",  icon);
    if(!query.exec() ) {
        qDebug() << "insertInto radio " << db.lastError().text();
         return false;
    } else {
        qDebug() << "addMyRadioDB added" ;
        return true;
    }
}

void Controller::addMyRadioTest()
{
    Radio *newRadio = new Radio("SAd",
                                "query.value(nameR).toString()",
                                "query.value(iconR).toString()",
                                0);


    test.addRadio( newRadio  );
    qDebug() << "test";
}



















bool   sortlistening_hours(const Radio &left, const Radio &right)
{
    return (left.listeningHours() >  right.listeningHours()) ;
}


bool   sort2(  const Radio *left,  const Radio *right)
{
    //     qDebug() <<  QString::compare( left.name(), right.name());
    qDebug() <<  left->name() << "|" <<   right->name() ;
    qDebug() <<  left->listeningHours() << "|" <<   right->listeningHours() ;
    qDebug() << (left->listeningHours() <  right->listeningHours() ) ;

    return (left->listeningHours() >  right->listeningHours() );

    //       int asd =(left.name() >  right.name() ) ;
    //       if (asd > 0) return true;
    //       else return false;
}

int Controller::sortList(){
    qDebug() << "Sort" ;


    //  for (int i = 0; i < stations.getModelData().size(); ++i)
    //  {

    //  }
    // Radio *rad = stations.m_radios[0] ;
    // stations.m_radios[0] =  stations.m_radios[1];
    //  stations.m_radios[1] = rad;

    QList<int> asd;

    QList<Radio*> *fieldsList = stations.getModelDataLink();

    //  Radio *rad = fieldsList->at(0);
    //   Radio *rad = stations.m_radios[0] ;
    //   stations.m_radios[0] =  stations.m_radios[1];
    //    stations.m_radios[1] = rad;
    //     stations.m_radios[2] =  stations.m_radios[3];

    //  const  QList<Radio*>::iterator left = stations.m_radios.begin();
    //      Radio *rad =  *stations.m_radios.begin();

    //   const  QList<Radio*>::iterator &right = stations.m_radios.end();

    //     qDebug() << "left" <<   (*&*right)->listening_hours() << "|";


    std::vector<Radio*> vec;

    for ( int i = 0; i < stations.m_radios.size(); ++i)
    {
        qDebug() << "|" << stations.m_radios[i]->listeningHours() ;
        vec.push_back( stations.m_radios[i]);
    }

    //    std::sort(vec.begin(), vec.end(),  sort2 );

    std::sort(stations.m_radios.begin(), stations.m_radios.end(),   sort2 );

    qDebug() << "sort";

    for ( int i = 0; i < vec.size(); ++i)
    {
        qDebug() << "|" << vec[i]->listeningHours() ;
    }

    return 0;
}

bool   Controller::variantLessThan(const Radio &left, const Radio &right)
{
    return left.listeningHours() <  right.listeningHours() ;
}




