#include "BitcoinExchange.hpp"

int main(int argc, const char * argv[]) {
    if (argc <= 1) {
        std::cout << RED << "Usage: " << argv[0] << " [input.txt]" << RESET << std::endl;
        return 1;
    }

    std::ifstream data_file(DATA_FILE_NAME);
    if (!data_file.is_open()) {
        std::cout << RED << "Error: " << RESET << "Could not open file '" << DATA_FILE_NAME << "'" << std::endl;
        return 2;
    }
    BitcoinExchange btc(data_file);
    data_file.close();

    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cout << RED << "Error: " << RESET << "Could not open file '" << argv[1] << "'" << std::endl;
        return 3;
    }
    btc.processInput(input_file);

    input_file.close();

    return 0;
}
