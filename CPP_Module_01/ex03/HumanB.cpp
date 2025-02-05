#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::setName(std::string name) {
	this->_name = name;
}

std::string HumanB::getName() {
	return this->_name;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

Weapon *HumanB::getWeapon() {
	return this->_weapon;
}

void HumanB::attack() {
	if (this->_weapon == NULL) {
		std::cout << MAGENTA << this->_name << BLUE << " has no weapon to attack with " YELLOW << "NONE" << RESET << std::endl;
	} else {
		std::cout << MAGENTA << this->_name << BLUE << " attacks with their " << YELLOW << this->_weapon->getType() << RESET << std::endl;
	}
}
