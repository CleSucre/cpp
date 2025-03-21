#include <iostream>
#include "MutantStack.hpp"
#include "colors.h"

int main() {
    std::cout << CYAN << BOLD << "=== Testing MutantStack ===" << RESET << std::endl;

    MutantStack<int> mstack;

    std::cout << YELLOW << "\n-- Pushing values: 5, 17 --" << RESET << std::endl;
    mstack.push(5);
    mstack.push(17);

    std::cout << GREEN << "Top of stack: " << mstack.top() << RESET << std::endl;

    std::cout << YELLOW << "\n-- Popping top value --" << RESET << std::endl;
    mstack.pop();

    std::cout << GREEN << "Size after pop: " << mstack.size() << RESET << std::endl;

    std::cout << YELLOW << "\n-- Pushing values: 3, 5, 737, 0 --" << RESET << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << BLUE << "\n-- Iterating through MutantStack --" << RESET << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    for (; it != ite; ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << MAGENTA << "\n-- Copying stack into std::stack --" << RESET << std::endl;
    std::stack<int> copy(mstack);
    std::cout << GREEN << "Top of copied std::stack: " << copy.top() << RESET << std::endl;

    std::cout << CYAN << BOLD << "\n=== End of test ===" << RESET << std::endl;
    return 0;
}
