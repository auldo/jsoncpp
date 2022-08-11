#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

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
    std::string read_file(const std::string& fileName);
}

namespace jsoncpp {

}