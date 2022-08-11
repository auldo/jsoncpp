#include "JsonValue.hpp"

namespace jsoncpp {

    std::string JsonTextValue::getValue() const {
        return this->value;
    }

    std::string JsonTextValue::toString() const {
        return "\"" + this->getValue() + "\"";
    }
}