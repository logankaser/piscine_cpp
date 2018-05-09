#include <iostream>

int	main(int argc, char **argv)
{
	char 	*str;
	int 	i;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	i = 1;
	while (i < argc)
	{
		str = argv[i];
		while (*str)
		{
			if (*str >= 'a' && *str <= 'z')
				std::cout << (char)(*str - 32);
			else
				std::cout << *str;
			++str;
		}
		++i;
	}
	std::cout << std::endl;
	return (0);
}
