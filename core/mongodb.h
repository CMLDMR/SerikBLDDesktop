#ifndef MONGODB_H
#define MONGODB_H

#include <mongocxx/database.hpp>
#include <mongocxx/client.hpp>

namespace Core {


class MongoDB
{
private:
    MongoDB();
    mongocxx::client *mClient;
    mongocxx::database mDB;
    static MongoDB* mInstance;

public:
    static MongoDB* Instance();

    mongocxx::database &Database();
};

}



#endif // MONGODB_H
