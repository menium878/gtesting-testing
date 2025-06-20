#include <gtest/gtest.h>
#include "../main.cc"

TEST(AdditionTest, Adding){
    EXPECT_EQ(my_math::add(2,3), 7);
}
