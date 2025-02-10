#include "../includes/AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(AMateria const &other) : _type(other._type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(AMateria const &) {
    return *this;
}

std::string const &AMateria::getType() const {
    return this->_type;
}
