#include <iostream>
#include <memory>
#include "../include/utils/mathutils.h"
#include "core/animal.h"
int main(){
    std::cout << my_math::add(2,3) <<"\n";
    std::shared_ptr<Animal> dog = std::make_shared<Animal>("Max",7);
    return 0;
}
