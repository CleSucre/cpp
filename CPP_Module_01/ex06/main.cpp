#include "Harl.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <log level>" << std::endl;
		return 1;
	}

	Harl harl(argv[1]);

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	return 0;
}
