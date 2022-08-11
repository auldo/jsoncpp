#pragma once

#include <iostream>
#include <string>

#include "includes/reader.hpp"

int main() {
    std::cout << "Starting Application!" << std::endl;

    std::string fileName = "/Users/dominikaulinger/Desktop/test.json";
    std::string fileContent = jsoncpp::util::read_file(fileName);
    std::cout << fileContent << std::endl;

    return 0;
}
