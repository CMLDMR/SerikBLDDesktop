#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <mongocxx/instance.hpp>

#include <serikbldbackend.h>
#include <iostream>

inline const char* _url = "";


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    mongocxx::instance ins{};

    QQmlApplicationEngine engine;

    engine.addImportPath("qrc:/QML");

    SerikBLDBackend::registerQML();

    const QUrl url(u"qrc:/SerikBLDDesktopQML/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
