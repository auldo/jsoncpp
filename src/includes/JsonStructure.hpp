#pragma once

#include <string>

#include "JsonValue.hpp"

namespace jsoncpp {
    /**
     * Groups JsonObject and JsonArray, as these are the possible outcomes of the
     * reading and parsing process.
     */
    class JsonStructure : public JsonValue {
        public:
        virtual std::string toString() const = 0;
    };
}