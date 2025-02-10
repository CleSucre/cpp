#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
	std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << GREEN << "Cat copy constructor called" << RESET << std::endl;
	if (other._brain)
		this->_brain = new Brain(*other._brain);
	else
		this->_brain = NULL;
}

Cat::~Cat() {
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
	delete this->_brain;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		std::cout << YELLOW << "Cat assignment operator called." << RESET << std::endl;
		this->_type = other._type;
		delete this->_brain;
		if (other._brain)
			this->_brain = new Brain(*other._brain);
		else
			this->_brain = NULL;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << MAGENTA << "~ Meow meow ~" << RESET << std::endl;
}

Brain *Cat::getBrain() const {
	if (!this->_brain) {
		std::cerr << RED << "Warning: This Cat has no Brain!" << RESET << std::endl;
		return NULL;
	}
	return this->_brain;
}
