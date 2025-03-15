cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

# Include the "include" directory
include_directories(include)

# Automatically find and compile all .cpp files
file(GLOB SOURCES "src/*.cpp" "!src/tempCodeRunnerFile.cpp")

# Create an executable
add_executable(program ${SOURCES} "include/input/Menu.h" "src/input/Menu.cpp" "include/Config.h" "src/Config.cpp")