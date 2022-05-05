cmake_minimum_required(VERSION 3.5)

project(Compiler 
                VERSION 0.0.0 
                LANGUAGES CXX)

# shuild only be under cmake_minimum_required
# should be set as g++-7, otherwise will report error
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    message("Linux")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    message("Darwin")
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set (CMAKE_CXX_COMPILER "/usr/bin/g++-5")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    set (CMAKE_CXX_COMPILER "x86_64-apple-darwin21-g++-11")
endif()

set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    include_directories(dependencies/linux/antlr4-runtime/src)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    include_directories(dependencies/linux/antlr4-runtime/src)
endif()
include_directories(grammar)
include_directories(src)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    link_directories(dependencies/linux/antlr4-runtime/lib)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    link_directories(dependencies/mac/antlr4-runtime/lib)
endif()
link_libraries(antlr4-runtime)

FILE(GLOB SOURCE_FILES "src/*.cpp" "grammar/*.cpp")

add_definitions(-w -g)

add_executable(compiler ${SOURCE_FILES})
