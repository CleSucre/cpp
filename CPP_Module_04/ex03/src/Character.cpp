#include "../includes/Character.hpp"
#include <AMateria.hpp>

Character::Character() : _name(""), _inventory{nullptr} {}

Character::Character(const std::string &name) : _name(name) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		this->_inventory[i] = nullptr;
	}
}

Character::Character(Character &other) {
	*this = other;
}

Character::~Character() {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		AMateria *m = this->_inventory[i];
		if (m != nullptr) {
			delete m;
		}
	}
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			if (other._inventory[i]) {
				this->_inventory[i] = other._inventory[i]->clone();
			} else {
				this->_inventory[i] = nullptr;
			}
		}
	}
	return *this;
}

const std::string &Character::getName() const {
	return this->_name;
}

bool Character::isSlotEmpty(const int idx) const {
	if (idx < 0 || idx >= INVENTORY_SIZE) {
		return true;
	}
	return this->_inventory[idx] == nullptr;
}


void Character::equip(AMateria *m) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (this->_inventory[i] == nullptr) {
			this->_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(const int idx) {
	if (this->isSlotEmpty(idx)) {
		return;
	}
	this->_inventory[idx] = nullptr;
}

void Character::use(const int idx, ICharacter &target) {
	if (this->isSlotEmpty(idx)) {
		return;
	}
	AMateria *materia = this->_inventory[idx];
	materia->use(target);
}
