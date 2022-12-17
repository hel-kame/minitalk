/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:19:07 by hel-kame          #+#    #+#             */
/*   Updated: 2022/11/26 11:16:03 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_size(long long unsigned int n)
{
	int	size;

	size = 1;
	while (n >= 16)
	{
		size++;
		n /= 16;
	}
	return (size);
}

static void	convert_hexa(long long unsigned int n)
{
	char					*format;
	long long unsigned int	length;

	format = "0123456789abcdef";
	length = 0;
	while (format[length] != '\0')
		length++;
	if (n == 0)
		ft_putchar('0');
	if (n > 0 && n < length)
		ft_putchar(format[n]);
	if (n >= length)
	{
		convert_hexa(n / length);
		convert_hexa(n % length);
	}
}

int	ft_print_memory(void *s)
{
	long long unsigned int	i;

	i = (long long unsigned int)s;
	if (!s)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr("0x");
	convert_hexa(i);
	return (nb_size((i)) + 2);
}
