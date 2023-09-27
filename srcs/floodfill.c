/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:45:24 by canocent          #+#    #+#             */
/*   Updated: 2023/09/27 12:30:18 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	floodfill(int w, int l, char **map)
{
	map[w][l] = '1';
	if (map[w -1][l] != '1')
		floodfill(w -1, l, map);
	if (map[w +1][l] != '1')
		floodfill(w +1, l, map);
	if (map[w][l -1] != '1')
		floodfill(w, l -1, map);
	if (map[w][l +1] != '1')
		floodfill(w, l +1, map);
}

void	findplayer(int *pos, char **map)
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
				break ;
			l++;
		}
		if (map[w][l] == 'P')
			break ;
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
				return (write(1, "wrong map\n", 11), 0);
			l++;
		}
		w++;
	}
	return (1);
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
	if (!copy)
		return (false);
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
