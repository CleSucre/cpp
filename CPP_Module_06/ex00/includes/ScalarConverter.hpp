#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
  	private:
        bool isPrintable(int value) const;
        bool isInt(const std::string &value) const;
        bool isFloat(const std::string &value) const;
        bool isDouble(const std::string &value) const;
        bool isChar(const std::string &value) const;

    public:
        ScalarConverter();
        ~ScalarConverter();

        static void convert(std::string value);
};

#endif // SCALARCONVERTER_HPP
