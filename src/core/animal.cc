#include "core/animal.h"

Animal::Animal(std::string name, int age)
:name(std::move(name)),age(age){};

const std::string& Animal::getName() const noexcept {
    return name;
}
void Animal::setName(const std::string& _name){
    name = _name;
}

void Animal::setName(std::string&& _name) noexcept{
    name = std::move(_name);
}
