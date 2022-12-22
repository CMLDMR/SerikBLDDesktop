#include "personelmodel.h"
#include <QQmlEngine>

PersonelModel::PersonelModel(mongocxx::collection *_collection, QObject *parent)
    : mCollection{_collection},QAbstractListModel{parent}
{

}

void PersonelModel::registerType()
{
    qmlRegisterType<PersonelModel>("com.serik.personel",1,0, "PersonelModel");
}


int PersonelModel::rowCount(const QModelIndex &parent) const
{
    return 15;
}

QVariant PersonelModel::data(const QModelIndex &index, int role) const
{
    return QVariant{};
}

