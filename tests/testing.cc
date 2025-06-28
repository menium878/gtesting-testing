#include <gtest/gtest.h>
#include <memory>
#include "utils/mathutils.h"
#include "core/animal.h"

TEST(AdditionTest, Adding){
    EXPECT_EQ(my_math::add(2,3), 7);
}
TEST(AdditionTest, AddingFailed){
    EXPECT_EQ(my_math::add(2,3), 9);
}
TEST(AnimalTest, AnimalTest){
    std::unique_ptr<Animal> animal = std::make_unique<Animal>("Cat",7);
    EXPECT_EQ(animal->getName(), "Cat");
    animal->setName("Dog");
    EXPECT_EQ(animal->getName(), "Dog");
}
