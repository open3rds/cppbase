cmake_minimum_required(VERSION 3.16)
include(FetchContent)
#### CPP related
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_COMPILER /usr/bin/gcc-11)
set(CMAKE_CXX_COMPILER /usr/bin/g++-11)
# set(CMAKE_C_COMPILER /usr/bin/clang-15)
# set(CMAKE_CXX_COMPILER /usr/bin/clang++-15)

#### output to the same directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(app C CXX)


FetchContent_Declare(
        cppbase
        GIT_REPOSITORY https://github.com/open3rds/cppbase.git
        GIT_TAG v0.0.2
)
FetchContent_MakeAvailable(cppbase)

add_executable(app
    app.cpp
)

target_link_libraries(app PUBLIC cppbase)