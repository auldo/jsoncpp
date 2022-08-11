#pragma once

#include <string>

#include "JsonValue.hpp"

namespace jsoncpp {

    /**
     * Represents a Key Value pair typically stored inside JsonObjects.
     */
    class JsonItem {

    private:
        std::string key;
        JsonValue* value = nullptr;
    public:
        /**
         * Creates a new JsonItem.
         * @param key The item's key.
         * @param value The item's value.
         */
        JsonItem(std::string &key, JsonValue* value);

        /**
         * @return The item's key.
         */
        std::string getKey() const;

        /**
         * @return The item's value.
         */
        JsonValue* getValue() const;

        /**
         * @return The item's json string representation.
         * E.g., "name":"example".
         */
        std::string toString() const;

    };

}