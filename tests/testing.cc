#include <gtest/gtest.h>
#include "../utils/mathutils.h"

TEST(AdditionTest, Adding){
    EXPECT_EQ(my_math::add(2,3), 7);
}
TEST(AdditionTest, AddingFailed){
    EXPECT_EQ(my_math::add(2,3), 9);
}
