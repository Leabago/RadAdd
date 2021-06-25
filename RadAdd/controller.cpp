#include "controller.h"

Controller::Controller(QObject * parent)
    : QObject(parent)
{
    //    genre.push_back("�������� ������");             //0
    //    genre.push_back("�������� ������");             //1
    //    genre.push_back("������������� ������");        //2
    //    genre.push_back("����-������");                 //3
    //    genre.push_back("������");                      //4
    //    genre.push_back("������������������ ������");   //5
    //    genre.push_back("����");                        //6
    //    genre.push_back("����-�-����");                 //7
    //    genre.push_back("����");                        //8
    //    genre.push_back("������");                      //9
    //    genre.push_back("����������� ������");          //10
    //    genre.push_back("���");                         //11
    //    genre.push_back("���-���");                     //12
    //    genre.push_back("�����");                       //13
    //    genre.push_back("���-������");                  //14
    //    genre.push_back("�����");                       //15
    //    genre.push_back("��������� �����");             //16

    genre.push_back("Kek");             //0
    genre.push_back("Rock");             //1
    genre.push_back("Pusk");        //2
    genre.push_back("asd{");                 //3
    genre.push_back("asdd");                      //4
    genre.push_back("test123");


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
    QHash<QString, Radio*> allRadiosHash;

    if( !query.exec("SELECT * FROM radio_genre")){
        qDebug() << "read DB radio_genre" << db.lastError().text();
        //          return 1;
    }

    QSqlRecord recordRadioGenre = query.record();
    const int radioId = recordRadioGenre.indexOf("radioId");
    const int genreId = recordRadioGenre.indexOf("genreId");
    QMultiHash<QString, QString> allGenre;

    while (query.next() ) {
        allGenre.insert(query.value(radioId).toString(), query.value(genreId).toString());
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

        QString url_str = query.value(linkR).toString();
        qDebug() << url_str ;

        QList<QString> genreRadio = allGenre.values(query.value(linkR).toString());

        Radio *newRadio = new Radio(query.value(linkR).toString(),
                                    query.value(nameR).toString(),
                                    query.value(iconR).toString(),
                                    query.value(listeningR).toInt(),
                                    genreRadio);

        allRadiosHash.insert(newRadio->link(), newRadio);
    }

    qDebug() << "allRadiosHash";

    QHash<QString, Radio*>::iterator iterHash = allRadiosHash.begin();

    for (; iterHash != allRadiosHash.end(); ++iterHash)
    {
        qDebug() << iterHash.key() ;
        stations.addRadio( *iterHash.value() );
    }


    if( !query.exec("SELECT * FROM favorite")){
        qDebug() << "read DB favorite" << db.lastError().text();
        //        return 1;
    }

    QSqlRecord recordFavorite = query.record();

    while (query.next() ) {
        const int radioId = recordFavorite.indexOf("radioId");
        QString radioIdStr = query.value(radioId).toString();
        Radio *favoriteRadio =  allRadiosHash[radioIdStr];
        favorite.addRadio( *favoriteRadio);
        favoriteHash.insert(favoriteRadio->link(), favoriteRadio);
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
    stations.addRadio( new Radio(link, name, icon, listening, genre));
    return 0;
}

int Controller::insert(const QString &link, const QString &name, const QString &icon, const int &listening, const QList<QString> genre)
{
    inserDBinRadio(link, name, icon, listening, genre);
    //    insertList(link, name, icon, listening, genre);
    return 0;
}
