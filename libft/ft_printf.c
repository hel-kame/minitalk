/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:16:55 by hel-kame          #+#    #+#             */
/*   Updated: 2022/11/26 11:44:15 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_flags(const char *f, va_list args)
{
	if (*f == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*f == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*f == 'p')
		return (ft_print_memory(va_arg(args, void *)));
	else if (*f == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (*f == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*f == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (*f == 'x')
		return (ft_puthexa(va_arg(args, unsigned int)));
	else if (*f == 'X')
		return (ft_puthexa_maj(va_arg(args, unsigned int)));
	else if (*f == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		i;
	int		ret;

	va_start(args, f);
	i = 0;
	ret = 0;
	while (f[i] != '\0')
	{
		while (f[i] != '%' && f[i] != '\0')
		{
			ret += ft_putchar(f[i]);
			i++;
		}
		if (f[i] == '%')
		{
			ret += ft_flags((f + i) + 1, args);
			i += 2;
		}
	}
	va_end(args);
	return (ret);
}
