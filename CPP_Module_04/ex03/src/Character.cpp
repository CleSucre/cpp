#include "Character.hpp"
#include "colors.h"

void Character::initInventory() {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character() : _name("default") {
	this->initInventory();
}

Character::Character(const std::string &name) : _name(name) {
	this->initInventory();
	std::cout << GREEN << "Character " << MAGENTA << this->_name << RESET << std::endl;
}

Character::Character(Character const &other) {
	this->_name = other._name;
	this->initInventory();
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (other._inventory[i]) {
			this->_inventory[i] = other._inventory[i]->clone();
		}
	}
}

Character::~Character() {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (this->_inventory[i]) {
			delete this->_inventory[i];
		}
	}
	std::cout << YELLOW << "Character " << MAGENTA << this->_name << YELLOW << " destroyed" << RESET << std::endl;
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			if (other._inventory[i]) {
				this->_inventory[i] = other._inventory[i]->clone();
			} else {
				this->_inventory[i] = NULL;
			}
		}
	}
	std::cout << GREEN << "Character " << MAGENTA << this->_name << GREEN << " copied" << RESET << std::endl;
	return *this;
}

bool Character::isSlotEmpty(const int idx) const {
	if (idx < 0 || idx >= INVENTORY_SIZE) {
		return true;
	}
	return this->_inventory[idx] == NULL;
}

const std::string &Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			std::cout << GREEN << this->_name << " equipped " << MAGENTA << m->getType() << GREEN << " to slot " << MAGENTA << i << RESET << std::endl;
			return;
		}
	}
	std::cout << RED << this->_name << " tried to equip a full inventory." << RESET << std::endl;
}

void Character::unequip(const int idx) {
	if (this->isSlotEmpty(idx)) {
		return;
	}
	this->_inventory[idx] = NULL;
	std::cout << GREEN << this->_name << " unequipped slot " << MAGENTA << idx << RESET << std::endl;
}

void Character::use(const int idx, ICharacter &target) {
	if (this->isSlotEmpty(idx)) {
		std::cout << RED << this->_name << " tried to use " << MAGENTA << idx << RESET << RED << " which is empty." << RESET << std::endl;
		return;
	}
	AMateria *materia = this->_inventory[idx];
	materia->use(target);
}
