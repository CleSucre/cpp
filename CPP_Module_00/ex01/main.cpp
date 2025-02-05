#include "Terminal.hpp"

bool	is_number(std::string str)
{
    for (int i = str.length() - 1; i >= 0; i--)
    {
		if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

int	main(void) {
	Terminal	terminal;

	terminal.loop();
	return 0;
}
