#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "colors.h"
#include <iostream>

class Animal {
	protected:
		std::string	_type;

	public:
		Animal();
		explicit Animal(const std::string &type);
        Animal(const Animal &other);
		virtual ~Animal();

		Animal &operator=(const Animal &animal);

		std::string getType() const;
		virtual void makeSound() const;
};

#endif //ANIMAL_HPP
