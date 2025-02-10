#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("default_clap_name"), ScavTrap("default"), FragTrap("default") {
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << GREEN << "DiamondTrap constructed!" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
	std::cout << GREEN << "DiamondTrap " << this->_name << " constructed!" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << RED << "DiamondTrap " << this->_name << " destroyed!" << RESET << std::endl;
}

void DiamondTrap::whoAmI() {
  	std::cout << CYAN << "DiamondTrap " << this->_name << " is also known as " << this->ClapTrap::_name << RESET << std::endl;
}
