#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		explicit FragTrap(const std::string &name);
		~FragTrap();

		void highFivesGuys();
};

#endif //FRAGTRAP_HPP
