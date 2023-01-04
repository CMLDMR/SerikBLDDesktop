#include "item.h"

Core::Item::Item()
{
    this->append("sdsd",true);
    this->append("asas",bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("sdf","sdfg")));
}

bsoncxx::document::view Core::Item::getView() const
{
    return this->view();
}

template<typename T>
Core::Item &Core::Item::append(const std::string key, const T &value)
{
    this->bsoncxx::builder::basic::document::append(bsoncxx::builder::basic::kvp(key,value));
    return *this;
}
