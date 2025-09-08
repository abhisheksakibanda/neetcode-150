cmake_minimum_required(VERSION 4.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(leetcode_practice)

file(GLOB_RECURSE UTILS_SOURCES src/utils/*.cpp)
add_library(utils ${UTILS_SOURCES})

file(GLOB_RECURSE PROBLEM_SOURCES src/*/*.cpp)
list(FILTER PROBLEM_SOURCES EXCLUDE REGEX ".*/utils/.*")

foreach (demo ${PROBLEM_SOURCES})
    get_filename_component(file_name_we ${demo} NAME_WE)

    add_executable(${file_name_we} ${demo})
    target_link_libraries(${file_name_we} PRIVATE utils)
endforeach ()