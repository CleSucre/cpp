#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "colors.h"
#include "ICharacter.hpp"
#include <iostream>

class AMateria {
	protected:
		std::string _type;

    public:
		explicit AMateria(std::string const & type);
		AMateria(AMateria const &other);
		virtual ~AMateria();

		AMateria &operator=(AMateria const &);

		std::string const &getType() const;

		virtual void use(ICharacter &target);

		virtual AMateria* clone() const = 0;
};

#endif //AMATERIA_HPP
