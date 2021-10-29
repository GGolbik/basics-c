###########################################################
# cmake version to be used
# It is just to tell CMake which version of the tool it shall use.
###########################################################
cmake_minimum_required( VERSION 3.13 )

###########################################################
# project name
# It is to name your project.
###########################################################
message("### Build project.c.binary ###")
set(PROJECT_BINARY_VERSION "1.0.0")
project(project_c_binary VERSION ${PROJECT_BINARY_VERSION} DESCRIPTION "A simple C application.")

message (STATUS "System=${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION} ${CMAKE_SYSTEM_PROCESSOR}")

###########################################################
# flags
# This section is to tell CMake which compiler and compiler version you wish to build your project with. If you don’t set anything, it will pick the best fit on its own.
###########################################################
#message(STATUS "### Flags ###")
#message(STATUS "CMAKE_C_FLAGS=${CMAKE_C_FLAGS}")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11 -Wall" )
#message(STATUS "CMAKE_C_FLAGS=${CMAKE_C_FLAGS}")

###########################################################
# files
# In this section we basically specify all the files and club then into sensible variable names like source, include, etc. It is just to ease things out, but if you wish you can totally skip this section and use the file names directly instead of the variables.
###########################################################
message(STATUS "### Files ###")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")

# Find all source files
file(GLOB_RECURSE PROJECT_C_BINARY_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.c")
message(STATUS "PROJECT_C_BINARY_SOURCES=${PROJECT_C_BINARY_SOURCES}")

# Find all header files
file(GLOB_RECURSE PROJECT_C_BINARY_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.h" "include/*.h" )
message(STATUS "PROJECT_C_BINARY_HEADERS=${PROJECT_C_BINARY_HEADERS}")

###########################################################
# target
# This is the part where we tell CMake the name of the output file, in our case we wish to name it as binary. Whatever files names follow after that are basically your source files same way as you do while compiling them manually.
###########################################################
message(STATUS "### Target ###")
# defines our binary with all linked source files.
add_executable(project_c_binary ${PROJECT_C_BINARY_HEADERS} ${PROJECT_C_BINARY_SOURCES} )
# set version number
set_target_properties(project_c_binary PROPERTIES VERSION ${PROJECT_BINARY_VERSION})

###########################################################
# include
# This command is used to specify the path of the include directories that you want the compiler to look into while searching for header files while compiling your code. This will also include the header files from 3rd party libraries as we have done for Randomize and Logger.
###########################################################
# include of this project
target_include_directories(project_c_binary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src)

###########################################################
# external libs
# This part is what we call linking in compilation terms. So what you have done is you have included the header files of these 3rd party libraries and now you need to tell the compiler where exactly are these libraries located.
###########################################################

###########################################################
# install
# The TARGETS form specifies rules for installing targets from a project. There are several kinds of target files that may be installed:
###########################################################
message(STATUS "### Install ###")
install(TARGETS project_c_binary RUNTIME DESTINATION bin)