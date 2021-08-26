#include "myobject.h"


TwoModels::TwoModels(QList<QString> &all, QObject *parent)
    : QObject(parent)
{
 QList<MyObject> *allGenreList = allGenre.getModelDataLink();

    for (int i = 0; i < all.size() ; ++i )
    {
      allGenre.addMyObject(MyObject(all[i]));
    }
}

 QString TwoModels::myvar() const
 {

 }

void TwoModels::setMyvar(const QString& myvar)
{
//    if(myvar != m_myvar){
//        m_myvar = myvar;
//        emit myvarChanged();
//    }
}


