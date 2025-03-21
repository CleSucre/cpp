#include "Span.hpp"
#include "colors.h"
#include <iostream>
#include <ctime>

int main() {
    std::cout << CYAN << BOLD << "=== Span Test ===" << RESET << std::endl;

    try {
        std::cout << YELLOW << "Creating a Span with a capacity of 5..." << RESET << std::endl;
        Span sp(5);

        std::cout << GREEN << "Adding numbers: 6, 3, 17, 9, 11" << RESET << std::endl;
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << BLUE << "Shortest span: " << sp.shortestSpan() << RESET << std::endl;
        std::cout << BLUE << "Longest span: " << sp.longestSpan() << RESET << std::endl;

        std::cout << RED << "Trying to add another number to a full Span..." << RESET << std::endl;
        sp.addNumber(42);
    } catch (const std::exception& e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << CYAN << BOLD << "\n=== Large Span Test (Manual Insertion) ===" << RESET << std::endl;

    try {
        Span bigSpan(20000);
        std::cout << YELLOW << "Adding 20,000 random numbers manually..." << RESET << std::endl;


        srand(static_cast<unsigned int>(time(NULL)));
        std::vector<int> randomNumbers;
        for (int i = 0; i < 20000; ++i) {
            randomNumbers.push_back(rand());
        }
        bigSpan.addNumber(randomNumbers.begin(), randomNumbers.end());

        std::cout << GREEN << "Shortest span: " << bigSpan.shortestSpan() << RESET << std::endl;
        std::cout << GREEN << "Longest span: " << bigSpan.longestSpan() << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}
