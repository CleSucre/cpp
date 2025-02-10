#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
	std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
	if (other._brain)
		this->_brain = new Brain(*other._brain);
	else
		this->_brain = NULL;
}

Dog::~Dog() {
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		std::cout << YELLOW << "Dog assignment operator called." << RESET << std::endl;
		this->_type = other._type;
		delete this->_brain;
		if (other._brain)
			this->_brain = new Brain(*other._brain);
		else
			this->_brain = NULL;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << MAGENTA << "~ Woof woof ~" << RESET << std::endl;
}

Brain *Dog::getBrain() const {
	if (!this->_brain) {
		std::cerr << RED << "Warning: This Dog has no Brain!" << RESET << std::endl;
		return NULL;
	}
	return this->_brain;
}
