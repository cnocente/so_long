#include <unistd.h>

int	main(int ac, char **av)
{
	int i, j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			write(1, &av[i][j], 1);
			j++;
		}
		i++;
	}
}