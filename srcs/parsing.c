/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:38:08 by canocent          #+#    #+#             */
/*   Updated: 2023/09/25 15:28:02 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdbool.h> // true == 1 false == 0
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (!s1[i] && !s2[i])
	{
		return (1);
	}
	return (0);
}

bool	check_map(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (false);
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			if (ft_strcmp(".ber", str + i))
				return (true);
		i++;
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
	return (write(1, "lines are ok\n", 14), 1);
}

void	free_copy(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

bool	check_path_format(char **map, t_data *data)
{
	int		pos[2];
	char	**copy;

	copy = NULL;
	if (!ft_checkshape(map, *data))
		return (write(1, "wrong map shape\n", 17), false);
	if (!ft_validmap(map, *data))
		return (false);
	if (!ft_characters(map, data))
		return (false);
	copy = map_copy(map);
	findplayer(pos, copy);
	floodfill(pos[0], pos[1], copy);
	if (check_path(copy))
	{
		data->player_pos_x = pos[0];
		data->player_pos_y = pos[1];
		return (free_copy(copy), true);
	}
	return (free_copy(copy), false);
}

int	main(int argc, char **argv)
{
	char			**map;
	char			**copy;
	static t_data	data;

	ft_bzero(&data, sizeof(t_data));
	copy = NULL;
	map = NULL;
	if (argc != 2 || check_map(argv[1]) == false)
		return (write(1, "wrong argument\n", 16), 2);
	map = build_tab(argv[1]);
	if (map == NULL)
		return (1);
	if (!check_path_format(map, &data))
		return (freetab(map), 1);
	game(map, data);
	freetab(map);
}
