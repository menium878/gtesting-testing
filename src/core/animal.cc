#include "core/animal.h"

Animal::Animal(std::string name, int age)
:name(name),age(age){};

const std::string& Animal::getName() const noexcept {
    return name;
}
