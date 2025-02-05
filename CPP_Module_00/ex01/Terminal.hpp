#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <cstdlib>
#include "PhoneBook.hpp"

class Terminal {
	private:
		PhoneBook	_phoneBook;

		std::string	_getInput(std::string prompt, bool number_only = false);
		bool        _addContact(void);
		bool        _searchContact(void);

	public:
		Terminal(void);
		~Terminal(void);

		void		loop(void);

};

#endif //TERMINAL_HPP
