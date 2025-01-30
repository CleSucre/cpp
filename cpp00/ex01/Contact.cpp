#include "Contact.hpp"

Contact::Contact()
    : _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("") {
}

Contact::Contact(const std::string& first_name,
                 const std::string& last_name,
                 const std::string& nickname,
                 const std::string& phone_number,
                 const std::string& darkest_secret)
    : _first_name(first_name),
      _last_name(last_name),
      _nickname(nickname),
      _phone_number(phone_number),
      _darkest_secret(darkest_secret) {
}

Contact::~Contact() {}

std::string Contact::_truncateField(const std::string& field) const {
    if (field.length() > MAX_FIELD_WIDTH) {
		return field.substr(0, MAX_FIELD_WIDTH - 1) + ".";
	}
    return field;
}


void Contact::setFirstName(const std::string& first_name) {
    _first_name = first_name;
}

void Contact::setLastName(const std::string& last_name) {
    _last_name = last_name;
}

void Contact::setNickname(const std::string& nickname) {
	_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phone_number) {
	_phone_number = phone_number;
}

void Contact::setDarkestSecret(const std::string& darkest_secret) {
	_darkest_secret = darkest_secret;
}

const std::string& Contact::getFirstName() const {
    return _first_name;
}

const std::string& Contact::getLastName() const {
    return _last_name;
}

const std::string& Contact::getNickname() const {
    return _nickname;
}

const std::string& Contact::getPhoneNumber() const {
	return _phone_number;
}

const std::string& Contact::getDarkestSecret() const {
	return _darkest_secret;
}

void Contact::display(bool resume) const {
    if (resume) {
        std::cout << std::setw(MAX_FIELD_WIDTH) << YELLOW << this->_truncateField(this->_first_name) << RESET << "|";
        std::cout << std::setw(MAX_FIELD_WIDTH) << CYAN << this->_truncateField(this->_last_name) << RESET << "|";
        std::cout << std::setw(MAX_FIELD_WIDTH) << GREEN << this->_truncateField(this->_nickname) << RESET << std::endl;
        return;
    }

    std::cout << BOLD BLUE "📌 Contact Details:" RESET << std::endl;
    std::cout << BOLD "First name: " RESET << GREEN << _first_name << RESET << std::endl;
    std::cout << BOLD "Last name: " RESET << CYAN << _last_name << RESET << std::endl;
    std::cout << BOLD "Nickname: " RESET << YELLOW << _nickname << RESET << std::endl;
    std::cout << BOLD "Phone number: " RESET << _phone_number << std::endl;
    std::cout << BOLD "Darkest secret: " RESET << _darkest_secret << std::endl;
}
