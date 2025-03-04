#include "Fixed.hpp"

Fixed::Fixed() {
    this->_value = 0;
    std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << CYAN << "Copy constructor called" << RESET << std::endl;
    *this = src;
}

Fixed::~Fixed() {
    std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src) {
    std::cout << MAGENTA << "Assignation operator called" << RESET << std::endl;
    if (this != &src)
        this->_value = src.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << GREEN << "getRawBits member function called" << RESET << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << BLUE << "setRawBits member function called" << RESET << std::endl;
    this->_value = raw;
}
