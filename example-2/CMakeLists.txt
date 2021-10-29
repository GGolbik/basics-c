###########################################################
# cmake version to be used
# It is just to tell CMake which version of the tool it shall use.
###########################################################
cmake_minimum_required( VERSION 3.13 )




###########################################################
# project name
# It is to name your project.
###########################################################
message("### Build project.cpp.binary ###")
set(PROJECT_BINARY_VERSION "1.0.0")

# define binary/library names
set(PROJECT_TARGET_BINARY project_c_binary)
set(PROJECT_TARGET_LIBRARY_TEST project_c_lib)
set(PROJECT_TARGET_TEST project_c_test)

project(${PROJECT_TARGET_BINARY} LANGUAGES C VERSION ${PROJECT_BINARY_VERSION} DESCRIPTION "A simple C application with tests.")

# print architecture
message (STATUS "System=${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION} ${CMAKE_SYSTEM_PROCESSOR}")

# enable tests
enable_testing()





###########################################################
# flags
# This section is to tell CMake which compiler and compiler version you wish to build your project with. If you don’t set anything, it will pick the best fit on its own.
###########################################################
message(STATUS "### Flags ###")

# set C standard
# set(CMAKE_C_STANDARD 17) # requires cmake version 3.21. using -std
# -g = Produce debugging information in the operating system’s native format
# -O0 = no optimization
# -std=c17 = enables/limits build to the C17 standard.
# -Wall = enables all the warnings about constructions that some users consider questionable
set(CMAKE_C_FLAGS "-g -O0 -std=c17 -Wall")
# https://newbedev.com/cmake-gcov-c-creating-wrong-gcno-files
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE ON)

message(STATUS "CMAKE_C_FLAGS=${CMAKE_C_COMPILER} ${CMAKE_C_FLAGS} ${COMPILE_FLAGS}")


###########################################################
# components to build
###########################################################
add_subdirectory(src)
add_subdirectory(test)
