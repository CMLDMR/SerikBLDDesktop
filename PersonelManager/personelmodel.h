#ifndef PERSONELMODEL_H
#define PERSONELMODEL_H

#include <QAbstractListModel>
#include <mongocxx/database.hpp>
#include <vector>


#include "db.h"
#include "personelmanager.h"
namespace Core{
class MongoDB;
}


class PersonelModel : public QAbstractListModel, public SerikBLDCore::PersonelManager
{
public:
    PersonelModel(SerikBLDCore::DB* _database = nullptr, QObject *parent = nullptr);

    static void registerType();

    enum PersonelModelRoles{
        adSoyad = Qt::UserRole+1,
        birim,
        status,
        telefon,
        sifre
    };


    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;



private:
    Core::MongoDB* mDB;


    int personelCount;

    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // ListItem interface
public:
    virtual void onList(const QVector<SerikBLDCore::IK::Personel> *mlist) override;

};

#endif // PERSONELMODEL_H
