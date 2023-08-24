/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canocent <canocent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:12:58 by canocent          #+#    #+#             */
/*   Updated: 2023/06/20 11:20:52 by canocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_lenb(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_putunsigned(unsigned int n)
{
	int	len;

	len = ft_lenb(n);
	if (n >= 10)
		ft_putunsigned(n / 10);
	ft_putchar(n % 10 + '0');
	return (len);
}
