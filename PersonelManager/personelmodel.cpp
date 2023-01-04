#include "personelmodel.h"
#include <QQmlEngine>
#include "core/mongodb.h"
#include "core/item.h"
#include <QDebug>

using bsoncxx::builder::basic::document;

PersonelModel::PersonelModel(Core::MongoDB *_database, QObject *parent)
    : mDB{_database},QAbstractListModel{parent}
{

    Core::Item item;

    qDebug() << item << "";


    personelCount = mDB->Database().collection("Personel").count_documents(document{}.view());

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

