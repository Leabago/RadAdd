#include "controller.h"

Controller::Controller(QObject * parent)
    : QObject(parent)
{


//    listMy.push_back("text2");
    //    genre.push_back("Народная музыка");             //0
    //    genre.push_back("Духовная музыка");             //1
    //    genre.push_back("Академическая музыка");        //2
    //    genre.push_back("Фолк-музыка");                 //3
    //    genre.push_back("Кантри");                      //4
    //    genre.push_back("Латиноамериканская музыка");   //5
    //    genre.push_back("Блюз");                        //6
    //    genre.push_back("Ритм-н-блюз");                 //7
    //    genre.push_back("Джаз");                        //8
    //    genre.push_back("Шансон");                      //9
    //    genre.push_back("Электронная музыка");          //10
    //    genre.push_back("Рок");                         //11
    //    genre.push_back("Хип-хоп");                     //12
    //    genre.push_back("Регги");                       //13
    //    genre.push_back("Поп-музыка");                  //14
    //    genre.push_back("Аниме");                       //15
    //    genre.push_back("Смешанный стиль");             //16

    genre.push_back("Kek");             //0
    genre.push_back("Rock");             //1
    genre.push_back("Pusk");        //2
    genre.push_back("asd{");                 //3
    genre.push_back("asdd");                      //4
    genre.push_back("test123");

    twoModel = new TwoModels(genre);

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
                "listening INTEGER NOT NULL"
                ")";

const QString createGenre =  "create TABLE IF NOT EXISTS genre"
                "("
               "genre TEXT NOT NULL PRIMARY KEY"
                ")";

const QString createRadioGenre = "CREATE TABLE  IF NOT EXISTS radio_genre"
                "("
                "radioId TEXT,"
                "genreId TEXT,"
                "FOREIGN KEY(radioId) REFERENCES radio(link),"
                "FOREIGN KEY(genreId) REFERENCES genre(genre),"
                "PRIMARY KEY (radioId, genreId)"
                ")";

const QString createRadioFavorite = "CREATE TABLE  IF NOT EXISTS favorite"
                "("
                "radioId TEXT,"
                "FOREIGN KEY(radioId) REFERENCES radio(link),"
                "PRIMARY KEY (radioId)"
                ")";

const QString createRadioCustom = "CREATE TABLE  IF NOT EXISTS custom"
                "("
                "radioId TEXT,"
                "FOREIGN KEY(radioId) REFERENCES radio(link),"
                "PRIMARY KEY (radioId)"
                ")";

const QString insertGenre =
        "INSERT INTO genre(genre) "
"SELECT :genre "
"WHERE NOT EXISTS "
"(SELECT genre "
"FROM genre "
"WHERE genre = :genre) "
"LIMIT 1";

const QString insertRadio =
        "INSERT INTO radio (link, name, icon, listening) "
"SELECT * FROM (SELECT :link, :name, :icon, :listening) AS tmp "
"WHERE NOT EXISTS ( "
"SELECT link FROM radio WHERE link = :link "
") LIMIT 1; ";

const QString insertRadioGenre =
        "INSERT INTO radio_genre (radioId, genreId) "
"SELECT * FROM (SELECT :radioId, :genreId ) AS tmp "
"WHERE NOT EXISTS ( "
"SELECT * FROM radio_genre WHERE radioId = :radioId AND genreId = :genreId "
") LIMIT 1";

const QString insertFavorite =
        "INSERT INTO favorite (radioId) "
"SELECT * FROM (SELECT :radioId) AS tmp "
"WHERE NOT EXISTS ( "
"SELECT * FROM favorite WHERE radioId = :radioId "
") LIMIT 1";

const QString deleteFavorite =
"DELETE FROM favorite "
"WHERE radioId = :radioId ";


int Controller::createDateBase()
{
    qDebug() << "createDateBase" ;

    QSqlQuery query( db );
    if( !query.exec( createRadio)) {
        qDebug() << "Error CREATE TABLE radio " << db.lastError().text();
        return 1;
    }   qDebug() << "CREATE TABLE IF NOT EXISTS radio" ;

    if( !query.exec(createGenre)) {
        qDebug() << "Error create TABLE genre " << db.lastError().text();
        return 1;
    }  qDebug() << "create TABLE IF NOT EXISTS genre" ;

    if( !query.exec(createRadioGenre)) {
        qDebug() << "Error CREATE TABLE  IF NOT EXISTS radio_genre " << db.lastError().text();
        return 1;
    } qDebug() <<  "CREATE TABLE  IF NOT EXISTS radio_genre" ;

    if( !query.exec(createRadioFavorite)) {
        qDebug() << "Error CREATE TABLE  IF NOT EXISTS favorite " << db.lastError().text();
        return 1;
    } qDebug() <<  "CREATE TABLE  IF NOT EXISTS favorite" ;

    if( !query.exec(createRadioCustom)) {
        qDebug() << "Error CREATE TABLE  IF NOT EXISTS custom " << db.lastError().text();
        return 1;
    } qDebug() <<  "CREATE TABLE  IF NOT EXISTS custom" ;


    for (int i = 0; i < genre.size(); ++i)
    {
        inserDBinGenre(genre[i]);
    }

    QList<QString> newL;

    for (int i = 0; i < 3; ++i)
    {
        newL.push_back(genre[i]);
    }

    insert("http://ic4.101.ru:8000/region_avto_237" , "name1", "icon1", 0, newL);
    insert("http://air.radiorecord.ru:8101/rr_320" , "name2", "icon2", 0, newL);
    insert("http://air.radiorecord.ru:8102/sd90_320" , "name3", "icon3", 0, newL);
    insert("link4" , "name4", "icon4", 0, newL);

    return 0;
}

int Controller::readDB()
{
    QSqlQuery query( db );
    QMultiHash<QString, QString> allGenre;

    if( !query.exec("SELECT * FROM radio_genre")){
        qDebug() << "read DB radio_genre" << db.lastError().text();
        //          return 1;
    }
    QSqlRecord recordRadioGenre = query.record();
    const int radioId = recordRadioGenre.indexOf("radioId");
    const int genreId = recordRadioGenre.indexOf("genreId");

    while (query.next() ) {
        allGenre.insert(query.value(radioId).toString(), query.value(genreId).toString());
    }

    if( !query.exec("SELECT * FROM favorite")){
        qDebug() << "read DB favorite" << db.lastError().text();
        //        return 1;
    }

    QSqlRecord recordFavorite = query.record();

    QSet<QString> favoriteSet;

    while (query.next() ) {
        const int radioId = recordFavorite.indexOf("radioId");
        QString radioIdStr = query.value(radioId).toString();
        //        Radio *favoriteRadio =  allRadiosHash[radioIdStr];
        //        favorite.addRadio( *favoriteRadio);
        //      favoriteHash.insert(favoriteRadio->link(), favoriteRadio);
        favoriteSet.insert(radioIdStr);
    }

    if( !query.exec("SELECT * FROM radio")){
        qDebug() << "read DB radio" << db.lastError().text();
        //        return 1;
    }

    QSqlRecord record = query.record();

    qDebug("record +++++++++ record");
    while (query.next() ) {
        const int linkR = record.indexOf("link");
        const int nameR = record.indexOf("name");
        const int iconR = record.indexOf("icon");
        const int listeningR = record.indexOf("listening");

        QString link_str = query.value(linkR).toString();
        qDebug() << link_str ;

        QList<QString> genreRadio = allGenre.values(query.value(linkR).toString());

        Radio *newRadio = new Radio(query.value(linkR).toString(),
                                    query.value(nameR).toString(),
                                    query.value(iconR).toString(),
                                    query.value(listeningR).toInt(),
                                    genreRadio);
        //        if (favoriteHash.contains(link_str))
        //            newRadio->setFavorite(true);



        if (favoriteSet.contains(link_str))
        {
            newRadio->setFavorite(true);
            favorite.addRadio( newRadio);
            favoriteHash.insert(link_str, newRadio);

        }

        //           TestObject *testObj  ;



        stationsHash.insert(newRadio->link(), newRadio);
        stations.addRadio( newRadio  );

        //        sfHash.insert(newRadio->link(), testObj);

        stationsSet.push_back(newRadio);

    }

    //        qDebug() << "allRadiosHash";
    //    QHash<QString, Radio*>::iterator iterHash = stationsHash.begin();
    //    for (; iterHash != stationsHash.end(); ++iterHash)
    //    {
    //        //            qDebug() << iterHash.key() ;
    //        stations.addRadio( iterHash.value() );
    //    }


    qDebug() << "allRadiosHash check point stations";

    for (int i = 0; i < stations.getModelData().size(); ++i  )
    {
        qDebug() <<  stations.getModelData()[i]->link() << "|"  << stations.getModelData()[i];
    }
    qDebug() << "allRadiosHash check point favorite";
    for (int i = 0; i < favorite.getModelData().size(); ++i  )
    {
        qDebug() <<  favorite.getModelData()[i]->link() << "|"  << favorite.getModelData()[i];
    }


    return 0;
}

bool Controller::favoriteLinkExist(const QString link )
{ 
    //    emit sentToQmlFavorite(favoriteHash.contains(link));
    return favoriteHash.contains(link);
}


int Controller::inserDBinGenre(const QString genre)
{
    QSqlQuery query( db );
    query.prepare(insertGenre);
    query.bindValue( ":genre", genre );

    if( !query.exec() ) {
        qDebug() << "insertInto genre " << db.lastError().text();
        return -1;
    }
}

int Controller::inserDBinRadio(const QString &link, const QString &name, const QString &icon, const int &listening, const QList<QString> genre)
{
    QSqlQuery query(db);
    query.prepare(
                insertRadio
                );
    query.bindValue( ":link", link );
    query.bindValue( ":name", name );
    query.bindValue( ":icon",  icon);
    query.bindValue( ":listening",  listening);
    if( !query.exec() ) {
        qDebug() << "insertInto radio " << db.lastError().text();
        return -1;
    }


    for (int i = 0; i < genre.size(); ++i)
    {
        query.prepare(insertRadioGenre);
        query.bindValue( ":radioId", link );
        query.bindValue( ":genreId", genre[i] );
        if( !query.exec() ) {
            qDebug() << "insertInto radio_genre" << db.lastError().text();
            return -1;
        }
    }


    //    if( !query.exec("SELECT * FROM radio")){
    //        qDebug() << "read DB " << db.lastError().text();
    //        return 1;
    //    }

    //    QSqlRecord record = query.record();
    //    const int linkR = record.indexOf("link");
    //    const int nameR = record.indexOf("name");
    //    const int iconR = record.indexOf("icon");
    //    const int listeningR = record.indexOf("listening");


    //    qDebug("record +++++++++ record");
    //    while (query.next() ) {
    //        QString url_str = query.value(linkR).toString();
    //        qDebug() << url_str ;
    //    }

    return 0;
}

int Controller::insertList(const QString &link, const QString &name, const QString &icon, const int &listening, const QList<QString> genre)
{
    Radio *rad =  new Radio(link, name, icon, listening, genre);
    stations.addRadio( rad);
    return 0;
}

int Controller::insert(const QString &link, const QString &name, const QString &icon, const int &listening, const QList<QString> genre)
{
    inserDBinRadio(link, name, icon, listening, genre);
    //    insertList(link, name, icon, listening, genre);
    return 0;
}

//void Controller::addToFavoite(const QVariant& var){
////    QObject* obj = qvariant_cast<QObject*>(var);
////    Radio *radio = qobject_cast<Radio*>(obj);
//    qDebug() << "info" << var ;
////    qDebug() << "info" << radio->favorite() ;
//    //    radio->setFavorite(true);
//    //    favorite.addRadio(*radio);
//    //    emit sentToQml();
//    //    addToFavoiteInDB(radio->url()) ;
//}

void Controller::addToFavoite(const QString &radioId){
    if (stationsHash.contains(radioId))
    {
        if (addToFavoriteDB(radioId))
        {
            Radio *addToFavorite = stationsHash[radioId];
            addToFavorite->setFavorite(true);
            favorite.addRadio(addToFavorite);
            favoriteHash.insert(radioId, addToFavorite);
            emit sentToQml();
        }

        //         favoriteSetObj.push_back(addToFavorite);
        //        emit sentToQml();
        //        emit stations.favoriteChanged();
        //     qDebug() << favoriteSetObj.size();
        emit sentToQml();
    }
}

bool Controller::addToFavoriteDB(const QString &radioId)
{
    QSqlQuery query(db);
    query.prepare(insertFavorite);
    query.bindValue( ":radioId", radioId );

    if( !query.exec() ) {
        qDebug() << "insertInto favorite " << db.lastError().text();
        return false;
    } else return true;
}

void Controller::removeFromFavorite(const  QString &radioId)
{
    if (favoriteHash.contains(radioId))
    {
        qDebug() <<  "contain";
                if (  removeFromFavoriteDB(radioId) )
                {
                    Radio *removeFromFavorite = favoriteHash[radioId];
                    removeFromFavorite->setFavorite(false);
                    favorite.removeRadio(removeFromFavorite);
                    favoriteHash.remove(radioId);
                     emit sentToQml();
                }
        //        for (int i = 0; i <   stations.getModelData().size(); ++i)
        //        {
        //            qDebug() <<  stations.getModelData()[i]->link() << "|" <<  stations.getModelData()[i]->favorite() ;
        //        }

        // emit stations.favoriteChanged();
    } else  qDebug() <<  "does no contain";

    //            for (QHash<QString, Radio*>::iterator  i = favoriteHash.begin(); i!=favoriteHash.end(); ++i)
    //            {
    //                qDebug() <<  "|" + i.key() ;
    //            }
    qDebug() <<  "| removeFromFavorite " ;
}

  bool Controller::removeFromFavoriteDB(const  QString &radioId)
{
      QSqlQuery query(db);
      query.prepare(deleteFavorite);
      query.bindValue( ":radioId", radioId );

      if( !query.exec() ) {
          qDebug() << "delete favorite " << db.lastError().text();
          return false;
      } else return true;
}

bool   sortListening(const Radio &left, const Radio &right)
{
    return (left.listening() >  right.listening()) ;
}


bool   sort2(  const Radio *left,  const Radio *right)
{
    //     qDebug() <<  QString::compare( left.name(), right.name());
    qDebug() <<  left->name() << "|" <<   right->name() ;
    qDebug() <<  left->listening() << "|" <<   right->listening() ;
    qDebug() << (left->listening() <  right->listening() ) ;

    return (left->listening() >  right->listening() );

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

    //     qDebug() << "left" <<   (*&*right)->listening() << "|";


    std::vector<Radio*> vec;

    for ( int i = 0; i < stations.m_radios.size(); ++i)
    {
        qDebug() << "|" << stations.m_radios[i]->listening() ;
        vec.push_back( stations.m_radios[i]);
    }

    //    std::sort(vec.begin(), vec.end(),  sort2 );

    std::sort(stations.m_radios.begin(), stations.m_radios.end(),   sort2 );

    qDebug() << "sort";

    for ( int i = 0; i < vec.size(); ++i)
    {
        qDebug() << "|" << vec[i]->listening() ;
    }



    return 0;
}

bool   Controller::variantLessThan(const Radio &left, const Radio &right)
{
    return left.listening() <  right.listening() ;
}




