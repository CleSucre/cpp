#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	protected:
		bool	_isGuardGateMode;

	public:
        explicit ScavTrap(const std::string &name);
        ~ScavTrap();

		void guardGate();
};

#endif //SCAVTRAP_HPP
