cmake_minimum_required(VERSION 3.22)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Rlease)
endif()

message("Build Type: ${CMAKE_BUILD_TYPE}")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake;${CMAKE_CODULE_PATH}")

#check compilers info
message("Generator: ${CMAKE_GENERATOR}")
message("C++ compiler: ${CMAKE_CXX_COMPILER}")
message("C compiler: ${CMAKE_C_COMPILER}")

project(femtic LANGUAGES CXX)
project(femtic
    DESCRIPTION "FEMTIC is a 3-D magnetotelluric inversion code. FEMTIC is made by object-oriented programming with C++. FEMTIC is applicable to land magnetotelluric survey data as well as ocean bottom magnetotelluric survey data."
    HOMEPAGE_URL https://github.com/yoshiya-usui/femtic
    VERSION 0.0.0
    )
message("Project_Name: ${PROJECT_NAME}")
message("Project_Version: ${PROJECT_VERSION}")
message("Project_Version_Major: ${PROJECT_VERSION_MAJOR}")
message("Project_Version_Minor: ${PROJECT_VERSION_MINOR}")
message("Project_Version_Patch: ${PROJECT_VERSION_PATCH}")
message("Project_Description: ${PROJECT_DESCRIPTION}")
message("Project_Homepage_URL: ${PROJECT_HOMEPAGE_URL}")
message("Project_Source_Dir: ${PROJECT_SOURCE_DIR}")
message("Project_Binary_Dir: ${PROJECT_BINARY_DIR}")
message("CMAKE_Current_Ssource_Dir: ${CMAKE_CURRENT_SOURCE_DIR}")
message("CMAKE_Current_Binary_Dir: ${CMAKE_CURRENT_BINARY_DIR}")
add_subdirectory(femtic_lib)
add_subdirectory(femtic_main)
set(CMAKE_COLOR_MAKEFILE on)

