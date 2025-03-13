#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << GREEN << "Animal constructor called" << RESET << std::endl;
}

Animal::Animal(const std::string &type) : _type(type) {
    std::cout << GREEN << "Animal constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
    std::cout << GREEN << "Animal copy constructor called" << RESET << std::endl;
}

Animal::~Animal() {
    std::cout << RED << "Animal destructor called" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
    if (this != &animal) {
        _type = animal._type;
    }
    return *this;
}

std::string Animal::getType() const {
    return _type;
}

void Animal::makeSound() const {
    std::cout << MAGENTA << "~ Animal sound ~" << RESET << std::endl;
}
