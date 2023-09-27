/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:52:53 by canocent          #+#    #+#             */
/*   Updated: 2023/09/27 12:29:38 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	wcount(char **map)
{	
	int	w;
	int	l;

	w = 0;
	l = 0;
	while (map[w])
	{
		w++;
	}
	return (w);
}

void	freetab(char **map)
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

char	**map_copy(char **map)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	j = wcount(map);
	copy = (char **)ft_calloc((j + 1), sizeof (char *));
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
