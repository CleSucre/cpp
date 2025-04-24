#include "colors.h"
#include <iostream>
#include <stack>
#include <sstream>

int evaluateRPN(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;
    int number;
    int b;
    int a;

    while (iss >> token) {
        if ((isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))) {
            std::istringstream tokenStream(token);
            tokenStream >> number;
            if (number > 9) {
                throw std::runtime_error("Invalid number: " + token);
            }
            stack.push(number);
        } else {
            if (stack.size() < 2) {
                throw std::runtime_error("Syntax error: " + token);
            }
            b = stack.top();
            stack.pop();
            a = stack.top();
            stack.pop();
            
            if (token == "+") {
                stack.push(a + b);
            } else if (token == "-") {
                stack.push(a - b);
            } else if (token == "*") {
                stack.push(a * b);
            } else if (token == "/") {
                stack.push(a / b);
            } else {
                throw std::runtime_error("Unknown operator: " + token);
            }
        }
    }

    return stack.top();
}

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
