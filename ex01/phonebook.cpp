#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

class Contact
{
	public:
		std::string phone_num;
		std::string name;
		std::string surname;
		std::string nickname;
		std::string secret;
};

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
		bool		check_for_string(std::string str);
		bool		check_for_number(std::string str);
		void		get_rigth_size(std::string &str);
		PhoneBook() : num_of_contacts(0) {}
};

bool	PhoneBook::check_for_string(std::string str)
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

bool	PhoneBook::check_for_number(std::string str)
{
	int i;
	int size;

	i = -1;
	size = str.size();
	if (!check_for_string(str))
	{
		while (++i < size)
		{
			if (!((str[i] >= '0' && str[i] <= '9')))
				return false;
		}
	}
	return true;
}

void	PhoneBook::exit(void)
{
	std::exit(0);
}

int	PhoneBook::fill_contact(int i)
{

	std::string tmp_name;
	std::cout << "Enter your name -> ";
	std::cin >> tmp_name;
	while (!(check_for_string(tmp_name)))
		{
			std::cout << "Name have to only contain characters -> ";
			std::cin >> tmp_name;
		}
	std::cout << std::endl;

	std::string tmp_surname;
	std::cout << "Enter your surname -> ";
	std::cin >> tmp_surname;
	while (!(check_for_string(tmp_surname)))
		{
			std::cout << "Surname have to only contain characters -> ";
			std::cin >> tmp_surname;
		}
	std::cout << std::endl;

	std::string tmp_nickname;
	std::cout << "Enter your nickname -> ";
	std::cin >> tmp_nickname;
	while (!(tmp_nickname.empty()))
		{
			std::cout << "Nickname have not to be empty -> " ;
			std::cin >> tmp_nickname;
		}
	std::cout << std::endl;

	std::string tmp_number;
	std::cout << "Enter your phone number -> ";
	std::cin >> tmp_number;
	while (!(check_for_number(tmp_number)))
		{
			std::cout << "Phone Number have to be contain only numbers -> " ;
			std::cin >> tmp_number;
		}
	std::cout << std::endl;
	
	std::string tmp_secret;
	std::cout << "Enter your secret -> ";
	std::cin >> tmp_secret;
	while (!(tmp_secret.empty()))
		{
			std::cout << "Secret have not to be empty -> " ;
			std::cin >> tmp_secret;
		}
	std::cout << std::endl;

	// if every field filled properly we can add it to our array
	// now adding

	contacts[i].name = tmp_name;
	contacts[i].surname = tmp_surname;
	contacts[i].nickname = tmp_nickname;
	contacts[i].phone_num = tmp_number;
	contacts[i].secret = tmp_secret;
	return 1;
}

void	PhoneBook::add_contact(void)
{
	if (num_of_contacts >= 0 && num_of_contacts < 8)
		fill_contact(num_of_contacts);
	else if (num_of_contacts >= 8)
		fill_contact(num_of_contacts % 8);
}


void	PhoneBook::printf_table(void)
{
	int i;

	i = -1;
	//search indexov nor tpel secret
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "|        id" << "|      name" << "|   surname" << "|  nickname" << "|" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	while ( ++i < num_of_contacts)
		print_with_index(i);
}

void	PhoneBook::get_rigth_size(std::string &str)
{
	int size;

	size = str.length();
	if (size > 10)
	{
		str = str.substr(0,9);
		str += ".";
	}
}

void	PhoneBook::print_with_index(int i)
{
	std::cout << "|" << std::setw(10) << i;
	get_rigth_size(contacts[i].name);
	std::cout << "|" << std::setw(10) << (contacts[i].name);
	get_rigth_size(contacts[i].surname);
	std::cout << "|" << std::setw(10) << (contacts[i].surname);
	get_rigth_size(contacts[i].nickname);
	std::cout << "|" << std::setw(10) << (contacts[i].nickname);
	std::cout << "|" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
}


bool	PhoneBook::search_contact(int i)
{
	if (i >= 0)
	{
		if (!contacts[i].name.empty())
		{
			print_with_index(i);
			return true;
		}
	}
	else
		std::cout << "You have entered unvalid index ^_^ " << std::endl;
	return false;
}

bool check_cmd(std::string str)
{
	std::cin >> str;
	if (str == "ADD")
		return true;
	else if (str == "SEARCH")
		return true;
	else if (str == "EXIT")
		return true;
	else
		return false;
}


int main()
{

	std::string cmd;
	std::cout << "Enter only [ ADD , SEARCH , EXIT] commands " << std::endl;
	PhoneBook phone_book;
	while (check_cmd(cmd))
	{
		if (cmd == "ADD")
			phone_book.add_contact();
		else if (cmd == "SEARCH")
			phone_book.printf_table();
		else if (cmd == "EXIT")
			phone_book.exit();
	}
	return 0;
}

