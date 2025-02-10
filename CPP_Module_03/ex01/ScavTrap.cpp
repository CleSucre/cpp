#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name, 100, 50, 20), _isGuardGateMode(false) {
    std::cout << GREEN << "ScavTrap " << this->_name << " constructed!" << RESET << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << RED << "ScavTrap " << this->_name << " destroyed!" << RESET << std::endl;
}

void ScavTrap::guardGate() {
    this->_isGuardGateMode = true;
    std::cout << CYAN << "ScavTrap " << this->_name << " has entered in Gate keeper mode!" << RESET << std::endl;
}
