#include "radiomodel.h"
#include <QDebug>

RadioModel::RadioModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void RadioModel::addRadio( Radio *&radio)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_radios.push_back(radio);
    endInsertRows();
}

void RadioModel::removeByIndex(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_radios.removeAt(index);
    endRemoveRows();
}

int RadioModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_radios.count();
}

QVariant RadioModel::data(const QModelIndex & index, int role)  const {
    if (index.row() < 0 || index.row() >= m_radios.count())
        return QVariant();

    const Radio *radio = m_radios[index.row()];
    if (role == LinkRole)
        return radio->link();
    else if (role == NameRole)
        return radio->name();
    else if (role == IconRole)
        return radio->icon();
    else if (role == ListeninHoursRole)
        return radio->listeningHours();
    else if (role == FavoriteRole)
        return radio->favorite();   
    return QVariant();
}

QHash<int, QByteArray> RadioModel::roleNames()  const {
    QHash<int, QByteArray> roles;
    roles[LinkRole] = "link";
    roles[NameRole] = "name";
    roles[IconRole] = "icon";
    roles[ListeninHoursRole] = "listeningHours";
    roles[FavoriteRole] = "favorite";
    return roles;
}

QList<Radio*>  RadioModel::getModelData()
{
    return  m_radios;
}

  QList<Radio*>*   RadioModel::getModelDataLink()
  {
      return &m_radios;
  }

void RadioModel::removeRadio(Radio *rad)
{
    int index = m_radios.indexOf(rad);
    beginRemoveRows(QModelIndex(), index, index);
    m_radios.removeOne(rad);
    endRemoveRows();
}

//void RadioModel::insert(int index, const QString &colorValue)
//{
//    qDebug() << "insert";
//    emit QAbstractItemModel::beginResetModel();
//     emit QAbstractItemModel::endResetModel();
//}
