file(GLOB_RECURSE CPP_SRC_LIST *.cpp)
foreach(v ${CPP_SRC_LIST})
    string(REGEX MATCH "test/.*" relative_path ${v})
    string(REGEX REPLACE "test/" "" target_name ${relative_path})
    string(REGEX REPLACE "_test.cpp" "" target_name ${target_name})
    add_executable(${target_name}_unittest ${v})
    target_link_libraries(${target_name}_unittest gtest_main cppbase)
    add_test(
        NAME   
            ${target_name}_unittest
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/${target_name}_unittest
    )
endforeach()