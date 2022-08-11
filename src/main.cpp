#include <iostream>
#include <string>

#include "includes/reader.hpp"

int main() {
    std::cout << "Starting Application!" << std::endl;

    std::string fileName = "../test/res/test.json";
    std::string fileContent = jsoncpp::util::read_file(fileName);

    std::map<int, std::string> values = jsoncpp::store_values(fileContent);
    jsoncpp::util::remove_from_string(fileContent, ' ');
    std::cout << fileContent << std::endl;

    jsoncpp::JsonStructure* structure = jsoncpp::readStructure(fileContent, &values);
    auto* object = dynamic_cast<jsoncpp::JsonObject*>(structure);
    std::cout << object->toString() << std::endl;

    return 0;
}
