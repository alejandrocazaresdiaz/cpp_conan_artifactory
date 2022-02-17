cmake_minimum_required(VERSION 3.1)
project(producerLib CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(producerLib producerLib.cpp)
add_executable(demo main.cpp)
target_link_libraries(demo producerLib ${CONAN_LIBS})
