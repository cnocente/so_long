#include <stdio.h>

int	ft_check(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		printf("%s",str+i);
		printf("{%d}[%c]\n", i, str[i]);
		if( str[i] == '.')
			break;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_check(argv[1]);
	return(0);
}
