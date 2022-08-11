cmake_minimum_required(VERSION 3.23)
project(jsoncpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(jsoncpp src/main.cpp src/includes/reader.hpp src/lib/reader.cpp src/includes/JsonItem.hpp src/includes/JsonValue.hpp src/lib/JsonItem.cpp src/includes/JsonObject.hpp src/lib/JsonObject.cpp src/lib/JsonValue.cpp src/includes/JsonArray.hpp src/lib/JsonArray.cpp src/includes/JsonStructure.hpp)
