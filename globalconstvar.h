#ifndef GLOBALCONSTVAR_H
#define GLOBALCONSTVAR_H

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>
#include <memory>

#include "core/mongodb.h"

class PersonelModel;


class GlobalConstVar : public QObject
{
    Q_OBJECT

private:
    explicit GlobalConstVar(QObject *parent = nullptr);
    virtual ~GlobalConstVar();
    static GlobalConstVar *mInstance;

public:
    static GlobalConstVar* createSingletonInstance( QQmlEngine* engine,QJSEngine* scriptEngine );


    Q_INVOKABLE QString mainPage() const { return "qrc:/QML/AnaMenu.qml";}
    Q_INVOKABLE QString personelPage() const { return "qrc:/PersonelManager/PersonelManager.qml";}


    Q_INVOKABLE PersonelModel* getPersonelModel();


signals:


private:
    std::unique_ptr<PersonelModel> mPersonelModel = nullptr;

    Core::MongoDB* mMongoDB;

};

#endif // GLOBALCONSTVAR_H
