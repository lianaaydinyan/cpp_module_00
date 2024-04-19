#include <iostream>
#include <string>

int getlength(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

void to_upper(char *str)
{
	int i;
	int len;

	i = -1;
	len = getlength(str);
	while (++i < len) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			std::cout << (char)(str[i] - 32);
		} else {
			std::cout << str[i];
		}
	}
}

int main(int ac, char **av) {
	int i;
	int len;

	i = 1;
	len = ac - 1;
	while (i <= len)
	{
		to_upper(av[i]);
		i++;
	}
	return 0;
}
