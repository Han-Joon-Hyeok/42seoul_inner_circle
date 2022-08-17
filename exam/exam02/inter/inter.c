#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_inter(char *str1, char *str2)
{
	char	table[256];

	for (int i = 0; i < 255; i++)
	{
		table[i] = 0;
	}
	for (int i = 0; str1[i] != '\0'; i++)
	{
		if (table[(int)str1[i]] == 0)
		{
			table[(int)str1[i]] = 1;
		}
	}
	for (int i = 0; str2[i] != '\0'; i++)
	{
		if (table[(int)str2[i]] == 1)
		{
			table[(int)str2[i]] = 2;
		}
	}
	for (int i = 0; str1[i] != '\0'; i++)
	{
		if (table[(int)str1[i]] == 2)
		{
			ft_putchar(str1[i]);
			table[(int)str1[i]] = 0;
		}
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		ft_inter(argv[1], argv[2]);
	}
	ft_putchar('\n');
	return (0);
}
