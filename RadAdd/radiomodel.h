#ifndef RADIOMODEL_H
#define RADIOMODEL_H
#include <QAbstractListModel>
#include "radio.h"

class RadioModel : public QAbstractListModel
{
    Q_OBJECT

public:
    RadioModel(QObject *parent = 0);

    enum Roles {
        LinkRole = Qt::UserRole + 1,
        NameRole,
        IconRole,
        ListeninHoursRole,
        FavoriteRole,
    };
    void removeByIndex(int index);
    void addRadio(Radio *&radio);
    void removeRadio(Radio *rad);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const ;
    QList<Radio*>  getModelData();
    QList<Radio*>*  getModelDataLink();

protected:
    QHash<int, QByteArray> roleNames()  const;
public: // private
    QList<Radio*> m_radios;

//public slots:
//    Q_INVOKABLE void insert(int index, const QString& colorValue);

signals:
    void favoriteChanged();
};

#endif // RADIOMODEL_H
