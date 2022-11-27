set_project("open3rd-cpp-demo")
set_version("v0.0.1")

add_requires("gtest")

target("cppbase")
    set_kind("shared")
    set_languages("c++20")
    add_files("src/*.cpp")
    add_headerfiles("include/(cppbase/*.hpp)")
    add_includedirs("include")

target("test")
    set_kind("binary")
    add_files("test/*.cpp")
    set_languages("c++20")
    add_deps("cppbase")
    add_packages("gtest")
    add_includedirs("include")
    if is_plat("linux", "macosx") then
        add_links("pthread", "m", "dl")
    end

