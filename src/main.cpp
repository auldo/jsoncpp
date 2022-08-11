#include <iostream>
#include <string>

#include "includes/reader.hpp"

int main(int argc, char *argv[]) {
    std::cout << "Starting Application!" << std::endl;
    if(argc == 2) {
        std::string fileName = argv[1];
        jsoncpp::JsonStructure* structure = jsoncpp::readStructure(fileName);
        std::cout << "Result:" << std::endl;
        std::cout << structure->toString() << std::endl;
    } else {
        std::cout << "Please make sure there's only one argument - the path." << std::endl;
    }
    return 0;
}
