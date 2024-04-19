#include <iostream>
#include <string>

void to_upper(std::string& str)
{
	int i;
	int len;

	i = -1;
	len = str.size();
	while (++i < len)
	{
		if (std::islower(str[i]))
			str[i] = std::toupper(str[i]);
	}
}

int main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac >= 2)
	{
		while (i <= ac - 1)
		{
			std::string arg(av[i]);
			to_upper(arg);
			std::cout << arg;
			i++;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return 0;
}

