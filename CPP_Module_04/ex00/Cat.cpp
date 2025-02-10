#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type) {
  std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
}

Cat::~Cat() {
  std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const {
  std::cout << MAGENTA << "~ Meow meow ~" << RESET << std::endl;
}
