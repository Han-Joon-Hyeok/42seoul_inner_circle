#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		int count;
		Contact contact[8];

	public:
		PhoneBook() { count = 0; }
		void show_count(void);// 테스트용
		void add_new_contact(Contact contact);
		void show_contacts(void);
		void remove_last_contact(void);
};

#endif
