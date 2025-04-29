#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << RED << "Usage: " << argv[0] << " <expression>" << RESET << std::endl;
        return 1;
    }

    try {
        int result = evaluateRPN(argv[1]);
        std::cout << GREEN << "Result: " << YELLOW << result << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        return 2;
    }

    return 0;
}
