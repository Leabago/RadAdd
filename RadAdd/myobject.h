#ifndef MYOBJECT_H
#define MYOBJECT_H
#include <QObject>
#include <testobject.h>

class TwoModels :  public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString myvar READ myvar WRITE setMyvar NOTIFY myvarChanged)
public:
    TwoModels( QList<QString> &all, QObject *parent = 0);
    virtual ~TwoModels() {}

    MyModel* getAllGenre(){ return  &allGenre;}
    MyModel* getMyGenre(){ return  &myGenre;}

private:
    MyModel allGenre;
    MyModel myGenre;

    QString myvar() const;
    void setMyvar(const QString& myvar);

signals:
    void myvarChanged();
};

#endif // MYOBJECT_H
