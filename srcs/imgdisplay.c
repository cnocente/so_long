/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgdisplay.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:49:52 by canocent          #+#    #+#             */
/*   Updated: 2023/09/15 17:19:30 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_int.h>
#include <mlx.h>
#include "so_long.h"

int	ok(int button, t_data *data)
{
	if (button == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		free(data->win_ptr);
	}
	printf("Keypress: %d\n", button);
	return (0);
}


int	handle_no_event(void *data)
{
	if (data)
		return (0);
	/* This function needs to exist, but it is useless for the moment */
	return (1);
}
void	free_imgs()
{
	free(img[0]);
	free(img[1]);
	free(img[2]);
	free(img[3]);
	free(img[4]);
	
}
void	showmap(char **map)
{	
	int			w;
	int			l;
	t_data		data;
	t_images	img[5];
	int			img_width;
	int			img_height;
	
	w = 0;
	l = 0;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		exit (0); // TODO: free everything else
	img[0].img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "img/grass.xpm", &img_width, &img_height);
	img[1].img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "img/trees.xpm", &img_width, &img_height);
	img[2].img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "img/lapincreepy.xpm", &img_width, &img_height);
	img[3].img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "img/exit.xpm", &img_width, &img_height);
	img[4].img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "img/bellbag.xpm", &img_width, &img_height);
	if (!img[0].img_ptr || !img[1].img_ptr || !img[2].img_ptr
		|| !img[3].img_ptr || !img[4].img_ptr)
		{
			free_imgs();
			free(data.mlx_ptr);
			exit(0); // TODO: free everything else
		}
	data.win_ptr = mlx_new_window(data.mlx_ptr, 13*40, 5*40, "Animal Crossing");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		exit(0); // TODO: free everything else
	}
	while(map[w])
	{
		l = 0;
		while (map[w][l] != '\0')
		{
			if(map[w][l] == '0')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img[0].img_ptr, l * 40, w * 40);
			if(map[w][l] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img[1].img_ptr, l * 40, w * 40);
			if(map[w][l] == 'P')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img[2].img_ptr, l * 40, w * 40);
			if(map[w][l] == 'E')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img[3].img_ptr, l * 40, w * 40);
			if(map[w][l] == 'C')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img[4].img_ptr, l * 40, w * 40);
			l++;
		}
		w++;
	}
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ok, &data);
	mlx_loop(data.mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}