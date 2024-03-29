/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:24:43 by canocent          #+#    #+#             */
/*   Updated: 2023/09/27 15:25:08 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <stdbool.h>

# define NO_IMG "Missing image(s)\n"

typedef struct s_image
{
	void		*img_ptr;
	char		*addr;

	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_images;

typedef struct s_data
{
	int			i;
	int			w;
	int			l;
	int			j;
	int			map_length;
	int			map_height;
	int			player_pos_x;
	int			player_pos_y;
	int			p_count;
	int			e_count;
	int			c_count;
	int			move;
	char		**mapp;
	char		**map;
	void		*mlx_ptr;
	void		*win_ptr;

	bool		e;
	t_images	img[5];

}				t_data;

int				char_count(int e, int p, int c);
int				ft_characters(char **map, t_data *data);
int				wcount(char **map);
int				check_path(char **map);
int				ft_checkshape(char **map, t_data data);
int				ft_validmap(char **map, t_data data);
int				ft_checkline(char *line);
int				close_cross(t_data *data);
int				close_window(int button, t_data *data);

char			*ft_strdup(const char *source);
char			**map_copy(char **map);
char			**build_tab(char *str);

void			game(char **map, t_data *data);
void			floodfill(int w, int l, char **map);
void			findplayer(int *pos, char **map);
void			freetab(char **map);
void			ft_go_up(t_data *data);
void			ft_go_down(t_data *data);
void			ft_go_left(t_data *data);
void			ft_go_right(t_data *data);
void			ft_destroy(t_data *data);
void			free_copy(char **map);
void			moveplayer(int button, t_data *data);

bool			check_path_format(char **map, t_data *data);

#endif