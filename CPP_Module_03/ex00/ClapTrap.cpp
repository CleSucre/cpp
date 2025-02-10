#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << GREEN << "ClapTrap constructed!" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << GREEN << "ClapTrap " << this->_name << " constructed!" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, const unsigned int hitpoints, const unsigned int energyPoints, const unsigned int attackDamage)
    : _name(name), _hitPoints(hitpoints), _energyPoints(energyPoints), _attackDamage(attackDamage) {
    std::cout << GREEN << "ClapTrap " << this->_name << " constructed!" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << GREEN << "ClapTrap " << other._name << " copied!" << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
        std::cout << GREEN << "ClapTrap " << other._name << " assigned!" << RESET << std::endl;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << RED << "ClapTrap " << this->_name << " destroyed!" << RESET << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (this->_energyPoints == 0) {
        std::cout << RED << "ClapTrap " << this->_name << " is out of energy!" << RESET << std::endl;
        return;
    }
    if (this->_hitPoints == 0) {
        std::cout << RED << "ClapTrap " << this->_name << " is dead and cannot attack!" << RESET << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << YELLOW << "ClapTrap " << this->_name << " attacks " << target
                << ", causing " << this->_attackDamage << " points of damage!"
                << " Energy points left: " << this->_energyPoints << RESET << std::endl;
}

void ClapTrap::takeDamage(const unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << RED << "ClapTrap " << this->_name << " is already dead!" << RESET << std::endl;
        return;
    }
    if (amount >= this->_hitPoints) {
        this->_hitPoints = 0;
        std::cout << RED << "ClapTrap " << this->_name << " takes " << amount << " points of damage and dies!" << RESET << std::endl;
        return;
    }
    this->_hitPoints -= amount;
    std::cout << BLUE << "ClapTrap " << this->_name << " takes " << amount << " points of damage!"
                << " Hitpoints left: " << this->_hitPoints << RESET << std::endl;
}

void ClapTrap::beRepaired(const unsigned int amount) {
    if (this->_energyPoints == 0) {
        std::cout << RED << "ClapTrap " << this->_name << " is out of energy and cannot be repaired!" << RESET << std::endl;
        return;
    }
    if (this->_hitPoints == 0) {
        std::cout << RED << "ClapTrap " << this->_name << " is dead and cannot be repaired!" << RESET << std::endl;
        return;
    }
    this->_energyPoints--;
    this->_hitPoints += amount;
    std::cout << CYAN << "ClapTrap " << this->_name << " is repaired for " << amount << " hitpoints!"
                << " Hitpoints left: " << this->_hitPoints << RESET << std::endl;
}
