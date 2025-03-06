#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

#define INVENTORY_SIZE 4

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria* _inventory[INVENTORY_SIZE];

		void initInventory();
		bool isSlotEmpty(const int idx) const;

	public:
		Character();
		explicit Character(const std::string &name);
		Character(Character const &other);
		virtual ~Character();

		Character &operator=(const Character &other);

		const std::string &getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif //CHARACTER_HPP
