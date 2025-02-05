#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		std::string	_name;
		Weapon		&_weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void		setName(std::string name);
		void		setWeapon(Weapon &weapon);
		std::string	getName();
		Weapon		&getWeapon();

		void		attack();
};

#endif //HUMANA_HPP
