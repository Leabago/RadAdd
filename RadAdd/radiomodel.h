#ifndef RADIOMODEL_H
#define RADIOMODEL_H
#include <QAbstractListModel>
#include "radio.h"

class RadioModel : public QAbstractListModel
{
    Q_OBJECT
public:
    RadioModel(QObject *parent = 0);

    enum AnimalRoles {
        LinkRole = Qt::UserRole + 1,
        NameRole,
        IconRole,
        ListeningRole,
        GenreRole
    };
    void removeByIndex(int index);
    void addRadio(Radio *&radio);
    void addRadio(Radio &radio);
    void addRadio(Radio *radio);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QList<Radio*>  getModelData();

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Radio*> m_radios;
};

#endif // RADIOMODEL_H
