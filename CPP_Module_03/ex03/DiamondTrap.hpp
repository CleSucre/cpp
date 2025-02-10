#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	_name;

	public:
          DiamondTrap();
          explicit DiamondTrap(const std::string &name);
          ~DiamondTrap();

          using ScavTrap::attack;

          void whoAmI();
};

#endif //DIAMONDTRAP_HPP
