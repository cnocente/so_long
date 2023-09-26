# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: canocent <canocent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 14:06:05 by canocent          #+#    #+#              #
#    Updated: 2023/09/26 16:50:57 by canocent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
	
SRCS		=	srcs/copy_map.c \
				srcs/floodfill.c \
				srcs/inside_map.c \
				srcs/map_making.c \
				srcs/parsing.c\
				srcs/imgdisplay.c\
				srcs/mvplayer.c\
				srcs/closewin.c 
				
	
CC			=	clang
	
CFFLAGS		=	-Wall -Wextra -Werror -g3

INCLUDES	=	-I. -Iminilibx-linux/. 

LIB			=	-Lminilibx-linux -lmlx -lXext -lX11 -Llibft -lft -Lft_printf -Lft_printf

OBJS		=	$(SRCS:%.c=%.o)

all	:	$(NAME)

%.o	:	%.c
	$(CC) $(CFFLAGS) $(INCLUDES) -c $< -o $@

$(NAME)	:	$(OBJS)
	make -C minilibx-linux
	make -C libft
# make -C libft/ft_printf
	$(CC) $(CFFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)

clean :
	rm -rf $(OBJS)
	make -C minilibx-linux clean
	make -C libft clean
# make -C libft/ft_printf clean

fclean : clean
	rm -rf $(NAME)
	make -C libft fclean
# make -C libft/ft_printf fclean

re : fclean all

.PHONY: all clean fclean re
