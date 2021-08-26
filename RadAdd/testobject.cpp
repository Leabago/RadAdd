#include "testobject.h"
#include <QString>


MyObject::MyObject(const QString &myVar)
    : m_myVar(myVar)
{
}

QString MyObject::myVar() const
{
    return m_myVar;
}

void MyObject::setMyVar(const  QString &_myVar){
    m_myVar = _myVar;
}

MyModel::MyModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void MyModel::addMyObject(const MyObject &myObj)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data << myObj;
    endInsertRows();
    qDebug() <<  " rowCount();" << rowCount();
}

int MyModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_data.count();
}
 int MyModel::size() const
 {
     return m_data.count();
 }

 QList<MyObject>*  MyModel::getModelDataLink(){
     return &m_data;
 }


QVariant MyModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_data.count())
        return QVariant();

    const MyObject &myObj = m_data[index.row()];
    if (role == MyVarRole)
        return myObj.myVar();
    return QVariant();
}

//![0]
QHash<int, QByteArray> MyModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[MyVarRole] = "myVar";
    return roles;
}

void MyModel::deleteByIndex(const int &index)
{
    if (index <  rowCount() && index >= 0)
    {
        beginRemoveRows(QModelIndex(), rowCount(), rowCount());
        m_data.removeAt(index);
        endRemoveRows();
    }
}

