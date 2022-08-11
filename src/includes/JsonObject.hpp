#pragma once

#include <string>
#include <vector>

#include "JsonStructure.hpp"
#include "JsonItem.hpp"
#include "JsonValue.hpp"

namespace jsoncpp {

    /**
     * Represents a JsonObject that contains JsonItem key-value pairs.
     */
    class JsonObject : public JsonStructure {

    private:
        std::vector<JsonItem*> items;
    public:

        /**
         * Creates a new JsonObject from key-value pairs.
         * @param items The key-value pairs.
         */
        JsonObject(std::vector<JsonItem*> items);

        /**
         * Creates an empty JsonObject.
         */
        JsonObject();

        /**
         * @return The string representation of a JsonObject.
         * E.g., {"name":"example"}.
         */
        std::string toString() const override;

    };

}