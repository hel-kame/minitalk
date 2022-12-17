/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:48:58 by hel-kame          #+#    #+#             */
/*   Updated: 2022/11/17 11:15:17 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	progress;

	i = 0;
	if (little[i] == '\0')
		return ((char *)&big[i]);
	while (i < len && big[i] != '\0')
	{
		progress = 0;
		while (progress + i < len
			&& little[progress] == big[progress + i])
		{
			if (little[progress + 1] == '\0')
				return ((char *)&big[i]);
			progress++;
		}
		i++;
	}
	return (0);
}
