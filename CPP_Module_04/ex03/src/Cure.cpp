#include "Cure.hpp"
#include <colors.h>

Cure::Cure() : AMateria("cure") {}

AMateria *Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter &target) {
	std::cout << GREEN << "* heals " << MAGENTA << target.getName() << GREEN << "'s wounds *" << RESET << std::endl;
}
