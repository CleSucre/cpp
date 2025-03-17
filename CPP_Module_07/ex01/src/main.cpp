#include "iter.hpp"

void printInt(int& n) {
    std::cout << GREEN << n << " " << RESET;
}

void printString(std::string& str) {
    std::cout << BLUE << str << " " << RESET;
}

void increment(int& n) {
    n++;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    std::string words[] = {"Hello", "World", "Templates"};

    std::cout << YELLOW << "Before increment: " << RESET;
    iter(numbers, 5, printInt);
    std::cout << std::endl;

    iter(numbers, 5, increment);

    std::cout << YELLOW << "After increment: " << RESET;
    iter(numbers, 5, printInt);
    std::cout << std::endl;

    std::cout << MAGENTA << "Strings: " << RESET;
    iter(words, 3, printString);
    std::cout << std::endl;

    return 0;
}
