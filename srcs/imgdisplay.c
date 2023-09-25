/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgdisplay.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:49:52 by canocent          #+#    #+#             */
/*   Updated: 2023/09/25 15:14:55 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <mlx_int.h>

void	moveplayer(int button, t_data *data)
{
	int	w;
	int	l;

	w = 0;
	l = 0;
	if (button == 65362)
		ft_go_up(data);
	if (button == 65364)
		ft_go_down(data);
	if (button == 65361)
		ft_go_left(data);
	if (button == 65363)
		ft_go_right(data);
	while (data->mapp[w])
	{
		l = 0;
		while (data->mapp[w][l] != '\0')
		{
			if (data->mapp[w][l] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[0].img_ptr, l * 40, w * 40);
			if (data->mapp[w][l] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[1].img_ptr, l * 40, w * 40);
			if (data->mapp[w][l] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[2].img_ptr, l * 40, w * 40);
			if (data->mapp[w][l] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[3].img_ptr, l * 40, w * 40);
			if (data->mapp[w][l] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[4].img_ptr, l * 40, w * 40);
			l++;
		}
		w++;
	}
}

int	close_window(int button, t_data *data)
{
	int	i;
	int	w;
	int	l;

	w = 0;
	l = 0;
	i = 0;
	if (button == XK_Escape)
		ft_destroy(data);
	else
		moveplayer(button, data);
	return (0);
}

int	close_cross(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img[0].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img[1].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img[2].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img[3].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img[4].img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	exit(0);
}

int	handle_no_event(void *data)
{
	if (data)
		return (0);
	/* This function needs to exist, but it is useless for the moment */
	return (1);
}

int	tab_height(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void	game(char **map, t_data data)
{
	int	w;
	int	l;
	int	img_width;
	int	img_height;
	int	map_length;
	int	map_height;

	map_length = ft_strlen(map[0]);
	map_height = tab_height(map);
	w = 0;
	l = 0;
	data.mapp = map;
	if (map_length > 48 || map_height > 27)
		return (ft_destroy(&data));
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		exit(0);
	data.img[0].img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "img/grass.xpm",
			&img_width, &img_height);
	data.img[1].img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "img/trees.xpm",
			&img_width, &img_height);
	data.img[2].img_ptr = mlx_xpm_file_to_image(data.mlx_ptr,
			"img/lapincreepy.xpm", &img_width, &img_height);
	data.img[3].img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "img/exit.xpm",
			&img_width, &img_height);
	data.img[4].img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "img/bellbag.xpm",
			&img_width, &img_height);
	if (!data.img[0].img_ptr || !data.img[1].img_ptr || !data.img[2].img_ptr
		|| !data.img[3].img_ptr || !data.img[4].img_ptr)
		exit(0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, map_length * 40, map_height
			* 40, "Animal Crossing");
	// faire en sorte que la taille varie en fonction de la map; si too big quit
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		data.mlx_ptr = NULL;
		exit(0);
	}
	while (map[w])
	{
		l = 0;
		while (map[w][l] != '\0')
		{
			if (map[w][l] == '0')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					data.img[0].img_ptr, l * 40, w * 40);
			if (map[w][l] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					data.img[1].img_ptr, l * 40, w * 40);
			if (map[w][l] == 'P')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					data.img[2].img_ptr, l * 40, w * 40);
			if (map[w][l] == 'E')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					data.img[3].img_ptr, l * 40, w * 40);
			if (map[w][l] == 'C')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
					data.img[4].img_ptr, l * 40, w * 40);
			l++;
		}
		w++;
	}
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &close_window, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &close_cross,
		&data);
	mlx_loop(data.mlx_ptr);
	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	data.mlx_ptr = NULL;
}