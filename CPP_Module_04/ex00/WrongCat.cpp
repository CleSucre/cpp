#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << GREEN << "WrongCat constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type) {
	std::cout << GREEN << "WrongCat constructor called" << RESET << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << RED << "WrongCat destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << MAGENTA << "~ WrongCat ~" << RESET << std::endl;
}
