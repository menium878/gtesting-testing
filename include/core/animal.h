#pragma once

#include <string>

class Animal{
public:
    Animal(std::string name, int age);
    ~Animal() = default;
    const std::string& getName() const noexcept;
    void setName(const std::string& name);
private:
    std::string name;
    int age;
};
