/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:45:01 by canocent          #+#    #+#             */
/*   Updated: 2023/09/27 12:30:37 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	char_count(int e, int p, int c)
{
	if (e != 1)
	{
		write(2, "wrong exit count\n", 18);
		return (0);
	}	
	else if (p != 1)
	{
		write(2, "wrong player count\n", 20);
		return (0);
	}
	else if (c < 1)
	{
		write(2, "no collectible\n", 16);
		return (0);
	}
	else
		return (1);
}

int	ft_characters(char **map, t_data *data)
{
	while (map[data->w])
	{
		data->l = 0;
		while (map[data->w][data->l])
		{
			if (map[data->w][data->l] == 'E')
					data->e_count++;
			else if (map[data->w][data->l] == 'P')
					data->p_count++;
			else if (map[data->w][data->l] == 'C')
					data->c_count++;
			else if (map[data->w][data->l] != '1' &&
				map[data->w][data->l] != '0')
				return (write(1, "error with characters\n", 23), 0);
			data->l++;
		}
		data->w++;
	}
	if (char_count(data->e_count, data->p_count, data->c_count) == 0)
		return (0);
	return (1);
}
