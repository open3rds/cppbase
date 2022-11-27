cmake_minimum_required(VERSION 3.16)
include(FetchContent)
#### CPP related
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_COMPILER /usr/bin/gcc-11)
set(CMAKE_CXX_COMPILER /usr/bin/g++-11)
# set(CMAKE_C_COMPILER /usr/bin/clang-15)
# set(CMAKE_CXX_COMPILER /usr/bin/clang++-15)

project(open3rds-demo-cpp C CXX)

#### output to the same directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#### If you need threads
set(CMAKE_THREAD_PREFER_PTHREAD ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
FIND_PACKAGE(Threads)
# FIND_PACKAGE(Threads REQUIRED)
set(CPP3RD_HAVE_PTHREAD "${CMAKE_USE_PTHREADS_INIT}")
# please use TARGET_LINK_LIBRARIES(XXX ${CMAKE_THREAD_LIBS_INIT}) when you need pthread.

#### GTest
FetchContent_Declare(
  	googletest
  	GIT_REPOSITORY https://github.com/google/googletest.git
  	GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(googletest)

#### use —DCMAKE_BUILD_TYPE=DEBUG or —DCMAKE_BUILD_TYPE=RELEASE to use them
if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "$ENV{CXXFLAGS} ${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++20")
    # SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} ${CMAKE_CXX_FLAGS} -O0 -g2 -ggdb pthread")
    # SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O2 pthread")
    SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} ${CMAKE_CXX_FLAGS} -O0 -g2 -ggdb")
    SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O2")
endif()
if ( MSVC )
    set(CMAKE_CXX_FLAGS  "$ENV{CXXFLAGS} ${CMAKE_CXX_FLAGS} /W4 /std:c++20")
    SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} ${CMAKE_CXX_FLAGS} /O0 /DEBUG")
    SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} /O2")
endif()


#### PROJECT_SOURCE_DIR is the directory of current cmake path
include_directories(${PROJECT_SOURCE_DIR}/include)

enable_testing()
add_subdirectory(test)

file(GLOB_RECURSE CPP_SRC_LIST ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library(cppbase SHARED "")
target_sources(
    cppbase
    PRIVATE
           ${CPP_SRC_LIST}
)
target_include_directories(
    cppbase
    PUBLIC
        include
)