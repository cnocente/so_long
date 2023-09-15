/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:24:43 by canocent          #+#    #+#             */
/*   Updated: 2023/09/15 14:35:19 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
#include <stdbool.h>

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;//nb de bytes par pixel (3 ou 4/bleu vert roug et mayne transparent)
	int		line_length;//cbn de pixels par lignes de la fenetre
	int		endian;//lit de droite a gauche ou de gauche a droite???
}t_images;

typedef struct s_data
{
	int		i;
	
	int		w;
	int		l;
	int		j;

	int		p_count;
	int		e_count;
	int		c_count;
	
	void	*mlx_ptr;
	void	*win_ptr;
//minilibx
	t_images jhgfkhg[5];
	
}	t_data;




int	char_count(int e, int p, int c);
int	ft_characters(char **map, t_data data);
int	wcount(char **map);
int	check_path(char **map);
int	ft_checkshape(char **map, t_data data);
int	ft_validmap(char **map, t_data data);
int	ft_checkline(char *line);
void	showmap(char **map);

char	*ft_strdup(const char *source);
char	**map_copy(char **map);
char	**build_tab(char	*str);


void	floodfill(int w, int l, char **map);
void	findplayer(int *pos, char **map);

bool	check_path_format(char** map, t_data data);



#endif