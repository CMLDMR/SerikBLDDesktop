#include "mongodb.h"
#include <mongocxx/exception/exception.hpp>
#include <QDebug>

#include "../url.h"

Core::MongoDB* Core::MongoDB::mInstance = nullptr;

Core::MongoDB* Core::MongoDB::Instance()
{
    if( mInstance == nullptr ){
        mInstance = new MongoDB();
    }
    return mInstance;
}

mongocxx::database &Core::MongoDB::Database()
{
    return mDB;
}

Core::MongoDB::MongoDB()
{
    try {
        mClient = new mongocxx::client(mongocxx::uri(_url));
    } catch (mongocxx::exception &e) {
        qDebug() << "Error: No DB Connection: " << e.what();
    }


    mDB = mClient->database("SERIKBELTR");
}
