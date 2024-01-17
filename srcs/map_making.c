/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_making.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:12:08 by canocent          #+#    #+#             */
/*   Updated: 2023/10/05 16:04:03 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*tab_content(char *super_line, int fd)
{
	char	*tmp;
	char	*line;

	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] != '1')
			return (free(line), free(super_line),
				write(1, "error first char\n", 18), NULL);
		tmp = super_line;
		super_line = ft_strjoin(super_line, line);
		if (!super_line)
			return (NULL);
		free(tmp);
		free(line);
		if (!ft_checkline(super_line))
			break ;
	}
	return (super_line);
}

char	**build_tab(char *str)
{
	char	*super_line;
	int		fd;
	char	**split_return;

	fd = open(str, O_RDONLY);
	super_line = get_next_line(fd);
	if (!super_line)
		return (ft_printf("no existing file\n"), NULL);
	split_return = NULL;
	if (super_line[0] != '1')
	{
		close(fd);
		return (free(super_line), write(1, "error first char\n", 18), NULL);
	}
	super_line = tab_content(super_line, fd);
	close(fd);
	if (super_line)
	{
		split_return = ft_split(super_line, '\n');
		free(super_line);
		return (split_return);
	}
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
	write(1, "shape is ok\n", 13);
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
		if (map[data.w][0] != '1' || map[data.w][data.l - 1] != '1')
			return (write(1, "error columns\n", 15), 0);
		data.w++;
	}
	data.l = 0;
	data.w--;
	while (map[data.w][data.l])
	{
		if (map[data.w][data.l] != '1')
			return (write(1, "error last line\n", 17), 0);
		data.l++;
	}
	return (write(1, "walls are ok\n", 14), 1);
}
