#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "colors.h"
#include <iostream>

class WrongAnimal {
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		explicit WrongAnimal(const std::string &type);
		virtual ~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal &animal);

		std::string getType() const;

		void makeSound() const;
};

#endif //WRONGANIMAL_HPP
