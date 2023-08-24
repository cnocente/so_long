/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:23:40 by canocent          #+#    #+#             */
/*   Updated: 2023/06/20 13:47:46 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putadd(unsigned long n);
int	ft_putchar(char c);
int	ft_puthexa(unsigned int n, char c);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putunsigned(unsigned int n);

#endif /* FT_PRINTF_H */