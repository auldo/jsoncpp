#include "JsonItem.hpp"

namespace jsoncpp {

    JsonItem::JsonItem(std::string &key, jsoncpp::JsonValue* value) {
        this->key = key;
        this->value = value;
    }

    std::string JsonItem::getKey() const {
        return this->key;
    }

    JsonValue* JsonItem::getValue() const {
        return this->value;
    }

    std::string JsonItem::toString() const {
        return "\"" + key + "\"" + ":" + value->toString();
    }

}