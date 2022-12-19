
cmake_minimum_required(VERSION 3.11.0)
project(tower_defence_game VERSION 0.1.0)

enable_language(CXX)

# use C++ standard version 17
set(CMAKE_CXX_STANDARD 17)
# produce non-optimized code with debug symbols
set(CMAKE_BUILD_TYPE Debug)

message(STATUS "BUILD directory is ${CMAKE_BINARY_DIR}")
message(STATUS "SRC directory is ${CMAKE_SOURCE_DIR}")

# Add all .c, - files under src/ directory
file(GLOB SOURCES_C "src/*.c")
# Add all .cpp, - files under src/ directory
file(GLOB SOURCES_CPP "src/*.cpp")
# Add all .hpp, - files under src/ directory
file(GLOB SOURCES_HPP "src/*.hpp")
# Add all .h, - files under src/ directory
file(GLOB SOURCES_H "src/*.h")
set(SOURCES ${SOURCES_C} ${SOURCES_CPP} ${SOURCES_H} ${SOURCES_HPP})
message(STATUS "SRC directory source code files: \n\t-- HEADERS: ${SOURCES_H}${SOURCES_HPP}\n\t-- C SOURCES: ${SOURCES_C}\n\t-- CPP SOURCE:${SOURCES_CPP}\n\t-- ALL:${SOURCES}")


# add the executable target
add_executable(tower_defence_game)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set (SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS audio graphics system window)

target_link_libraries(tower_defence_game PRIVATE sfml-audio sfml-graphics sfml-system sfml-window)

target_sources(tower_defence_game PUBLIC ${SOURCES})
target_include_directories(tower_defence_game PUBLIC .)
target_include_directories(tower_defence_game PUBLIC src)
target_include_directories(tower_defence_game PUBLIC libs)

# get a lot of warnings
if(MSVC)
    target_compile_options(tower_defence_game PRIVATE /Wall)
else()
    # gcc and clang
    target_compile_options(tower_defence_game PRIVATE -Wall -Wextra -pedantic -Wno-missing-field-initializers)
endif()