/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:49:15 by hel-kame          #+#    #+#             */
/*   Updated: 2022/11/16 14:09:44 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, char const *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	y;
	size_t	length;
	char	*str;

	i = 0;
	y = 0;
	length = 0;
	while (s1[i] != '\0' && is_charset(s1[i], set))
		i++;
	while (s1[i + length])
		length++;
	while ((is_charset(s1[i + (length - 1)], set)) && length > 0)
		length--;
	str = malloc(sizeof(char) * length + 1);
	if (!(str))
		return (NULL);
	while (y < length)
	{
		str[y] = s1[i + y];
		y++;
	}
	str[y] = '\0';
	return (str);
}
