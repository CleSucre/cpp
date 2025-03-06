#include "Ice.hpp"
#include <colors.h>

Ice::Ice() : AMateria("ice") {
}

AMateria *Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter &target) {
	std::cout << GREEN << "* shoots an ice bolt at " << MAGENTA << target.getName() << GREEN << " *" << RESET << std::endl;
}
