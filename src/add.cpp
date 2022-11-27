#include <cppbase/add.hpp>
#include <cstdio>

namespace open3rds
{
    struct Init
    {
        Init()
        {
            printf("Hello, this is message from libadd");
        }
    };

    Init init;
}
