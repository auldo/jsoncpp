#pragma once

#include <vector>

#include "JsonStructure.hpp"
#include "JsonValue.hpp"

namespace jsoncpp {

    /**
     * Represents a JsonArray containing JsonValues (numeric, string, objects, arrays).
     */
    class JsonArray : public JsonStructure {

    private:
        std::vector<JsonValue*> values;
    public:
        /**
         * Creates an empty JsonArray.
         */
        JsonArray();

        /**
         * Creates a JsonArray and stores values in it.
         * @param values The values to store in the array.
         */
        explicit JsonArray(std::vector<JsonValue*> values);

        /**
         * @return A string json representation of the array.
         */
        std::string toString() const override;

    };

}