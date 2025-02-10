#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		explicit Dog(const std::string &type);
		~Dog();

		void makeSound() const;
};

#endif //DOG_HPP
