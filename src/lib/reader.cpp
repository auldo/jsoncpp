#include "../includes/reader.hpp"

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

    bool string_contains(std::string &string, char c) {
        for(char i : string){
            if(i == c)
                return true;
        }
        return false;
    }

}

namespace jsoncpp {

    std::map<int,std::string> store_values(std::string &fileName) {
        int counter = 0;
        std::map<int, std::string> map;
        while(util::string_contains(fileName, '"')) {
            int start = -1;
            int end = -1;
            for(int i = 0; i < fileName.size(); i++) {
                if(fileName.at(i) == '"' && start == -1)
                    start = i;
                else if(fileName.at(i) == '"')
                    end = i + 1;
                if(start != -1 && end != -1) {
                    map.insert({counter, fileName.substr(start, (end-start))});
                    fileName.erase(start, (end - start));
                    fileName.insert(start, "val_" + std::to_string(counter));
                    counter++;
                    break;
                }
            }
        }
        return map;
    }

}