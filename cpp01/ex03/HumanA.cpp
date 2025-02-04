#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::setName(std::string name) {
	this->_name = name;
}

std::string HumanA::getName() {
	return this->_name;
}

void HumanA::setWeapon(Weapon &weapon) {
	this->_weapon = weapon;
}

Weapon &HumanA::getWeapon() {
	return this->_weapon;
}

void HumanA::attack() {
	std::cout << MAGENTA << this->_name << BLUE << " attacks with their " << YELLOW << this->_weapon.getType() << RESET << std::endl;
}
