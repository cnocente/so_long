
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
//lire ligne apres gnl et check 01CEP okkk
//verifier valid path w floodfill okkkkk
// creer copie de la map debut floodfill oooooooook


// Pour chaque Erreur on doit ecrire Error\n et lui dire pq

#include <stdio.h>
#include "so_long.h"

int	ft_strcmp(char *s1, char *s2, t_data data)
{
	data.i = 0;
	while (s1[data.i] && s2[data.i])
	{
		if (s1[data.i] != s2[data.i])
			return (0);
		data.i++;
	}
	if (!s1[data.i] && !s2[data.i])
	{
		return (1);
	}
	return (0);
}

int	check_map(char *str, t_data data)
{
	if (!str || !*str) //
		return (0);
	while (str[data.i] != '\0')
	{
		if (str[data.i] == '.')
			if (ft_strcmp(".ber", str+ data.i, data))
				return (1);
		data.i++;
	}
	return (0);
}

int	ft_checkline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i]!= '1' && line[i] != '0' && line[i] != '\n'
			&& line[i] != 'E' && line[i] != 'P' && line[i] != 'C')
			return (write(1,"wrong character\n", 16), 0);
		i++;
	} 
	return (printf("line ok\n"),1);
}
char **build_tab(char	*str)
{
	char	*super_line;
	char	*line;
	int		fd;

	fd = open(str, O_RDONLY);
	super_line = get_next_line(fd);
	if (super_line[0] != '1')
	{
		free(super_line);
		return (write(1, "error first char\n", 18), NULL);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (line[0] != '1')
		{
			free(line);
			free(super_line);
			return(write(1, "error first char\n", 18), NULL);
		}
		super_line = ft_strjoin(super_line, line);
		free(line);
		if (!ft_checkline(super_line))
			free(super_line);
	}
	if (super_line)
		return (ft_split(super_line, '\n'));
	return (NULL);
}

int	ft_checkshape(char **map, t_data data)
{
	while (map[data.w])
		data.w++;
	while (map[0][data.l])
		data.l++;
	data.j = data.l;
	data.w = 0;
	while (map[data.w])
	{
		data.l = 0;
		while (map[data.w][data.l])
			data.l++;
		if (data.j != data.l)
			return (0);
		data.w++;
	}
	write(1,"shape ok\n", 10);
	return (1);
}

int	ft_validmap(char **map, t_data data)
{
	while (map[data.w][data.l])
	{
		if (map[data.w][data.l] != '1')
			return (write(1, "error first line\n", 18), 0);
		data.l++; 
	}
	while (map[data.w])
	{
		if (map[data.w][0] != '1' || map[data.w][data.l - 1] != '1') // -1 bc \0
			return (write(1, "error columns\n", 15), 0);
		data.w++;
	}
	data.l = 0;
	data.w--;
	while (map[data.w][data.l])
	{
		if (map[data.w][data.l] != '1')
			return (write(1,"error last line", 16), 0);
		data.l++;
	}
	return (write(1,"walls ok\n",10), 1);
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
		return (0);
	}
	else if (c < 1)
	{
		write(2, "no collectible\n", 14);
		return (0);
	}
	else
		return (write(1,"characters count ok\n", 21), 1);

}

int	ft_characters(char **map, t_data data)
{
	while (map[data.w])
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
				return (write(1,"error\n",7), 0);
			data.l++;
		}
		data.w++;
	}
	if (char_count(data.e_count, data.p_count, data.c_count) == 0 )
		return (0); 
	return (1);
}
int	wcount(char **map)
{	
	int w;
	int l;

	w = 0;
	l = 0;
	while (map[w])
	{
		w++;
	}
	return (w);
	printf("lines = %d", w);
}

char	*ft_strdup(const char *source)
{
	int		i;
	int		l;
	char	*copy;

	i = 0;
	l = ft_strlen(source);
	copy = (char *)malloc((l + 1) * sizeof (char));
	if (!copy)
		return (NULL);
	while (source[i] != '\0')
	{
		copy[i] = source[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**map_copy(char **map)
{
	int	i;
	int	j;
	char	**copy;

	i = 0;
	j = wcount(map);
	copy = (char **)ft_calloc((j + 1) , sizeof (char *));
	if (!copy)
		return (NULL);
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (NULL);
		i++;
	}
	return (copy);
}
void	floodfill(int w, int l, char **map)
{
	map[w][l] = '1';
	if (map[w -1][l] != '1') // haut
		floodfill(w -1, l, map);
	if (map[w +1][l] != '1') // bas
		floodfill(w +1, l, map);
	if (map[w][l -1] != '1') // gauche
		floodfill(w, l -1, map);
	if (map[w][l +1] != '1') // droite
		floodfill(w, l +1, map);
}

void	findplayer(int *pos,char **map)
{
	int	i;
	int	w;
	int	l;

	i = 0;
	w = 0;
	while (map[w])
	{
		l = 0;
		while (map[w][l])
		{
			if (map[w][l] == 'P')
				break;
			l++;
		}
		if (map[w][l] == 'P')
			break;
		w++;
	}
	pos[0] = w;
	pos[1] = l;
}

int	check_path(char **map)
{
	int	w;
	int	l;

	w = 0;
	while (map[w])
	{
		l = 0;
		while (map[w][l])
		{
			if (map[w][l] != '0' && map[w][l] != '1')
				return (write(1, "wrong map\n",11),0);
			l++;
		}
		w++;
	}
	return (1);
}
	
int	main(int argc, char **argv)
{
	char	**map;
	char	**copy = NULL;
	static t_data	data = {0};

	map = NULL;
	if (argc == 2)
	{
		if (check_map(argv[1], data))
		{
			map = build_tab(argv[1]);
			if (map == NULL)
				return (1);
			if (!ft_checkshape(map, data))
				return (write(1,"wrong map shape\n",17), 0);
			if (!ft_validmap(map, data))
				return(1);
			if (!ft_characters(map, data))
				return (1);
		}
		int	pos[2];
		copy = map_copy(map);
		findplayer(pos,copy);
		floodfill(pos[0], pos[1], copy);
		if (check_path(copy))
			write(1,"Map ok\n", 8);
	}
	else
		write(1, "Argument invalide\n", 19);

	int	i, j;

	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			write(1, &copy[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (1);
}