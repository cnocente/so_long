/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgdisplay.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:49:52 by canocent          #+#    #+#             */
/*   Updated: 2023/09/27 15:26:48 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <mlx.h>
#include <mlx_int.h>

void	image_to_window(t_data *data)
{
	data->w = 0;
	while (data->mapp[data->w])
	{
		data->l = 0;
		while (data->mapp[data->w][data->l] != '\0')
		{
			if (data->mapp[data->w][data->l] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[0].img_ptr, data->l * 40, data->w * 40);
			if (data->mapp[data->w][data->l] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[1].img_ptr, data->l * 40, data->w * 40);
			if (data->mapp[data->w][data->l] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[2].img_ptr, data->l * 40, data->w * 40);
			if (data->mapp[data->w][data->l] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[3].img_ptr, data->l * 40, data->w * 40);
			if (data->mapp[data->w][data->l] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[4].img_ptr, data->l * 40, data->w * 40);
			data->l++;
		}
		data->w++;
	}
}

void	moveplayer(int button, t_data *data)
{
	if (button == 65362)
		ft_go_up(data);
	if (button == 65364)
		ft_go_down(data);
	if (button == 65361)
		ft_go_left(data);
	if (button == 65363)
		ft_go_right(data);
	image_to_window(data);
}

int	tab_height(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

t_data	*init(t_data *data, int img_width, int img_height)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(0);
	data->img[0].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/grass.xpm", &img_width, &img_height);
	data->img[1].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/trees.xpm", &img_width, &img_height);
	data->img[2].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/lapincreepy.xpm", &img_width, &img_height);
	data->img[3].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/exit.xpm", &img_width, &img_height);
	data->img[4].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/bellbag.xpm", &img_width, &img_height);
	if (!data->img[0].img_ptr || !data->img[1].img_ptr || !data->img[2].img_ptr
		|| !data->img[3].img_ptr || !data->img[4].img_ptr)
		return (ft_printf(NO_IMG), ft_destroy(data), NULL);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map_length * 40,
			data->map_height * 40, "Animal Crossing");
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
		exit(0);
	}
	return (data);
}

void	game(char **map, t_data *data)
{
	int	img_width;
	int	img_height;

	data->map_length = ft_strlen(map[0]);
	data->map_height = tab_height(map);
	data->w = 0;
	data->l = 0;
	img_height = 0;
	img_width = 0;
	data->mapp = map;
	if (data->map_length > 48 || data->map_height > 27)
		return (ft_destroy(data));
	data = init(data, img_width, img_height);
	image_to_window(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &close_window, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &close_cross,
		data);
	mlx_loop(data->mlx_ptr);
}
