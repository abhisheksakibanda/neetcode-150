cmake_minimum_required(VERSION 4.1.0)
project(leetcode_practice)

file(GLOB_RECURSE SRC_FILES src/*/*.cpp)

foreach (demo ${SRC_FILES})
    get_filename_component(folder ${demo} DIRECTORY)
    get_filename_component(folder_name ${folder} NAME)
    get_filename_component(file_name_we ${demo} NAME_WE)
    set(target_name ${file_name_we})

    # Add CodeDemo.cpp and all helper files to the target
    add_executable(${target_name} ${demo})
endforeach ()