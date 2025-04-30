#include "ScalarConverter.hpp"
#include "colors.h"
#include <cstdlib>
#include <climits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isPrintable(int value) const {
    return value >= 32 && value <= 126;
}

bool ScalarConverter::isChar(const std::string &value) const {
    return value.length() == 1 && !isdigit(value[0]);
}

bool ScalarConverter::isInt(const std::string &value) const {
    if (value.empty()) {
        return false;
    }

    size_t i = 0;
    if (value[0] == '-' || value[0] == '+') {
        i++;
    }

    if (i == value.length()) {
        return false;
    }

    for (; i < value.size(); i++) {
        if (!isdigit(value[i])) {
            return false;
        }
    }

    return true;
}

bool ScalarConverter::isFloat(const std::string &value) const {
    if (value.empty()) {
        return false;
    }

    if (value == "nanf" || value == "+inff" || value == "inff" || "-inff") {
        return true;
    }

    size_t i = 0;
    if (value[0] == '-' || value[0] == '+') {
        i++;
    }

    bool hasDot = false;
    bool hasF = false;
    bool hasDigit = false;
    for (; i < value.size(); i++) {
        if (isdigit(value[i])) {
            hasDigit = true;
        } else if (value[i] == '.') {
            if (hasDot) {
                return false;
            }
            hasDot = true;
        } else if (value[i] == 'f') {
            if (hasF || i != value.size() - 1) {
                return false;
            }
            hasF = true;
        } else {
            return false;
        }
    }

    return hasDot && hasF && hasDigit;
}

bool ScalarConverter::isDouble(const std::string &value) const {
    if (value.empty()) {
        return false;
    }

    if (value == "nan" || value == "+inf" || value == "inf" || value == "-inf") {
        return true;
    }

    size_t i = 0;
    if (value[0] == '-' || value[0] == '+') {
        i++;
    }

    bool hasDot = false;
    bool hasDigit = false;
    for (; i < value.size(); i++) {
        if (isdigit(value[i])) {
            hasDigit = true;
        } else if (value[i] == '.') {
            if (hasDot) {
                return false;
            }
            hasDot = true;
        } else {
            return false;
        }
    }

    return hasDot && hasDigit;
}

void ScalarConverter::convert(std::string value) {
    ScalarConverter instance;

    if (instance.isChar(value)) {
        std::cout << GREEN << "Converting " << YELLOW << "char: " << MAGENTA << value.c_str() << RESET << std::endl;
        char c = value[0];
        std::cout << YELLOW << "char: '" << MAGENTA << c << YELLOW << "'" << RESET << std::endl;
        std::cout << YELLOW << "int: " << MAGENTA << static_cast<int>(c) << RESET << std::endl;
        std::cout << YELLOW << "float: " << MAGENTA << static_cast<float>(c) << ".0f" << RESET << std::endl;
        std::cout << YELLOW << "double: " << MAGENTA << static_cast<double>(c) << ".0" << RESET << std::endl;
        return;
    }

    if (instance.isInt(value)) {
        std::cout << GREEN << "Converting " << YELLOW << "int: " << MAGENTA << value.c_str() << RESET << std::endl;
        int intValue = std::atoi(value.c_str());

        std::cout << YELLOW << "char: ";
        if (instance.isPrintable(intValue)) {
            std::cout << "'" << MAGENTA << static_cast<char>(intValue) << YELLOW << "'" << RESET << std::endl;
        } else {
            std::cout << "Non displayable" << RESET << std::endl;
        }

        std::cout << YELLOW << "int: " << MAGENTA << intValue << RESET << std::endl;
        std::cout << YELLOW << "float: " << MAGENTA << static_cast<float>(intValue) << ".0f" << RESET << std::endl;
        std::cout << YELLOW << "double: " << MAGENTA << static_cast<double>(intValue) << ".0" << RESET << std::endl;
        return;
    }

    if (instance.isFloat(value) || instance.isDouble(value)) {
        if (instance.isFloat(value)) {
            std::cout << GREEN << "Converting " << YELLOW << "float: " << MAGENTA << value.c_str() << RESET << std::endl;
        } else {
            std::cout << GREEN << "Converting " << YELLOW << "double: " << MAGENTA  << value.c_str() << RESET << std::endl;
        }

        double doubleValue = std::strtod(value.c_str(), NULL);
        float floatValue = static_cast<float>(doubleValue);

        std::cout << YELLOW << "char: ";
        if (instance.isPrintable(static_cast<int>(doubleValue))) {
            std::cout << MAGENTA << "'" << static_cast<char>(doubleValue) << "'" << RESET << std::endl;
        } else {
            std::cout << RED << "Non displayable" << RESET << std::endl;
        }

        if (doubleValue > INT_MAX || doubleValue < INT_MIN) {
            std::cout << RED << "int: impossible" << RESET << std::endl;
        } else {
            std::cout << YELLOW << "int: " << MAGENTA << static_cast<int>(doubleValue) << RESET << std::endl;
        }

        std::cout << YELLOW << "float: " << MAGENTA << floatValue;
        if (floatValue == static_cast<int>(floatValue)) {
            std::cout << ".0";
        }
        std::cout << "f" << RESET << std::endl;

        std::cout << YELLOW << "double: " << MAGENTA << doubleValue;
        if (doubleValue == static_cast<int>(doubleValue)) {
            std::cout << ".0";
        }
        std::cout << RESET << std::endl;
        return;
    }

    std::cout << RED << "Conversion failed" << RESET << std::endl;
}
