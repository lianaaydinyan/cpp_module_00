#include "phonebook.hpp"

// erb vor searchi mej index es spasum stugel for tiv lini u chanel "stoi" ov zut dzerqov nayelll
// getlineic heto anpaymannayel for signal ekac chlini vor anverj cikl charajana ctrl + D
// petq a unenal amen classi hamar hpp u cpp filer hppum miayn clasn a isk cppum impilentatian
// setter and getter is best practise

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

	std::string tmp_surname;
	std::cout << "Enter your surname -> ";
	std::cin >> tmp_surname;
	while (!(check_for_string(tmp_surname)))
		{
			std::cout << "Surname have to only contain characters -> ";
			std::cin >> tmp_surname;
		}

	std::string tmp_nickname;
	std::cout << "Enter your nickname -> ";
	std::cin >> tmp_nickname;
	while ((tmp_nickname.empty()))
		{
			std::cout << "Nickname have not to be empty -> " ;
			std::cin >> tmp_nickname;
		}

	std::string tmp_number;
	std::cout << "Enter your phone number -> ";
	std::cin >> tmp_number;
	while (!(check_for_number(tmp_number)))
		{
			std::cout << "Phone Number have to be contain only numbers -> " ;
			std::cin >> tmp_number;
		}
	
	std::string tmp_secret;
	std::cout << "Enter your secret -> ";
	std::cin >> tmp_secret;
	while ((tmp_secret.empty()))
		{
			std::cout << "Secret have not to be empty -> " ;
			std::cin >> tmp_secret;
		}

	// if every field filled properly we can add it to our array
	// now adding
	contacts[i].name = tmp_name;
	contacts[i].surname = tmp_surname;
	contacts[i].nickname = tmp_nickname;
	contacts[i].phone_num = tmp_number;
	contacts[i].secret = tmp_secret;
	return 1;
}

void	PhoneBook::print_whole_info(int i)
{
	std::cout << "Name -> " << contacts[i].name << std::endl;
	std::cout << "Surname -> " << contacts[i].surname << std::endl;
	std::cout << "Nickname -> " << contacts[i].nickname << std::endl;
	std::cout << "Phone number -> " << contacts[i].phone_num << std::endl;
	std::cout << "Secret -> " << contacts[i].secret << std::endl;
}

void	PhoneBook::add_contact(void)
{
	if (num_of_contacts >= 0 && num_of_contacts < 8)
		fill_contact(num_of_contacts);
	else if (num_of_contacts >= 8)
		fill_contact(num_of_contacts % 8);
	num_of_contacts++;
}

void	PhoneBook::printf_table(void)
{
	int 		i;
	std::string index;
	int 		contact_index;

	i = -1;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|";
	std::cout  << std::right << std::setw(10) << "id";
	std::cout << "|";
	std::cout  << std::right << std::setw(10) << "name";
	std::cout << "|" ;
	std::cout  << std::right << std::setw(10) << "surname";
	std::cout << "|" ;
	std::cout  << std::right << std::setw(10) << "nickname";
	std::cout << "|" ;
	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	while ( ++i < num_of_contacts)
		print_with_index(i);

	std::cin >> index;
	if (!(check_for_number(index)))
	{
		while (!(check_for_number(index)))
		{
			std::cout << "Invalid index, write it one more time -> ";
			std::cin >> index;
		}
	}

	contact_index = std::atoi(index.c_str());
	if (contact_index >= 0 && contact_index < 8)
		print_whole_info(contact_index);
}



void	PhoneBook::get_rigth_size(std::string &str)
{
	int size;

	size = str.length();
	if (size > 10)
	{
		str = str.substr(0, 9);
		str += ".";
	}
}

void	PhoneBook::print_with_index(int i)
{
	std::cout << "|" ;
	std::cout << std::right << std::setw(10) << i;
	get_rigth_size(contacts[i].name);

	std::cout << "|" ;
	std::cout << std::right << std::setw(10) << (contacts[i].name);
	get_rigth_size(contacts[i].surname);

	std::cout << "|" ;
	std::cout << std::right << std::setw(10) << (contacts[i].surname);
	get_rigth_size(contacts[i].nickname);

	std::cout << "|" ;
	std::cout << std::right << std::setw(10) << (contacts[i].nickname);
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}


bool	PhoneBook::search_contact(int i)
{
	if (i >= 0)
	{
		if (!(contacts[i].name.empty()))
		{
			print_with_index(i);
			return true;
		}
	}
	else
		std::cout << "You have entered unvalid index ^_^ " << std::endl;
	return false;
}


