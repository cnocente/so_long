/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:38:08 by canocent          #+#    #+#             */
/*   Updated: 2023/09/14 16:50:48 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"
#include <stdbool.h> // true == 1 false == 0

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

bool	check_map(char *str, t_data data)
{
	if (!str || !*str)
		return (false);
	while (str[data.i] != '\0')
	{
		if (str[data.i] == '.')
			if (ft_strcmp (".ber", str + data.i, data))
				return (true);
		data.i++;
	}
	return (false);
}

int	ft_checkline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != '\n'
			&& line[i] != 'E' && line[i] != 'P' && line[i] != 'C')
			return (write(1, "wrong character\n", 16), 0);
		i++;
	}
	return (printf("line ok\n"), 1);
}

bool	check_path_format(char**map, t_data data)
{
	int		pos[2];
	char	**copy;

	copy = NULL;
	if (!ft_checkshape(map, data))
		return (write(1, "wrong map shape\n", 17), false);
	if (!ft_validmap(map, data))
		return (false);
	if (!ft_characters(map, data))
		return (false);
	copy = map_copy(map);
	findplayer(pos, copy);
	floodfill(pos[0], pos[1], copy);
	if (check_path(copy))
		return (free(copy), true);
	return (free(copy), false);
}

int	main(int argc, char **argv)
{
	char			**map;
	char			**copy;
	static t_data	data = {0};

	copy = NULL;
	map = NULL;
	if (argc != 2 || check_map(argv[1], data) == false)
		return (write(1, "Argument invalide\n", 19), 2);
	map = build_tab(argv[1]);
	if (map == NULL)
		return (1);
	check_path_format(map, data);
	showmap(map);
}
