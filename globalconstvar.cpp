#include "globalconstvar.h"
#include <PersonelManager/personelmodel.h>
#include <item.h>
#include "../url.h"

//TODO: std::call_once eklenecek

GlobalConstVar* GlobalConstVar::mInstance = nullptr;


GlobalConstVar::GlobalConstVar(QObject *parent)
    : QObject{parent}
{
    mMongoDB = Core::MongoDB::Instance();

    try {
        mClient = new mongocxx::client(mongocxx::uri(_url));
    } catch (mongocxx::exception &e) {
        qDebug() << "Error: No DB Connection: " << e.what();
    }
    mongoDB = mClient->database("SERIKBELTR");
    mDB = new SerikBLDCore::DB(&mongoDB);
}

GlobalConstVar::~GlobalConstVar()
{
    delete mMongoDB;
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
        mPersonelModel = std::make_unique<PersonelModel>(mDB);
    }
    return mPersonelModel.get();
}
