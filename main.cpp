#include <QGuiApplication>
#include <QQmlApplicationEngine>


#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/stdx/make_unique.hpp>
#include <bsoncxx/string/view_or_value.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/document/view_or_value.hpp>
#include <bsoncxx/document/view.hpp>
#include <bsoncxx/builder/core.hpp>
#include <bsoncxx/types.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/exception/exception.hpp>
#include <bsoncxx/view_or_value.hpp>
#include <bsoncxx/types/value.hpp>


#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/logger.hpp>
#include <mongocxx/options/client.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/exception/exception.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/gridfs/bucket.hpp>
#include <mongocxx/pipeline.hpp>
#include <mongocxx/exception/gridfs_exception.hpp>
#include <mongocxx/exception/query_exception.hpp>


#include <iostream>

inline const char* _url = "mongodb://<>SeriKbeltR<>:><><S_EKkrikneltR<>TR>1926><@195.175.200.2:41112/?authSource=SERIKBELTR";


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    mongocxx::instance ins{};

    mongocxx::client* mClient;

    try {
        mClient = new mongocxx::client(mongocxx::uri(_url));
    } catch (mongocxx::exception& e) {
        std::cout << "MongoDB Connection Error: " << e.what() << std::endl;
    }

    mongocxx::database db;

    db = mClient->database("SERIKBELTR");


    auto filter = bsoncxx::builder::basic::document{};

    auto cursor = db.collection("Duyurular").find(filter.view());

    for( auto &item : cursor ){

        std::cout << bsoncxx::to_json(item) << "\n";


    }


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
