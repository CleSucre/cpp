#include "Brain.hpp"

Brain::Brain() {
	std::cout << GREEN << "Brain constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << GREEN << "Brain copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
}

Brain::~Brain() {
	std::cout << RED << "Brain destructor called" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	if (&other != this) {
		std::cout << YELLOW << "Brain assignment operator called" << RESET << std::endl;
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

std::string Brain::getIdea(const int index) const {
	if (index < 0 || index >= 100) {
		std::cerr << RED << "Error: Index out of bounds in getIdea()" << RESET << std::endl;
		return "";
	}
	return this->_ideas[index];
}

void Brain::setIdea(const int index, const std::string &idea) {
	if (index < 0 || index >= 100) {
		std::cerr << RED << "Error: Index out of bounds in setIdea()" << RESET << std::endl;
		return;
	}
	this->_ideas[index] = idea;
}
