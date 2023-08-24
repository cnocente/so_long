/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:57:49 by canocent          #+#    #+#             */
/*   Updated: 2023/06/20 13:45:54 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_long(unsigned long nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_putadd(unsigned long n)
{
	char	*hexa;
	int		len;

	hexa = "0123456789abcdef";
	len = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	len = ft_long(n);
	if (n > 15)
		ft_putadd(n / 16);
	write(1, &hexa[n % 16], 1);
	return (len);
}
