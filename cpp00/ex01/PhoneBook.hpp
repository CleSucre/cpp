#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

enum AddStatus {
    ADD_SUCCESS = 1, // Contact added successfully
    ADD_ERASED = 0, // Contact added but erased another
    ADD_ERROR = -1 // Contact not added
};

const int MAX_CONTACTS = 8;

class PhoneBook {

	private:
		Contact	*_contacts[MAX_CONTACTS];
		int		_index;

		int		_realignContacts(void);
	public:
		PhoneBook(void);
		~PhoneBook(void);
		AddStatus	add(Contact *contact);
		bool		remove(int index);
		Contact*	getContact(int index) const;
		int			contactCount(void) const;
		void		displayContacts(void) const;
};

#endif //PHONEBOOK_HPP
