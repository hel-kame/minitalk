/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:58:20 by hel-kame          #+#    #+#             */
/*   Updated: 2022/11/13 19:19:23 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (start >= ft_strlen(s))
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[i] = '\0';
		return (str);
	}
	if (s == NULL)
		return (NULL);
	if (len <= ft_strlen(s) - start)
		str = (char *)malloc(sizeof(char) * (len + 1));
	else
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) - start) + 1);
	if (!str)
		return (NULL);
	while (start < ft_strlen(s) && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
