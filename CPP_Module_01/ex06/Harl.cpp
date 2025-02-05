#include "Harl.hpp"

Harl::Harl() {}

Harl::Harl(std::string maxLevel) {
	this->_levels[0].level = "DEBUG";
	this->_levels[0].func = &Harl::debug;

	this->_levels[1].level = "INFO";
	this->_levels[1].func = &Harl::info;

	this->_levels[2].level = "WARNING";
	this->_levels[2].func = &Harl::warning;

	this->_levels[3].level = "ERROR";
	this->_levels[3].func = &Harl::error;

	this->_minLevel = this->_getLevelIndex(maxLevel);
}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << CYAN << "[ DEBUG ] " << RESET << "This is a debug message." << std::endl;
}

void Harl::info() {
	std::cout << GREEN << "[ INFO ] " << RESET << "This is an informational message." << std::endl;
}

void Harl::warning() {
	std::cout << YELLOW << "[ WARNING ] " << RESET << "This is a warning message!" << std::endl;
}

void Harl::error() {
	std::cout << RED << "[ ERROR ] " << RESET << "This is an error message!" << std::endl;
}

void Harl::unknown(std::string level) {
	std::cout << MAGENTA << "[ UNKNOWN ] " << RESET << "Invalid complaint level: " << level << std::endl;
}

int Harl::_getLevelIndex(std::string level) {
    for (int i = 0; i < 4; i++) {
        if (this->_levels[i].level == level) {
            return i;
        }
    }
    return -1;
}

void Harl::complain(std::string level) {
	int minLevel = this->_getLevelIndex(level);

	if (minLevel == -1) {
		this->unknown(level);
	}
	if (minLevel >= this->_minLevel) {
		(this->*_levels[minLevel].func)();
	}
}
