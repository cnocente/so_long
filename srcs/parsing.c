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

// notre carte doit contenir uniquement 1 E 1 P et au minimum 1 C ok


// Pour chaque Erreur on doit ecrire Error\n et lui dire pq

#include <stdio.h>
#include "so_long.h"

int	ft_strcmp(char *s1, char *s2, t_data data)
{
	data.i = 0;
	while(s1[data.i] && s2[data.i])
	{
		if(s1[data.i] != s2[data.i])
			return(0);
		data.i++;
	}
	if(!s1[data.i] && !s2[data.i])
	{
		return(1);
	}
	return(0);
}

int	check_map(char *str, t_data data)
{
	if (!str || !*str) //
		return (0);
	while(str[data.i] != '\0')
	{
		if (str[data.i] == '.')
			if (ft_strcmp(".ber", str+ data.i, data))
				return (1);
		data.i++;
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

int	ft_checkshape(char **map, t_data data)
{
	while(map[data.w])
		data.w++;
	while(map[0][data.l])
		data.l++;
	data.j = data.l;
	data.w = 0;
	while(map[data.w])
	{
		data.l = 0;
		while(map[data.w][data.l])
			data.l++;
		if(data.j != data.l)
			return(0);
		data.w++;
	}
	printf("shape ok\n");
	return(1);
}

int	ft_validmap(char **map, t_data data)
{
	while(map[data.w][data.l])
	{
		if(map[data.w][data.l] != '1')
			return(write(1, "error first line\n", 17), 0);
		data.l++; 
	}
	while(map[data.w])
	{
		if(map[data.w][0] != '1' || map[data.w][data.l - 1] != '1') // -1 bc \0
			return(write(1, "error columns\n", 14), 0);
		data.w++;
	}
	data.l = 0;
	data.w--;
	while(map[data.w][data.l])
	{
		if(map[data.w][data.l] != '1')
			return(write(1,"error last line", 15), 0);
		data.l++;
	}
	return(printf("walls ok\n"), 1);
}

int	char_count(int e, int p, int c)
{
	if (e != 1)
	{
		write(2, "wrong exit count\n", 17);
		return (0);
	}	
	else if (p != 1)
	{
		write(2,"wrong player count\n", 18);
		return(0);
	}
	else if (c < 1)
	{
		write(2, "no collectible\n", 14);
		return(0);
	}
	else
		return(printf("characters count ok"), 1);

}

int	ft_characters(char **map, t_data data)
{
	while(map[data.w])
	{
		data.l = 0;
		while (map[data.w][data.l])
		{
			if (map[data.w][data.l] == 'E')
					data.e_count++;
			else if (map[data.w][data.l] == 'P')
					data.p_count++;
			else if (map[data.w][data.l] == 'C')
					data.c_count++;
			else if (map[data.w][data.l] != '1' && map[data.w][data.l] != '0')
				return(write(1,"error\n",7), 0);
			data.l++;
		}
		data.w++;
	}
	if (char_count(data.e_count, data.p_count, data.c_count) == 0 )
		return(0); 
	return(1);
}


int	main(int argc, char **argv)
{
	char	**map;
	static t_data	data = {0};

	if (argc == 2)
	{
		if (check_map(argv[1], data))
		{
			map = build_tab(argv[1]);
			if (map == NULL)
				return (1);
			if (!ft_checkshape(map, data))
				return (printf("wrong map shape"), 0);
			if (!ft_validmap(map, data))
				return(1);
			if (!ft_characters(map, data))
				return (1);
		}
	}
	else
		printf("Argument invalide");
	return (1);
}