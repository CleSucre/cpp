#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "colors.h"
#include "easyfind.hpp"

void    test_vector() {
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    int toFind = 30;

    try {
        std::vector<int>::iterator it = easyfind(numbers, toFind);
        std::cout << MAGENTA << "[VECTOR] " << GREEN << "Value " << YELLOW << toFind << GREEN << " found at position: " << YELLOW << std::distance(numbers.begin(), it) << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << MAGENTA << "[VECTOR] " << RED << "Value " << YELLOW << toFind << RED << " not found in the container." << RESET << std::endl;
    }

    toFind = -10;
    try {
        std::vector<int>::iterator it = easyfind(numbers, toFind);
        std::cout << MAGENTA << "[VECTOR] " << GREEN << "Value " << YELLOW << toFind << GREEN << " found at position: " << YELLOW << std::distance(numbers.begin(), it) << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << MAGENTA << "[VECTOR] " << RED << "Value " << YELLOW << toFind << RED << " not found in the container." << RESET << std::endl;
    }
}

void    test_list() {
    std::list<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    int toFind = 50;

    try {
        std::list<int>::iterator it = easyfind(numbers, toFind);
        std::cout << MAGENTA << "[LIST]  " << GREEN << "Value " << YELLOW << toFind << GREEN << " found at position: " << YELLOW << std::distance(numbers.begin(), it) << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << MAGENTA << "[LIST]  " << RED << "Value " << YELLOW << toFind << RED << " not found in the container." << RESET << std::endl;
    }

    toFind = 0;
    try {
        std::list<int>::iterator it = easyfind(numbers, toFind);
        std::cout << MAGENTA << "[LIST]  " << GREEN << "Value " << YELLOW << toFind << GREEN << " found at position: " << YELLOW << std::distance(numbers.begin(), it) << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << MAGENTA << "[LIST]  " << RED << "Value " << YELLOW << toFind << RED << " not found in the container." << RESET << std::endl;
    }
}

void    test_deque() {
    std::deque<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    int toFind = 10;

    try {
        std::deque<int>::iterator it = easyfind(numbers, toFind);
        std::cout << MAGENTA << "[DEQUE] " << GREEN << "Value " << YELLOW << toFind << GREEN << " found at position: " << YELLOW << std::distance(numbers.begin(), it) << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << MAGENTA << "[DEQUE] " << RED << "Value " << YELLOW << toFind << RED << " not found in the container." << RESET << std::endl;
    }

    toFind = 90;
    try {
        std::deque<int>::iterator it = easyfind(numbers, toFind);
        std::cout << MAGENTA << "[DEQUE] " << GREEN << "Value " << YELLOW << toFind << GREEN << " found at position: " << YELLOW << std::distance(numbers.begin(), it) << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << MAGENTA << "[DEQUE] " << RED << "Value " << YELLOW << toFind << RED << " not found in the container." << RESET << std::endl;
    }
}

int main() {
    test_vector();
    test_list();
    test_deque();
    return 0;
}
