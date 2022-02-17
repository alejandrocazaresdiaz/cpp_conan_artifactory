
cmake_minimum_required(VERSION 3.8)

project(consumerLib)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)

add_executable(demo main.cpp)

target_link_libraries(demo producerLib ${CONAN_LIBS})
