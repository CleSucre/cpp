#include "Harl.hpp"

Harl::Harl() : _minLevel(0) {}  // ✅ Initialise `_minLevel` à 0 par défaut

Harl::Harl(std::string maxLevel) {
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

int Harl::_getLevelIndex(const std::string &level) {
	if (level == "DEBUG")   return 0;
	if (level == "INFO")    return 1;
	if (level == "WARNING") return 2;
	if (level == "ERROR")   return 3;
	return -1;
}

void Harl::complain(std::string level) {

	if (this->_minLevel == -1) {
		this->unknown(level);
		return;
	}

	int index = this->_getLevelIndex(level);

	if (index < this->_minLevel) {
		return;
	}

	switch (index) {
		case 0:
			this->debug();
		break;
		case 1:
			this->info();
		break;
		case 2:
			this->warning();
		break;
		case 3:
			this->error();
		break;
		default:
			this->unknown(level);
	}
}
