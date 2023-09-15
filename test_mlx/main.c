/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:01:36 by canocent          #+#    #+#             */
/*   Updated: 2023/09/14 15:46:13 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <mlx_int.h>
#include <so_long.h>

void	my_mlx_pixel_put(t_images *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ok(int button,int x,int y,void *param)
{
	t_xvar *tmp = (t_xvar *)param;
	(void)x;
	(void)y;
	(void)button;
	(void)param;
	// tout free
	printf("ok\n");
	mlx_destroy_window(tmp, tmp->win_list);
	exit(0);
	return(0);
}

int	main(void)
{
	t_xvar	*mlx; //initialiser minilibx
	// void	*mlx_win; 
	// t_data	img;
	t_images	img[5];
	int img_width, img_height;
	
	mlx = mlx_init();
	img[0].img_ptr = mlx_xpm_file_to_image(mlx, "../img/exit.xpm", &img_width, &img_height);
	img[1].img_ptr = mlx_xpm_file_to_image(mlx, "../img/lapincreepy.xpm", &img_width, &img_height);
	img[2].img_ptr = mlx_xpm_file_to_image(mlx, "../img/trees.xpm", &img_width, &img_height);
	img[3].img_ptr = mlx_xpm_file_to_image(mlx, "../img/grass.xpm", &img_width, &img_height);
	img[4].img_ptr = mlx_xpm_file_to_image(mlx, "../img/bellbag.xpm", &img_width, &img_height);
	mlx->win_list = mlx_new_window(mlx, 500, 500, "Animal Crossing : so_long");
	
	mlx_put_image_to_window(mlx, mlx->win_list, img[0].img_ptr, 0, 0);
	mlx_put_image_to_window(mlx, mlx->win_list, img[1].img_ptr, 40, 0);
	mlx_put_image_to_window(mlx, mlx->win_list, img[2].img_ptr, 80, 0);
	mlx_put_image_to_window(mlx, mlx->win_list, img[3].img_ptr, 120, 0);
	mlx_put_image_to_window(mlx, mlx->win_list, img[4].img_ptr, 160, 0);
	mlx_hook(mlx->win_list, 17, 0, &ok, mlx);
	mlx_loop(mlx);
}