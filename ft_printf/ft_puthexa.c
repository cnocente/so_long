/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:48:04 by canocent          #+#    #+#             */
/*   Updated: 2023/06/20 11:20:37 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_length(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_puthexa(unsigned int n, char c)
{
	char	*hexa1;
	char	*hexa2;
	int		len;

	hexa1 = "0123456789abcdef";
	hexa2 = "0123456789ABCDEF";
	len = ft_length(n);
	if (n > 15)
		ft_puthexa(n / 16, c);
	if (c == 'x')
		write(1, &hexa1[n % 16], 1);
	else
		write(1, &hexa2[n % 16], 1);
	return (len);
}
