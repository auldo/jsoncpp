#pragma once

#include <string>
#include <utility>

namespace jsoncpp {

    /**
     * Super class for all JsonValues.
     * These are: JsonTextValue, JsonNumericValue, JsonObject and JsonArray.
     * A JsonValue can be part of a JsonArray or a JsonObject (via JsonItem Key-Value Pair).
     */
    class JsonValue {
        public:
            /**
             * @return A string representation of the json.
             */
            virtual std::string toString() const = 0;
    };

    /**
     * Wraps a string value.
     */
    class JsonTextValue : public JsonValue {
    private:
        std::string value;
    public:
        /**
         * @param value The string to become a JsonValue.
         */
        explicit JsonTextValue(std::string value) : value(std::move(value)) {}

        /**
         * @return The string, that is JsonValue.
         */
        std::string getValue() const ;
        std::string toString() const override;
    };

    /**
     * Wraps some sort of numeric value, like int or double.
     * @tparam T The type of the value.
     */
    template <typename T>
    class JsonNumericValue : public JsonValue {

    private:
        T value;
    public:
        explicit JsonNumericValue(T value) : value(value) {}
        /**
         * @return The number that is a JsonValue.
         */
        T getValue() const ;
        /**
         * @return The number as a string.
         */
        std::string toString() const override;

    };

    //Implementation of the generic methods as they can not be implemented in source files properly.
    //See https://stackoverflow.com/questions/115703/storing-c-template-function-definitions-in-a-cpp-file

    template <typename T>
    T JsonNumericValue<T>::getValue() const {
        return this->value;
    }

    template <typename T>
    std::string JsonNumericValue<T>::toString() const {
        return std::to_string(this->value);
    }
}