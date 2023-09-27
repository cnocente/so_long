/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvplayer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:42:55 by canocent          #+#    #+#             */
/*   Updated: 2023/09/27 12:34:44 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <mlx.h>
#include <mlx_int.h>

void	ft_go_up(t_data *data)
{
	if (data->mapp[data->player_pos_x - 1][data->player_pos_y] == '1')
		return ((void)write(1, "you can't go this way :(\n", 26));
	if (data->e == false)
		data->mapp[data->player_pos_x][data->player_pos_y] = '0';
	else
		data->mapp[data->player_pos_x][data->player_pos_y] = 'E';
	if (data->mapp[data->player_pos_x - 1][data->player_pos_y] == 'E')
		data->e = true;
	else
		data->e = false;
	if (data->mapp[data->player_pos_x - 1][data->player_pos_y] == 'C')
		data->c_count--;
	if (data->mapp[data->player_pos_x - 1][data->player_pos_y] == 'E'
		&& data->c_count == 0)
	{
		data->mapp[data->player_pos_x - 1][data->player_pos_y] = 'P';
		data->mapp[data->player_pos_x][data->player_pos_y] = '0';
		write(1, "you won :D", 11);
		close_cross(data);
	}
	data->mapp[data->player_pos_x - 1][data->player_pos_y] = 'P';
	data->player_pos_x--;
	data->move++;
	ft_printf("moves = %d\n", data->move);
}

void	ft_go_down(t_data *data)
{
	if (data->mapp[data->player_pos_x + 1][data->player_pos_y] == '1')
		return ((void)write(1, "you can't go this way :(\n", 26));
	if (data->e == false)
		data->mapp[data->player_pos_x][data->player_pos_y] = '0';
	else
		data->mapp[data->player_pos_x][data->player_pos_y] = 'E';
	if (data->mapp[data->player_pos_x + 1][data->player_pos_y] == 'E')
		data->e = true;
	else
		data->e = false;
	if (data->mapp[data->player_pos_x + 1][data->player_pos_y] == 'C')
		data->c_count--;
	if (data->mapp[data->player_pos_x + 1][data->player_pos_y] == 'E'
		&& data->c_count == 0)
	{
		data->mapp[data->player_pos_x + 1][data->player_pos_y] = 'P';
		data->mapp[data->player_pos_x][data->player_pos_y] = '0';
		write(1, "you won :D", 11);
		close_cross(data);
	}
	data->mapp[data->player_pos_x + 1][data->player_pos_y] = 'P';
	data->player_pos_x++;
	data->move++;
	ft_printf("moves = %d\n", data->move);
}

void	ft_go_left(t_data *data)
{
	if (data->mapp[data->player_pos_x][data->player_pos_y - 1] == '1')
		return ((void)write(1, "you can't go this way :(\n", 26));
	if (data->e == false)
		data->mapp[data->player_pos_x][data->player_pos_y] = '0';
	else
		data->mapp[data->player_pos_x][data->player_pos_y] = 'E';
	if (data->mapp[data->player_pos_x][data->player_pos_y - 1] == 'E')
		data->e = true;
	else
		data->e = false;
	if (data->mapp[data->player_pos_x][data->player_pos_y - 1] == 'C')
		data->c_count--;
	if (data->mapp[data->player_pos_x][data->player_pos_y - 1] == 'E'
		&& data->c_count == 0)
	{
		data->mapp[data->player_pos_x][data->player_pos_y - 1] = 'P';
		data->mapp[data->player_pos_x][data->player_pos_y] = '0';
		write(1, "you won :D", 11);
		close_cross(data);
	}
	data->mapp[data->player_pos_x][data->player_pos_y - 1] = 'P';
	data->player_pos_y--;
	data->move++;
	ft_printf("moves = %d\n", data->move);
}

void	ft_go_right(t_data *data)
{
	if (data->mapp[data->player_pos_x][data->player_pos_y + 1] == '1')
		return ((void)write(1, "you can't go this way :(\n", 26));
	data->move++;
	ft_printf("moves = %d\n", data->move);
	if (data->e == false)
		data->mapp[data->player_pos_x][data->player_pos_y] = '0';
	else
		data->mapp[data->player_pos_x][data->player_pos_y] = 'E';
	if (data->mapp[data->player_pos_x][data->player_pos_y + 1] == 'E')
		data->e = true;
	else
		data->e = false;
	if (data->mapp[data->player_pos_x][data->player_pos_y + 1] == 'C')
		data->c_count--;
	if (data->mapp[data->player_pos_x][data->player_pos_y + 1] == 'E'
		&& data->c_count == 0)
	{
		data->mapp[data->player_pos_x][data->player_pos_y + 1] = 'P';
		data->mapp[data->player_pos_x][data->player_pos_y] = '0';
		write(1, "you won :D", 11);
		close_cross(data);
	}
	data->mapp[data->player_pos_x][data->player_pos_y + 1] = 'P';
	data->player_pos_y++;
}

void	ft_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (data->img[i].img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->img[i].img_ptr);
		i++;
	}
	if (!data->mlx_ptr)
		return ;
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	exit(0);
}
