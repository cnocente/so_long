NAME = libftprintf.a

SRCS =	ft_printf.c\
		ft_putadd.c\
		ft_putchar.c\
		ft_puthexa.c\
		ft_putnbr.c\
		ft_putstr.c\
		ft_putunsigned.c

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJS = ${SRCS:.c=.o}

HEADER = ft_printf.h

RM = rm -rfv

FLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./

$(NAME): ${OBJS} ft_printf.h
	ar cr ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: re all clean fclean
# so:
# $(CC) -nostartfiles -fPIC $(FLAGS) $(SRCS)
# gcc -nostartfiles -shared -o libft.so $(OBJS)