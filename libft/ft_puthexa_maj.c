/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:22:51 by hel-kame          #+#    #+#             */
/*   Updated: 2022/11/26 11:59:49 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_size(unsigned int nb)
{
	int				size;

	size = 1;
	while (nb >= 16)
	{
		size++;
		nb /= 16;
	}
	return (size);
}

int	ft_puthexa_maj(unsigned int nb)
{
	char				*base;
	unsigned int		length;

	base = "0123456789ABCDEF";
	length = 0;
	while (base[length] != '\0')
		length++;
	if (nb == 0)
		ft_putchar ('0');
	if (nb > 0 && nb < length)
		ft_putchar(base[nb]);
	if (nb >= length)
	{
		ft_puthexa_maj(nb / length);
		ft_puthexa_maj(nb % length);
	}
	return (nb_size(nb));
}
