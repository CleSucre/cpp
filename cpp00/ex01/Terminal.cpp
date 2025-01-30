#include "Terminal.hpp"

Terminal::Terminal(void) {}

Terminal::~Terminal(void) {}

std::string Terminal::_getInput(std::string question, bool number_only) {
    std::string input;

    std::cout << CYAN << question << RESET;
    std::getline(std::cin, input);

    if (std::cin.eof()) return "";

    if (input.empty()) {
        std::cout << RED << "⚠ Please enter a valid input." << RESET << std::endl;
        return this->_getInput(question, number_only);
    }

    if (number_only) {
        for (size_t i = 0; i < input.length(); i++) {
            if (!std::isdigit(input[i])) {
                std::cout << RED << "⚠ Please enter a valid number." << RESET << std::endl;
                return this->_getInput(question, number_only);
            }
        }
    }

    return input;
}

bool Terminal::_addContact(void) {
    Contact *new_contact;

    std::cout << GREEN << "➕ Adding a new contact..." << RESET << std::endl;

    std::string first_name = this->_getInput(BOLD "First name: " RESET);
    if (first_name.empty()) return false;

    std::string last_name = this->_getInput(BOLD "Last name: " RESET);
    if (last_name.empty()) return false;

    std::string nickname = this->_getInput(BOLD "Nickname: " RESET);
    if (nickname.empty()) return false;

    std::string phone_number = this->_getInput(BOLD "Phone number: " RESET, true);
    if (phone_number.empty()) return false;

    std::string darkest_secret = this->_getInput(BOLD "Darkest secret: " RESET);
    if (darkest_secret.empty()) return false;

    new_contact = new Contact(first_name, last_name, nickname, phone_number, darkest_secret);

    if (this->_phoneBook.contactCount() == MAX_CONTACTS) {
        char confirm = this->_getInput(RED "⚠ Phone book is full, erase oldest contact? (y/n) " RESET)[0];
        if (confirm != 'y') {
            std::cout << YELLOW << "❌ Contact not added." << RESET << std::endl;
            return true;
        }
    }

    switch (this->_phoneBook.add(new_contact)) {
        case ADD_SUCCESS:
            std::cout << GREEN << "✅ Contact added successfully!" << RESET << std::endl;
            break;
        case ADD_ERASED:
            std::cout << YELLOW << "⚠ Contact added, but the oldest was erased." << RESET << std::endl;
            break;
        case ADD_ERROR:
            std::cout << RED << "❌ Unknown error: Contact not added!" << RESET << std::endl;
            break;
    }
    return true;
}

bool Terminal::_searchContact(void) {
    std::cout << BLUE << "🔎 Searching for a contact..." << RESET << std::endl;

    this->_phoneBook.displayContacts();

    std::string index_str = this->_getInput("Enter the contact index: ", true);
    if (index_str.empty()) {
		return false;
	}

    int index = std::atoi(index_str.c_str()) - 1;

    Contact *contact = this->_phoneBook.getContact(index);
    if (contact == NULL) {
        std::cout << RED << "❌ Contact not found!" << RESET << std::endl;
    } else {
        std::cout << GREEN << "📖 Contact details:" << RESET << std::endl;
        contact->display();
    }
    return true;
}

void Terminal::loop(void) {
	std::string command;

	std::cout << "Welcome to your Phone Book !" << std::endl;
	std::cout << "You can ADD a new contact, SEARCH for a contact or EXIT" << std::endl;
	while (true) {
		command = this->_getInput("Enter a command: ");
		if (command.empty() || command == "EXIT") {
            break;
        } else if (command == "ADD") {
			if (!this->_addContact()) {
				break;
            }
		} else if (command == "SEARCH") {
			if (!this->_searchContact()) {
				break;
			}
		}
	}
	std::cout << "Bye !" << std::endl;
}
