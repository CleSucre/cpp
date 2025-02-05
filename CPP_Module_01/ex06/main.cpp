#include "Harl.hpp"
#include <cstring>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <log level>" << std::endl;
		return 1;
	}

	if (strcmp(argv[1], "DEBUG") != 0 && strcmp(argv[1], "INFO") != 0 && strcmp(argv[1], "WARNING") != 0 && strcmp(argv[1], "ERROR") != 0) {
        std::cerr << "Invalid log level: " << argv[1] << std::endl;
        return 1;
    }

	Harl harl(argv[1]);

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("unknown");

	return 0;
}
