cmake_minimum_required(VERSION 3.1.4...3.6.0)
project(cmake-project-template)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR})#设置当前项目为根目录
include_directories(${PROJECT_SOURCE_DIR}/resource/)#设置当前项目为根目录
include_directories(${PROJECT_SOURCE_DIR}/3rdparty/spdlog-2.x/include/)#设置当前项目为根目录
#include_directories(${Boost_INCLUDE_DIRS})
string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})
add_subdirectory(src/base)
add_subdirectory(src/net)
add_subdirectory(tests)


