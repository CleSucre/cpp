#include "Harl.hpp"

Harl::Harl() : _minLevel(0) {}

Harl::Harl(std::string maxLevel) {
	this->_minLevel = this->_getLevelIndex(maxLevel);
	if (this->_minLevel == -1) {
		this->unknown(maxLevel);
	}
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

int	Harl::_getLevelIndex(const std::string &level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			return i;
		}
	}
	return -1;
}

void Harl::complain(std::string level) {
	if (this->_minLevel == -1) {
		return;
	}

	int levelIndex = this->_getLevelIndex(level);
	if (levelIndex < this->_minLevel) {
		return;
	}

	switch (levelIndex) {
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
	}
}
