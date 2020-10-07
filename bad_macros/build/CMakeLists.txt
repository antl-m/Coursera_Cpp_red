cmake_minimum_required (VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)

set (PROJECT bad_macros)

set (HEADERS
        ../../test_runner.h)

set (SOURCES
        ../print_values.cpp)

project (${PROJECT})

if (MSVC)
    add_definitions (/W4)
elseif (CMAKE_COMPILER_IS_GNUCXX)
    add_definitions (-Wall -pedantic)
else ()
    message ("Unknown compiler")
endif ()

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_executable (${PROJECT} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT} PUBLIC ../../ ../)