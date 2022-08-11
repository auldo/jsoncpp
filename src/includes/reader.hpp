#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>

#include "JsonStructure.hpp"
#include "JsonObject.hpp"
#include "JsonArray.hpp"
#include "JsonItem.hpp"
#include "JsonValue.hpp"

namespace jsoncpp::util {

    /**
     * Reads a file a returns the file's contents as coherent string.
     * @param fileName The absolute path to the file.
     * @return The content as a string.
     */
    std::string read_file(const std::string &fileName);

    /**
     * @param string The string to check on.
     * @param c The char to check on if it is contained.
     * @return True, iff the char is contained within the string at least once.
     */
    bool string_contains(std::string &string, char c);

    /**
     * Removes all occurrences of a char from a string.
     * @param string The string to shorten.
     * @param c The char to remove.
     */
    void remove_from_string(std::string &string, char c);
}

namespace jsoncpp {

    /**
     * Stores all string values of a json file (keys, string values) in a map.
     * Replaces the values in the file with internal id descriptors (val_0, val_1, ...).
     * @param fileContent The content of a json file as string (e.g., via read_file).
     * @return The map, that maps the value ids to the actual string values.
     */
    std::map<int,std::string> store_values(std::string &fileContent);

}