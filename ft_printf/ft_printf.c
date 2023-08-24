/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:00:51 by canocent          #+#    #+#             */
/*   Updated: 2023/06/20 13:47:55 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_checkformat(const char s, va_list params)
{
	int				len;
	unsigned long	add;

	len = 0;
	if (s == 'c')
		len = ft_putchar(va_arg(params, int));
	else if (s == 's')
		len = ft_putstr(va_arg(params, char *));
	else if (s == 'p')
	{
		add = va_arg(params, unsigned long);
		if (add != 0)
			len = ft_putstr("0x");
		len += ft_putadd(add);
	}
	else if (s == 'i' || s == 'd')
		len = ft_putnbr(va_arg(params, int));
	else if (s == 'u')
		len = ft_putunsigned(va_arg(params, unsigned int));
	else if (s == 'x' || s == 'X')
		len = ft_puthexa(va_arg(params, unsigned int), s);
	else
		len = ft_putchar(s);
	return (len);
}	

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		total_len;
	int		i;

	total_len = 0;
	i = 0;
	if (!str || *str == '\0')
		return (0);
	va_start(params, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			total_len += ft_checkformat(str[i + 1], params);
			i++;
		}
		else
			total_len += ft_putchar(str[i]);
		i++;
	}
	va_end (params);
	return (total_len);
}
