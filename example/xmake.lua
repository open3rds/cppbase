
add_repositories("open3rds https://github.com/open3rds/xmake-repo main")
-- add_repositories("open3rds https://github.com/open3rds/xmake-repo experiment")
add_requires("cppbase 0.0.2", {alias = "cppbase"})

target("app")
    set_kind("binary")
    add_packages("cppbase")
    add_files("app.cpp")