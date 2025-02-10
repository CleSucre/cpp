#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define RESET		"\033[0m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define MAGENTA		"\033[35m"
#define CYAN		"\033[36m"
#define WHITE		"\033[37m"
#define BOLD		"\033[1m"
#define UNDERLINE	"\033[4m"

class ClapTrap {
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		ClapTrap();
		explicit ClapTrap(const std::string &name);
		explicit ClapTrap(const std::string &name, unsigned int hitpoints, unsigned int energyPoints, unsigned int attackDamage);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap &other);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif //CLAPTRAP_HPP
