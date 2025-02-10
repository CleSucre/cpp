#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << GREEN << "FragTrap constructed!" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name, 100, 100, 30) {
	std::cout << GREEN << "FragTrap " << this->_name << " constructed!" << RESET << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << RED << "FragTrap " << this->_name << " destroyed!" << RESET << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << CYAN << "FragTrap " << this->_name << " requests a high five!" << RESET << std::endl;
}
