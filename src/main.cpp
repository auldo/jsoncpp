#pragma once

#include <iostream>
#include <string>

#include "includes/reader.hpp"

int main() {
    std::cout << "Starting Application!" << std::endl;

    std::string fileName = "../test/res/test.json";
    std::string fileContent = jsoncpp::util::read_file(fileName);
    std::cout << fileContent << std::endl;

    jsoncpp::store_values(fileContent);
    std::cout << fileContent << std::endl;

    return 0;
}
