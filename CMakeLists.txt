cmake_minimum_required(VERSION 3.23)
project(jsoncpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(jsoncpp main.cpp src/reader.hpp src/reader.cpp src/JsonItem.hpp src/JsonValue.hpp src/JsonItem.cpp src/JsonObject.hpp src/JsonObject.cpp src/JsonValue.cpp src/JsonArray.hpp src/JsonArray.cpp src/JsonStructure.hpp)
