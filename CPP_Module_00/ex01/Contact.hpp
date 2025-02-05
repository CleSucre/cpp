#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "colors.h"

const int MAX_FIELD_WIDTH = 10;

class Contact {
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;

		std::string	_truncateField(const std::string& field) const;

    public:
        Contact(const std::string& first_name,
                const std::string& last_name,
                const std::string& nickname,
                const std::string& phone_number,
                const std::string& darkest_secret);

        Contact(void);
        ~Contact(void);

		void setFirstName(const std::string& first_name);
		void setLastName(const std::string& last_name);
		void setNickname(const std::string& nickname);
		void setPhoneNumber(const std::string& phone_number);
		void setDarkestSecret(const std::string& darkest_secret);
		const std::string& getFirstName(void) const;
		const std::string& getLastName(void) const;
		const std::string& getNickname(void) const;
		const std::string& getPhoneNumber(void) const;
		const std::string& getDarkestSecret(void) const;

		void display(bool resume = false) const;
};

#endif //CONTACT_HPP
