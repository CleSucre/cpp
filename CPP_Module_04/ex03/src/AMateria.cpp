#include "AMateria.hpp"
#include "colors.h"

AMateria::AMateria(const std::string &type) : _type(type) {}

AMateria::AMateria(const AMateria &other) : _type(other._type) {}

AMateria::~AMateria() {
	std::cout << YELLOW << "Materia " << MAGENTA << this->_type << YELLOW << " destroyed" << RESET << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
	(void)other;
	return *this;
}

const std::string &AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter &target) {
	(void)target;
}
