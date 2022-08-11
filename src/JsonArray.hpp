#pragma once

#include <vector>

#include "JsonStructure.hpp"
#include "JsonValue.hpp"

namespace jsoncpp {

    /**
     * Represents a JsonArray containing JsonValues (numeric, string, objects, arrays).
     */
    class JsonArray : public JsonValue, public JsonStructure {

    private:
        std::vector<JsonValue*> values;
    public:
        /**
         * Creates an empty JsonArray.
         */
        JsonArray();
        JsonArray(std::vector<JsonValue*> values);
        std::string toString() const override;

    };

}