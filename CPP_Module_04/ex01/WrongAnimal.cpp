#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << GREEN << "WrongAnimal constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
	std::cout << GREEN << "WrongAnimal constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
	std::cout << GREEN << "WrongAnimal constructor called" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "WrongAnimal destructor called" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {
	if (this != &animal) {
		_type = animal._type;
	}
	return *this;
}

std::string WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound() const {
	std::cout << MAGENTA << "~ WrongAnimal sound ~" << RESET << std::endl;
}
