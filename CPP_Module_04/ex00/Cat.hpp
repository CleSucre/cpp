#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		explicit Cat(const std::string &type);
		~Cat();

		void makeSound() const;
};

#endif //CAT_HPP
