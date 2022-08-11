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

static char identifier = '$';

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

    /**
     * Removes the first and last char of a string.
     * @param string The string to shorten.
     */
    void remove_string_ends(std::string &string);

    /**
     * Looks up a value in the lookup table.
     * @param val The value.
     * @param lookup The lookup table.
     * @return The resulting value that has been represented by an id.
     */
    std::string lookup_value(std::string val, std::map<int,std::string>* lookup);

    /**
     * Looks for the top level char positions. E.g., when reading a JSON Object,
     * we only want to find the delimiters (,) that split the items in the top layer and
     * not the ones that split items in sub or sub-sub objects.
     * @param representation The typical json object or array representation as string.
     * @param c The char, typically a ,.
     * @return The positions of the delimiter within the json string representation.
     */
    std::vector<int> find_top_level_char_positions(std::string &representation, char c);

    /**
     * Splits a string at multiple positions.
     * Note: Appending all types of the resulting list leads to the complete input string again.
     * @param string The string to be split up.
     * @param positions The positions on where to split it.
     * @return The single parts of the string.
     */
    std::vector<std::string> split_string_at_positions(std::string &string, std::vector<int> &positions);
}

namespace jsoncpp {

    /**
     * Stores all string values of a json file (keys, string values) in a map.
     * Replaces the values in the file with internal id descriptors (val_0, val_1, ...).
     * @param fileContent The content of a json file as string (e.g., via read_file).
     * @return The map, that maps the value ids to the actual string values.
     */
    std::map<int,std::string> store_values(std::string &fileContent);

    /**
     * Reads a JsonValue. Depending on the json file this might be text, numeric, object or array value.
     * @param string The string representation of the json value.
     * @param lookup The lookup table to resolve the value in case of a text value.
     * @return The JsonValue object.
     */
    JsonValue* readValue(std::string string, std::map<int, std::string> *lookup);

    /**
     * Reads a JsonItem (key value pair).
     * @param representation The item json string representation.
     * @param lookup The lookup table to possibly read a text value.
     * @return The JsonItem object.
     */
    JsonItem* readItem(std::string &representation, std::map<int,std::string>* lookup);

    /**
     * Reads a json object by reading every of its sub items.
     * @param representation The object json string representation.
     * @param lookup The lookup table to possibly read an item containing a text vale.
     * @return The JsonObject object.
     */
    JsonObject* readObject(std::string &representation, std::map<int,std::string>* lookup);

    /**
     * Reads a json array by reading every of its sub values.
     * @param representation The array json string representation.
     * @param lookup The lookup table to possibly read a text value.
     * @return The JsonArray object.
     */
    JsonArray* readArray(std::string &representation, std::map<int,std::string>* lookup);

}