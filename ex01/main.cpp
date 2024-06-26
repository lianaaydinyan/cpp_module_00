#include "phonebook.h"

void	signal_handling(void)
{
	if (std::cin.eof())
		std::cin.clear();
	exit(-1);
}

bool	check_search_index(std::string str)
{
	int num;

	if ((str.size() == 1 )&& check_for_number(str))
	{
		num = std::stoi(str);
		if (num >= 0 && num < 8)
			return true;
	}
	return false;
}

bool	check_for_number(std::string str)
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

bool	check_for_string(std::string str)
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

bool	check_cmd(std::string &str)
{
	std::cout << "Enter only [ADD, SEARCH, EXIT] commands " << std::endl;
	if(!(std::cin >> str))
		signal_handling();
	if ( str == "ADD" || str == "SEARCH" || str == "EXIT")
		return true;
	return false;
}

int main()
{

	std::string cmd;
	PhoneBook phone_book;

	while (1)
	{
		if (check_cmd(cmd))
		{
			if (!(cmd.compare("ADD")))
				phone_book.add_contact();
			else if (!(cmd.compare("SEARCH")))
				phone_book.printf_table();
			else if (!(cmd.compare("EXIT")))
				phone_book.exit();
		}
		else
		std::cout << "Invalid input:" << std::endl;
	}
	return 0;
}