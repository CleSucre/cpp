#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria {
    protected:
        const std::string _type;

    public:
        AMateria(const std::string &type);
        AMateria(const AMateria &other);
        virtual ~AMateria();

        AMateria &operator=(const AMateria &other);

        const std::string &getType() const;

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif //AMATERIA_HPP
