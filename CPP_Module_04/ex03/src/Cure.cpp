#include "../includes/Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &other) : AMateria(other) {}

Cure::~Cure() {}

Cure &Cure::operator=(Cure const &other) {
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}
