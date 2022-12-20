#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <mongocxx/instance.hpp>


#include <iostream>

inline const char* _url = "mongodb://<>SeriKbeltR<>:><><S_EKkrikneltR<>TR>1926><@195.175.200.2:41112/?authSource=SERIKBELTR";


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    mongocxx::instance ins{};

    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/SerikBLDDesktopQML/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
