#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << GREEN << "Zombie constructor" << RESET << std::endl;
}

Zombie::Zombie(std::string name) {
	std::cout << GREEN << "Zombie constructor (" << name << ")" << RESET << std::endl;
	this->_name = name;
}

Zombie::~Zombie() {
	if (this->_name != "") {
		std::cout << RED << "Zombie destructor " << MAGENTA << this->_name << RESET << std::endl;
	} else {
		std::cout << RED << "Zombie destructor" << RESET << std::endl;
	}
}

void Zombie::setName(std::string name) {
	this->_name = name;
}

void Zombie::announce() {
	std::cout << MAGENTA << this->_name << RESET << ": " << BLUE << "BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
