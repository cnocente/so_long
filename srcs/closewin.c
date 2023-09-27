/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closewin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:50:03 by canocent          #+#    #+#             */
/*   Updated: 2023/09/27 12:34:59 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <mlx.h>
#include <mlx_int.h>

int	close_window(int button, t_data *data)
{
	int	i;
	int	w;
	int	l;

	w = 0;
	l = 0;
	i = 0;
	if (button == XK_Escape)
		close_cross(data);
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
	if (data->mapp)
		freetab(data->mapp);
	free(data->mlx_ptr);
	exit (0);
}
