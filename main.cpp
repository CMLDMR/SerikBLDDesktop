#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <mongocxx/instance.hpp>

#include <serikbldbackend.h>
#include <globalconstvar.h>
#include <PersonelManager/personelmodel.h>
#include <iostream>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    mongocxx::instance ins{};

    QQmlApplicationEngine engine;

    engine.addImportPath("qrc:/QML");

    SerikBLDBackend::registerQML();
    PersonelModel::registerType();


    qmlRegisterSingletonType<GlobalConstVar>("com.serik.global", 1 , 0 , "Global" , GlobalConstVar::createSingletonInstance );




    const QUrl url(u"qrc:/SerikBLDDesktopQML/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
