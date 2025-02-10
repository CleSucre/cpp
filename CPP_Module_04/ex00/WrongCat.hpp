#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		explicit WrongCat(const std::string &type);
		~WrongCat();

		void makeSound() const;
};

#endif //WRONGCAT_HPP
