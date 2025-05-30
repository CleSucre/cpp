#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

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

class Zombie {
	private:
    	std::string	_name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void		announce();
		void		setName(std::string name);
		std::string	getName();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif //ZOMBIE_HPP
