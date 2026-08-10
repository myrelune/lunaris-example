i use zed, so to get the language server to actually pick up the header file i had to add this to the cmakelists.txt

target_include_directories(particles PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Lunaris/include
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

then, i used ninja to build.
cmake -B build -G "Ninja" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release
im not sure how other ides do it
