#include "globalconstvar.h"
#include <PersonelManager/personelmodel.h>


//TODO: std::call_once eklenecek

GlobalConstVar* GlobalConstVar::mInstance = nullptr;


GlobalConstVar::GlobalConstVar(QObject *parent)
    : QObject{parent}
{
    mMongoDB = Core::MongoDB::Instance();
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
        mPersonelModel = std::make_unique<PersonelModel>(mMongoDB);
    }
    return mPersonelModel.get();
}
