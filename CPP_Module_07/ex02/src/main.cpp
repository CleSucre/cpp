#include "Array.hpp"

int main() {
    try {
        Array<int> numbers(5);
        for (unsigned int i = 0; i < numbers.size(); i++) {
            numbers[i] = i * 2;
        }

        std::cout << YELLOW << "Array content: " << RESET;
        for (unsigned int i = 0; i < numbers.size(); i++) {
            std::cout << GREEN << numbers[i] << " " << RESET;
        }
        std::cout << std::endl;

        Array<std::string> words(3);
        words[0] = "Hello";
        words[1] = "World";
        words[2] = "Templates";

        std::cout << BLUE << "String Array: " << RESET;
        for (unsigned int i = 0; i < words.size(); i++) {
            std::cout << MAGENTA << words[i] << " " << RESET;
        }
        std::cout << std::endl;

        std::cout << CYAN << "Testing copy constructor..." << RESET << std::endl;
        Array<int> copy(numbers);

        std::cout << CYAN << "Modifying the original array..." << RESET << std::endl;
        numbers[0] = 99;

        std::cout << YELLOW << "Original: " << RESET << GREEN << numbers[0] << RESET << std::endl;
        std::cout << YELLOW << "Copy: " << RESET << GREEN << copy[0] << RESET << std::endl;

        std::cout << RED << "Testing out of bounds access..." << RESET << std::endl;
        std::cout << numbers[10] << std::endl;

    } catch (const std::exception& e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}
