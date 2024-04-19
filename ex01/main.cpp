#include "phonebook.hpp"

bool check_for_number(std::string str)
{
	int i;
	int size;

	i = -1;
	size = str.size();

		while (++i < size)
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				return false;
		}
	return true;
}

bool check_for_string(std::string str)
{
	int i;
	int size;

	i = -1;
	size = str.size();
	while (++i < size)
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
			return false;
	}
	return true;
}

bool check_cmd(std::string *str)
{
	std::cin >> *str;

	if (*str == "ADD" || *str == "SEARCH" || *str == "EXIT")
		return true;
	return false;
}

int main()
{

	std::string cmd;
	std::cout << "Enter only [ ADD , SEARCH , EXIT] commands " << std::endl;
	PhoneBook phone_book;

	while (check_cmd(&cmd))
	{
		if (cmd == "ADD")
		{
			//compare
			phone_book.add_contact();
		}
		else if (cmd == "SEARCH")
		{
			//spasel indexi
			phone_book.printf_table();
		}
		else if (cmd == "EXIT")
			phone_book.exit();
	}
	return 0;
}