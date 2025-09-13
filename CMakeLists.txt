cmake_minimum_required(VERSION 4.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(leetcode_practice)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE PROBLEM_SOURCES src/*/*.cpp)

set(TREENODE_SRC ${CMAKE_SOURCE_DIR}/include/BinaryTree/TreeNode.cpp)
set(LISTNODE_SRC ${CMAKE_SOURCE_DIR}/include/LinkedList/ListNode.cpp)

# Create executables for each problem
foreach (src ${PROBLEM_SOURCES})
    get_filename_component(file_name_we ${src} NAME_WE)
    file(READ ${src} FILE_CONTENTS)
    set(EXTRA_SRC "")

    if(FILE_CONTENTS MATCHES "#include \"BinaryTree/TreeNode.h\"")
        list(APPEND EXTRA_SRC ${TREENODE_SRC})
    endif()
    if(FILE_CONTENTS MATCHES "#include \"LinkedList/ListNode.h\"")
        list(APPEND EXTRA_SRC ${LISTNODE_SRC})
    endif()
    add_executable(${file_name_we} ${src} ${EXTRA_SRC})

    # Make sure executables also know about headers
    target_include_directories(${file_name_we} PRIVATE
        ${CMAKE_SOURCE_DIR}/include
    )
endforeach ()