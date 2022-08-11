cmake_minimum_required(VERSION 3.23)
project(jsoncpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(jsoncpp main.cpp includes/reader.hpp lib/reader.cpp includes/JsonItem.hpp includes/JsonValue.hpp lib/JsonItem.cpp includes/JsonObject.hpp lib/JsonObject.cpp lib/JsonValue.cpp includes/JsonArray.hpp lib/JsonArray.cpp includes/JsonStructure.hpp)
