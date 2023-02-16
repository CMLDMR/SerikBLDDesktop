#include "personelmodel.h"
#include <QQmlEngine>
#include "core/mongodb.h"
#include "personel.h"
#include <QDebug>

using bsoncxx::builder::basic::document;

PersonelModel::PersonelModel(SerikBLDCore::DB *_database, QObject *parent)
    : SerikBLDCore::PersonelManager(_database),QAbstractListModel{parent}
{

    SerikBLDCore::IK::Personel filter;
    filter.setBirim("Bilgi İşlem Müdürlüğü");


    this->UpdateList(filter);

}

void PersonelModel::registerType()
{
    qmlRegisterType<PersonelModel>("com.belediye.personel",1,0, "PersonelModel");
}


int PersonelModel::rowCount(const QModelIndex &parent) const
{
    return this->List().size();
}

QVariant PersonelModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch (role) {
    case PersonelModelRoles::adSoyad:
        return QVariant{this->List()[index.row()].AdSoyad()};
        break;
    }

    return QVariant();
}



void PersonelModel::errorOccured(const std::string &errorText)
{
}

void PersonelModel::onList(const QVector<SerikBLDCore::IK::Personel> *mlist)
{
    beginResetModel();

    personelCount = mlist->size();
    endResetModel();

}


QHash<int, QByteArray> PersonelModel::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[adSoyad] = "adsoyad";
    roles[birim] = "birim";
    roles[status] = "statu";
    roles[telefon] = "telefon";
    roles[sifre] = "sifre";
    return roles;
}
