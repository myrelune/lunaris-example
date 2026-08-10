cmake_minimum_required(VERSION 3.15)

project(particles LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(particles
    src/main.cpp
)

add_subdirectory(Lunaris)

target_include_directories(particles PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Lunaris/include
)

target_link_libraries(particles PRIVATE Lunaris)
