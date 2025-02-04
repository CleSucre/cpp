#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <map>

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

class Harl {
	private:
		struct Level {
			std::string	level;
			void (Harl::*func)();
		};

		Level _levels[4];

		void	debug();
		void	info();
		void	warning();
		void	error();

	public:
		Harl();
		~Harl();

		void	complain(std::string level);
};

#endif //HARL_HPP
