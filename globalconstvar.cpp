#include "globalconstvar.h"
#include <PersonelManager/personelmodel.h>
#include <mongocxx/exception/exception.hpp>
#include "../url.h"

#include <bsoncxx/json.hpp>
#include <bsoncxx/types.hpp>

//TODO: std::call_once eklenecek

GlobalConstVar* GlobalConstVar::mInstance = nullptr;


GlobalConstVar::GlobalConstVar(QObject *parent)
    : QObject{parent}
{
    try {
        mClient = new mongocxx::client(mongocxx::uri(_url));
    } catch (mongocxx::exception &e) {
        qDebug() << "Error: No DB Connection: " << e.what();
    }
    mDB = mClient->database("SERIKBELTR");
}

GlobalConstVar::~GlobalConstVar()
{
    delete mClient;
}

GlobalConstVar *GlobalConstVar::createSingletonInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
{

    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    if(mInstance==nullptr){ mInstance = new GlobalConstVar;}
    return mInstance;

}

PersonelModel *GlobalConstVar::getPersonelModel()
{
    if( !mPersonelModel ){
        mCollection = mDB.collection("Personel");
        mPersonelModel = std::make_unique<PersonelModel>(&mCollection);
    }
    return mPersonelModel.get();
}
