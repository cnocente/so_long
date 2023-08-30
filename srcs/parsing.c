// Comment savoir si ma map est valide ?
// 1 MUR 0 Case vide C collectible E exit P points de depart de ton joueurs

// le fichier de la map doit etre obliatoirement un .ber CHECK ARGUMENT OOOOK

// GNL va nous servir a extraire chaque ligne  ok

// GNL fait une super string et split en fait un tableau le nombre le ligne est determine:ok
// par le nb de \n ok

//strlen chaque ligne et chaque colonne pour verifier != Carre OKKKK
//et nous allons checker que chaque ligne ne contient 
// que les caractere demandes 
// MA PREMIERE et DERNIERE ligne ne sont que des 1/mur oook

// le premier et le dernier(avant le \n) caractere ne sont que des 1 ok

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
	int	l;
	int	w;
	int	j;

	l = 0;
	w = 0;
	j = 0;
	while(map[w])
		w++;
	while(map[0][l])
		l++;
	// if (w == l)
	// 	return(0);
	j = l;
	w = 0;
	while(map[w])
	{
		l = 0;
		while(map[w][l])
			l++;
		if(j != l)
			return(0);
		w++;
	}
	printf("shape ok\n");
	return(1);
}

int	ft_validmap(char **map)
{
	int	w;
	int	l;

	w = 0;
	l = 0;
	while(map[w][l])
	{
		if(map[w][l] != '1')
			return(write(1, "error1", 6), 0);
		l++; 
	}
	while(map[w])
	{
		if(map[w][0] != '1' || map[w][l - 1] != '1') // -1 bc \0
		{
			write(1, "error2", 6);
			return(0);
		}
		w++;
	}
	l = 0;
	w--;
	while(map[w][l])
	{
		if(map[w][l] != '1')
		{
			write(1,"error3", 6);
			return(0);
		}
		l++;
	}
	return(printf("walls ok\n"), 1);
}

int	ft_characters(char **map)
{
	int	w;
	int	l;
	int	p_count;
	int	e_count;
	int	c_count;

	
	p_count = 0;
	e_count = 0;
	c_count = 0;
	w = 0;
	l = 0;
	while(map[w])
	{
		l = 0;
		while(map[w][l])
		{
			if(map[w][l] == '1' || map[w][l] == '0')
				l++;
			else if(map[w][l] == 'E' || map[w][l] == 'P' || map[w][l] =='C')
			{
				if(map[w][l] == 'E')
					e_count++;
				if(map[w][l] == 'P')
					p_count++;
				if(map[w][l] == 'C')
					c_count++;
			}
			else
				return(write(1,"error\n",7), 0);
			l++;
		}
	w++;
	}
	return(write(1, "char ok", 7), 1);
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
				return (printf("wrong map shape"), 0);
			if (!ft_validmap(map))
				return(1);
			if(!ft_characters(map))
				return(1);
		}
	}
	else
		printf("Argument invalide");
	return (1);
}