#include "../includes/JsonArray.hpp"

#include <utility>

namespace jsoncpp {

    JsonArray::JsonArray() = default;

    JsonArray::JsonArray(std::vector<JsonValue*> values) {
        this->values = std::move(values);
    }

    std::string JsonArray::toString() const {
        std::string result = "[";
        for(JsonValue* value : this->values) {
            result += value->toString() + ",";
        }
        if(result.size() > 1)
            result.pop_back();
        return result + "]";
    }

}