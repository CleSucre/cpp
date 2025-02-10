#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type) {
  std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
}

Dog::~Dog() {
  std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

void Dog::makeSound() const {
  std::cout << MAGENTA << "~ Woof woof ~" << RESET << std::endl;
}
