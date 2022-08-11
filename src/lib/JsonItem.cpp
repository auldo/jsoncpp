#include "../includes/JsonItem.hpp"

namespace jsoncpp {

    JsonItem::JsonItem(std::string &key, jsoncpp::JsonValue* value) {
        key.erase(0, 1);
        key.erase(key.size() - 1, 1);
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