#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"
bool check_for_number(std::string str);
bool check_for_string(std::string str);
bool check_cmd(std::string *str);
bool check_search_index(std::string str);

//main.cpp
//phonebook.cpp


class PhoneBook
{
	private:
		Contact contacts[8];
		int num_of_contacts;
	public:
		void		add(int i);
		void		exit(void);
		void		search_(void);
		void		exit_program(void);
		void		printf_table(void);
		void		add_contact(void);
		void		add_contact(int );
		int			fill_contact(int i);
		bool		search_contact(int i);
		void		print_with_index(int i);
		void		print_whole_info(int i);
		void		get_rigth_size(std::string &str);
		PhoneBook() : num_of_contacts(0) {}
};


#endif // PHONEBOOK_H