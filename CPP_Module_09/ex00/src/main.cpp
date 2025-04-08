#include "colors.h"
#include "Csv.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    std::cout << GREEN << "Bitcoin Exchange" << RESET << std::endl;

    if (argc <= 1) {
        std::cout << RED << "Usage: " << argv[0] << " [input.txt]" << RESET << std::endl;
        return 1;
    }

    std::ifstream data_file(DATA_FILE_NAME);
    if (!data_file.is_open()) {
        std::cout << RED << "Error: " << RESET << "Could not open file '" << DATA_FILE_NAME << "'" << std::endl;
        return 1;
    }

    Csv csv(data_file);
    csv.print();

    std::string content;

    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cout << RED << "Error: " << RESET << "Could not open file '" << argv[1] << "'" << std::endl;
        return 1;
    }
	//TODO: Input class
    input_file.close();

    return 0;
}
