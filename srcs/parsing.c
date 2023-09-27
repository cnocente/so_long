/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:38:08 by canocent          #+#    #+#             */
/*   Updated: 2023/09/27 12:31:09 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdbool.h>
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
	game(map, &data);
	freetab(map);
	return (0);
}
