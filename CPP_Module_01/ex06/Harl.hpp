#ifndef HARL_HPP
#define HARL_HPP

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

class Harl {
	private:
		int		_minLevel;

		void	debug();
		void	info();
		void	warning();
		void	error();
		void	unknown(std::string level);

		int		_getLevelIndex(const std::string &level);

	public:
		Harl();
		Harl(std::string maxLevel);
		~Harl();

		void	complain(std::string level);
};

#endif //HARL_HPP
