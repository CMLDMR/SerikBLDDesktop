#include "personelmodel.h"
#include <QQmlEngine>


using bsoncxx::builder::basic::document;

PersonelModel::PersonelModel(mongocxx::database *_database, QObject *parent)
    : mDB{_database},QAbstractListModel{parent}
{

    personelCount = mDB->collection("Personel").count_documents(document{}.view());

    beginResetModel();
    endResetModel();
}

void PersonelModel::registerType()
{
    qmlRegisterType<PersonelModel>("com.serik.personel",1,0, "PersonelModel");
}


int PersonelModel::rowCount(const QModelIndex &parent) const
{
    return personelCount;
}

QVariant PersonelModel::data(const QModelIndex &index, int role) const
{
    return QVariant{};
}

