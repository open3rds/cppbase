# CMake Version > v3.11
FetchContent_Declare(cppbase
        GIT_REPOSITORY https://github.com/open3rds/${python_module}.git
        GIT_TAG ${version})
FetchContent_MakeAvailable(cppbase)

add_executable(app
    app.cpp
)
target_link_libraries(app PRIVATE cppbase::cppbase)