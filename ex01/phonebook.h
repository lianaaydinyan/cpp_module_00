#ifndef PHONEBOOK_H
#define PHONEBOOK_H


#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "contact.h"

//main.cpp
void	signal_handling(void);
bool	check_for_number(std::string str);
bool	check_for_string(std::string str);
bool	check_cmd(std::string *str);
bool	check_search_index(std::string str);

class PhoneBook
{
	private:
		Contact contacts[8];
		int num_of_contacts;
	public:
		void		exit(void);
		int			fill_contact(int i);
		void		print_whole_info(int i);
		void		add_contact(void);
		void		printf_table(void);
		std::string	get_rigth_size(std::string str);
		void		print_with_index(int i);
		bool		search_contact(int i);
		PhoneBook() : num_of_contacts(0) {}
};


#endif // PHONEBOOK_H