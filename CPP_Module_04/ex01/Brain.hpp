#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "colors.h"
#include <iostream>

class Brain {
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain &other);
		~Brain();

		Brain &operator=(const Brain &other);

		std::string getIdea(int index) const;
		void setIdea(int index, const std::string &idea);
};

#endif // BRAIN_HPP
