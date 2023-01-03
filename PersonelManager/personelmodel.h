#ifndef PERSONELMODEL_H
#define PERSONELMODEL_H

#include <QAbstractListModel>
#include <mongocxx/database.hpp>
#include <vector>

class PersonelModel : public QAbstractListModel
{
public:
    PersonelModel(mongocxx::database* _database = nullptr, QObject *parent = nullptr);

    static void registerType();

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;



private:
    mongocxx::database* mDB;


    int personelCount;
};

#endif // PERSONELMODEL_H
