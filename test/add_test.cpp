#include <gtest/gtest.h>
#include <cppbase/add.hpp>

TEST(AddTest, AddInteger)
{
    EXPECT_EQ(open3rds::add(1, 2), 3);
    EXPECT_EQ(open3rds::add(1, 2, 3), 6);
    EXPECT_EQ(open3rds::add(1, 2, 3, 4), 10);
    EXPECT_EQ(open3rds::add(1, 2.125), 3.125 );
    EXPECT_EQ(open3rds::add(1, 2, 1.125) ,4.125);
    EXPECT_EQ(open3rds::add(1, 2, 3, 1.125), 7.125);
}

TEST(AddTest, DISABLED_AddFailDemo)
{
    EXPECT_EQ(open3rds::add(1, 1), 3);
}