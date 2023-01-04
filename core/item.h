#ifndef ITEM_H
#define ITEM_H

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <QDebug>


namespace Core {
class Item : private bsoncxx::builder::basic::document
{
public:
    Item();

    template<typename T>
    Item& append(const std::string key, const T &value );


    bsoncxx::document::view getView() const;

    friend QDebug operator<<( QDebug debug, const Item &item){
        debug << bsoncxx::to_json(item.getView()).c_str();
        return debug;
    }

};
}



#endif // ITEM_H
