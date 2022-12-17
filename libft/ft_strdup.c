/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:48:04 by hel-kame          #+#    #+#             */
/*   Updated: 2022/11/17 10:57:01 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*cpy;

	i = 0;
	size = ft_strlen(s1);
	cpy = (char *)malloc(sizeof(char) * (size + 1));
	if (!(cpy))
		return (NULL);
	while (i < size)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[size] = '\0';
	return (cpy);
}
