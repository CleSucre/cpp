#include "../includes/Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &other) : AMateria(other) {}

Ice::~Ice() {}

Ice &Ice::operator=(Ice const &other) {
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
