#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

const int INVENTORY_SIZE = 4;

class Character {
	private:
		std::string _name;
		AMateria* _inventory[INVENTORY_SIZE];

        bool isSlotEmpty(const int idx) const;

	public:
		Character();
		explicit Character(const std::string &name);
		Character(Character &other);
        virtual ~Character();

		Character &operator=(const Character &other);

		const std::string &getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif //CHARACTER_HPP
