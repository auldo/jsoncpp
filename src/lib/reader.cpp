#include "../includes/reader.hpp"

namespace jsoncpp::util {

    std::string read_file(const std::string &fileName) {
        std::string result;
        std::string line;
        std::ifstream file(fileName);
        if (file.is_open()) {
            while (std::getline(file, line)) {
                result += line;
            }
            file.close();
        }
        return result;
    }

    bool string_contains(std::string &string, char c) {
        for (char i: string) {
            if (i == c)
                return true;
        }
        return false;
    }

    void remove_from_string(std::string &string, char c) {
        while (string_contains(string, c)) {
            for (int i = 0; i < string.size(); i++) {
                if (string.at(i) == c) {
                    string.erase(i, 1);
                    break;
                }
            }
        }
    }

    void remove_string_ends(std::string &string) {
        string.pop_back();
        std::reverse(string.begin(), string.end());
        string.pop_back();
        std::reverse(string.begin(), string.end());
    }

    std::string lookup_value(std::string val, std::map<int, std::string> *lookup) {
        util::remove_from_string(val, identifier);
        int key = std::stoi(val);
        return lookup->at(key);
    }

    std::vector<int> find_top_level_char_positions(std::string &representation, char c) {
        std::vector<int> positions;
        int balance = 0;
        for (int i = 0; i < representation.size(); i++) {
            char ch = representation.at(i);
            if (ch == c && balance == 0)
                positions.push_back(i);
            if (ch == '{' || ch == '[')
                balance += 1;
            else if (ch == '}' || ch == ']')
                balance -= 1;
        }
        return positions;
    }

    std::vector<std::string> split_string_at_positions(std::string &string, std::vector<int> &positions) {
        std::vector<std::string> split;
        int last = 0;
        for (int i = 0; i < positions.size(); i++) {
            int position = positions.at(i);
            std::string substring = string.substr(last, (position - last));
            split.push_back(substring);
            last = position;
        }
        split.push_back(string.substr(last, (string.size() - last)));
        for (std::string &s: split) {
            if (s.at(0) == ',')
                s.erase(0, 1);
        }
        return split;
    }
}

namespace jsoncpp {

    std::map<int, std::string> store_values(std::string &fileName) {
        int counter = 0;
        std::map<int, std::string> map;
        while (util::string_contains(fileName, '"')) {
            int start = -1;
            int end = -1;
            for (int i = 0; i < fileName.size(); i++) {
                if (fileName.at(i) == '"' && start == -1)
                    start = i;
                else if (fileName.at(i) == '"')
                    end = i + 1;
                if (start != -1 && end != -1) {
                    map.insert({counter, fileName.substr(start, (end - start))});
                    fileName.erase(start, (end - start));
                    fileName.insert(start, identifier + std::to_string(counter));
                    counter++;
                    break;
                }
            }
        }
        return map;
    }

    JsonValue* readValue(std::string string, std::map<int, std::string> *lookup) {
        if (string.at(0) == identifier)
            return new JsonTextValue(util::lookup_value(string, lookup));
        else if (string.at(0) == '{')
            return (readObject(string, lookup));
        else if (string.at(0) == '[')
             return readArray(string, lookup);
        else {
            if (util::string_contains(string, '.'))
                return new JsonNumericValue<double>(std::stoi(string));
            else
                return new JsonNumericValue<int>(std::stoi(string));
        }
    }

    JsonItem *readItem(std::string &representation, std::map<int, std::string> *lookup) {
        std::string keySection = representation.substr(0, representation.find(':'));
        std::string valSection = representation.substr(representation.find(':') + 1, representation.size());
        std::string key = util::lookup_value(keySection, lookup);
        return new JsonItem(key, readValue(valSection, lookup));
    }

    JsonObject *readObject(std::string &representation, std::map<int, std::string> *lookup) {
        std::vector<JsonItem *> items;
        util::remove_string_ends(representation);

        std::vector<int> commata = util::find_top_level_char_positions(representation, ',');
        std::vector<std::string> locations = util::split_string_at_positions(representation, commata);

        for (std::string location: locations) {
            JsonItem *item = readItem(location, lookup);
            items.push_back(item);
        }

        return new JsonObject(items);
    }

    JsonArray* readArray(std::string &representation, std::map<int, std::string> *lookup) {
        std::vector<JsonValue *> values;
        util::remove_string_ends(representation);

        std::vector<int> commata = util::find_top_level_char_positions(representation, ',');
        std::vector<std::string> locations = util::split_string_at_positions(representation, commata);

        for (const std::string& location: locations)
            values.push_back(readValue(location, lookup));
        return new JsonArray(values);
    }

    JsonStructure* readStructure(std::string &fileContent, std::map<int,std::string> *lookup) {
        if(fileContent.at(0) == '{')
            return readObject(fileContent, lookup);
        if(fileContent.at(0) == '[')
            return readArray(fileContent, lookup);
        else
            return nullptr;
    }
}