#include "reader.hpp"

namespace jsoncpp::util {

    std::string read_file(const std::string& fileName) {
        std::string result;
        std::string line;
        std::ifstream file(fileName);
        if(file.is_open()) {
            while(std::getline(file, line)){
                result += line;
            }
            file.close();
        }
        return result;
    }
}

namespace jsoncpp {



}