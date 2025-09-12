cmake_minimum_required(VERSION 4.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(leetcode_practice)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE PROBLEM_SOURCES src/*/*.cpp)

foreach (demo ${PROBLEM_SOURCES})
    get_filename_component(file_name_we ${demo} NAME_WE)

    add_executable(${file_name_we} ${demo})

    target_include_directories(${file_name_we} PRIVATE
        ${CMAKE_SOURCE_DIR}/include
    )
endforeach ()