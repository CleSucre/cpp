#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    for (int i = 0; i < MAX_CONTACTS; i++) {
        this->_contacts[i] = NULL;
    }
    this->_index = 0;
}

PhoneBook::~PhoneBook(void) {
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (this->_contacts[i] != NULL) {
            delete this->_contacts[i];
            this->_contacts[i] = NULL;
        }
    }
}

int PhoneBook::_realignContacts(void) {
    int j = 0;
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (this->_contacts[i] != NULL) {
            this->_contacts[j++] = this->_contacts[i];
        }
    }
    while (j < MAX_CONTACTS) {
        this->_contacts[j++] = NULL;
    }
    return j;
}

AddStatus PhoneBook::add(Contact *contact) {
    if (!contact) {
        return ADD_ERROR;
    }

    AddStatus status = ADD_SUCCESS;

    if (this->_index >= MAX_CONTACTS) {
        delete this->_contacts[0];

        for (int i = 0; i < MAX_CONTACTS - 1; i++) {
            this->_contacts[i] = this->_contacts[i + 1];
        }
        this->_contacts[MAX_CONTACTS - 1] = NULL;
        this->_index = MAX_CONTACTS - 1;
        status = ADD_ERASED;
    }

    this->_contacts[this->_index++] = contact;
    return status;
}

bool PhoneBook::remove(int index) {
    if (index < 0 || index >= this->_index || this->_contacts[index] == NULL) {
        return false;
    }

    delete this->_contacts[index];
    this->_contacts[index] = NULL;
    this->_index = this->_realignContacts();
    return true;
}

Contact* PhoneBook::getContact(int index) const {
    if (index < 0 || index >= this->_index || this->_contacts[index] == NULL) {
        return NULL;
    }
    return this->_contacts[index];
}

int PhoneBook::contactCount(void) const {
	return this->_index;
}

void PhoneBook::displayContacts(void) const {
    if (this->_index == 0) {
        std::cout << RED << "📭 No contacts available." << RESET << std::endl;
        return;
    }

    std::cout << BOLD MAGENTA "     Index | First Name | Last Name  | Nickname" RESET << std::endl;
    std::cout << BOLD MAGENTA "---------------------------------------------" RESET << std::endl;

    for (int i = 0; i < this->_index; i++) {
        if (this->_contacts[i] != NULL) {
            std::cout << std::setw(MAX_FIELD_WIDTH) << i + 1 << "|";
            this->_contacts[i]->display(true);
        }
    }
}
