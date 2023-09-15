/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:52:53 by canocent          #+#    #+#             */
/*   Updated: 2023/09/11 14:29:17 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
