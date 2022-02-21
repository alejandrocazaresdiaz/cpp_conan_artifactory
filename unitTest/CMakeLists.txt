cmake_minimum_required(VERSION 3.8)

project(conanHelloWorld)

add_library(impFromJfrogLib impFromJfrogLib.cpp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)

add_executable(programa main.cpp)
add_executable(test cunit/basicTest.cpp)

target_link_libraries(programa impFromJfrogLib ${CONAN_LIBS})
target_link_libraries(test impFromJfrogLib ${CONAN_LIBS})

file(COPY
    my_config.json
    DESTINATION ${CMAKE_BINARY_DIR})
