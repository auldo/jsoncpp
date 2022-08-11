#include "../includes/JsonObject.hpp"

#include <utility>

namespace jsoncpp {

    JsonObject::JsonObject(std::vector<JsonItem*> items) : items(std::move(items)) {};

    JsonObject::JsonObject() = default;

    std::string JsonObject::toString() const {
        std::string result = "{";
        for(int i = 0; i < this->items.size(); i++) {
            JsonItem* item = items.at(i);
            result += item->toString() + ",";
        }
        if(result.size() > 1)
            result.pop_back();
        return result + "}";
    }
}