// Comment savoir si ma map est valide ?
// 1 MUR 0 Case vide C collectible E exit P points de depart de ton joueurs

// le fichier de la map doit etre obliatoirement un .ber CHECK ARGUMENT OOOOK

// GNL va nous servir a extraire chaque ligne  ok

// GNL fait une super string et split en fait un tableau le nombre le ligne est determine:ok
// par le nb de \n ok

//strlen chaque ligne et chaque colonne pour verifier != Carre
//et nous allons checker que chaque ligne ne contient 
// que les caractere precedent 
// MA PREMIERE et DERNIERE ligne ne sont que des 1/mur

// le premier et le dernier(avant le \n) caractere ne sont que des 1

// notre carte doit contenir uniquement 1 E 1 P et au minimum 1 C


// Pour chaque Erreur on doit ecrire Error\n et lui dire pq

#include <stdio.h>
#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s1[i] && s2[i])
	{
		if(s1[i] != s2[i])
			return(0);
		i++;
	}
	if(!s1[i] && !s2[i])
		return(1);
	return(0);
}

int	check_map(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str) //
		return (0);
	while(str[i] != '\0')
	{
		if (str[i] == '.')
			if (ft_strcmp(".ber", str+i))
				return (1);
		i++;
	}
	return (0);
}

char **build_tab(char	*str)
{
	char	*super_line;
	char	*line;
	int		fd;

	fd = open(str, O_RDONLY);
	super_line = get_next_line(fd);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		super_line = ft_strjoin(super_line, line);
		free(line);
	}
	if(super_line)
		return(ft_split(super_line, '\n'));
	return (NULL);
}

int	ft_checkshape(char **map)
{
	int	i;
	int	y;
	int	j;

	j = 0;
	i = 0;
	y = 0;
	while(map[i])
		i++;
	while(map[0][y])
		y++;
	if (i == y)
		return(0);
	j = y;
	i = 0;
	y = 0;
	while(map[i])
	{
		while(map[i][y])
			y++;
		if (j != y)
			return (0);
		i++;
	}
	printf("ok");
	return(1);
}
int	main(int argc, char **argv)
{
	char **map;

	if (argc == 2)
	{
		if(check_map(argv[1]))
		{
			map = build_tab(argv[1]);
			if (map == NULL)
				return (1);
			if(!ft_checkshape(map))
				printf("Map not good");
			return (0);
		}
	}
	printf("Arguments invalide");
	return (1);
}

//
//char str;
//
//char *str; == 3 4 5 6 7 8
//
//str[0] = c
//str = 3;
//
//Carla est relou str;
//34567				&
//012345678   		I
//
//./solong ""
//














































