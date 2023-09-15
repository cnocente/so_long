/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_making.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:12:08 by canocent          #+#    #+#             */
/*   Updated: 2023/09/14 15:07:25 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**build_tab(char	*str)
{
	char	*super_line;
	char	*line;
	int		fd;

	fd = open(str, O_RDONLY);
	super_line = get_next_line(fd);
	if (super_line[0] != '1')
		return (free(super_line), write(1, "error first char\n", 18), NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] != '1')
			return (free(line), free(super_line), \
			write(1, "error first char\n", 18), NULL);
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
	write(1, "shape ok\n", 10);
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
			return (write(1, "error last line", 16), 0);
		data.l++;
	}
	return (write(1, "walls ok\n", 10), 1);
}
