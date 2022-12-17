/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:17:45 by hel-kame          #+#    #+#             */
/*   Updated: 2022/11/25 17:08:55 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_size(unsigned int n)
{
	int				size;
	long			nb;

	nb = n;
	size = 1;
	while (nb >= 10)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

int	ft_putunbr(unsigned int n)
{
	if (n == 0)
		ft_putchar('0');
	if (n > 0 && n < 10)
		ft_putchar(n + '0');
	if (n > 9)
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
	return (nb_size(n));
}
