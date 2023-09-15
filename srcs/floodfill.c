/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:45:24 by canocent          #+#    #+#             */
/*   Updated: 2023/09/11 14:46:34 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
