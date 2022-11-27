add_repositories("open3rds git@github.com:open3rds/xmake-repo.git main")
-- add_repositories("open3rds git@github.com:open3rds/xmake-repo.git experiment")
add_requires("open3rds::cppbase  1.0.x", {alias = "cppbase"})

target("app")
    set_kind("binary")
    add_files("app.cpp")
    add_packages("cppbase")