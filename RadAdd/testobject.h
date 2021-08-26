#ifndef TESTOBJECT_H
#define TESTOBJECT_H
#include <QObject>
#include <QDebug>
#include <QAbstractListModel>

class MyObject
{
public:
    MyObject(const QString &myVar);
    QString myVar() const;    
    void setMyVar(const  QString &_myVar);
private:
    QString m_myVar;
};

class MyModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        MyVarRole = Qt::UserRole + 1
    };

    MyModel(QObject *parent = 0);

    void addMyObject(const MyObject &myObj);
    void deleteByIndex(const int &index);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    int size() const;
     QList<MyObject>*  getModelDataLink();

protected:
    QHash<int, QByteArray> roleNames() const;
public:
    QList<MyObject> m_data;
};


#endif // TESTOBJECT_H
