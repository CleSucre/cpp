#include "Fixed.hpp"

Fixed::Fixed() {
    this->_value = 0;
    std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(int const value) {
    this->_value = value << this->_fractionalBits;
    std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(float const value) {
    this->_value = roundf(value * (1 << this->_fractionalBits));
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

bool    Fixed::operator>(const Fixed &src) const {
    return this->_value > src.getRawBits();
}

bool    Fixed::operator<(const Fixed &src) const {
    return this->_value < src.getRawBits();
}

bool    Fixed::operator>=(const Fixed &src) const {
    return this->_value >= src.getRawBits();
}

bool    Fixed::operator<=(const Fixed &src) const {
    return this->_value <= src.getRawBits();
}

bool    Fixed::operator==(const Fixed &src) const {
    return this->_value == src.getRawBits();
}

bool    Fixed::operator!=(const Fixed &src) const {
    return this->_value != src.getRawBits();
}

Fixed Fixed::operator+(const Fixed &src) {
    return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) {
    return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) {
    return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) {
    return Fixed(this->toFloat() / src.toFloat());
}

Fixed &Fixed::operator++() {
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->_value++;
    return tmp;
}

Fixed &Fixed::operator--() {
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->_value--;
    return tmp;
}

Fixed Fixed::min(Fixed &a, Fixed &b) {
    return a < b ? a : b;
}

Fixed Fixed::min(Fixed const &a, Fixed const &b) {
    return a < b ? a : b;
}

Fixed Fixed::max(Fixed &a, Fixed &b) {
    return a > b ? a : b;
}

Fixed Fixed::max(Fixed const &a, Fixed const &b) {
    return a > b ? a : b;
}

void Fixed::print() {
    std::cout << this->toFloat() << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << GREEN << "getRawBits member function called" << RESET << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << BLUE << "setRawBits member function called" << RESET << std::endl;
    this->_value = raw;
}

float Fixed::toFloat() const {
    return (float)this->_value / (1 << this->_fractionalBits);
}

int Fixed::toInt() const {
    return this->_value >> this->_fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &src) {
    out << src.toFloat();
    return out;
}
