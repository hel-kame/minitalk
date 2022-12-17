/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:17:32 by hel-kame          #+#    #+#             */
/*   Updated: 2022/11/17 11:17:56 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	val;
	int	neg;

	i = 0;
	val = 0;
	neg = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
		neg = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while ((nptr[i] != '\0') && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		val *= 10;
		val += nptr[i] - '0';
		i++;
	}
	if (neg == 1)
		return (-val);
	else
		return (val);
}
