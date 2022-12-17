/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:36:27 by hel-kame          #+#    #+#             */
/*   Updated: 2022/11/16 13:10:27 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == charset)
			i++;
		if (str[i] != '\0' && str[i] != charset)
			count++;
		while (str[i] != '\0' && str[i] != charset)
			i++;
	}
	return (count + 1);
}

static int	free_tab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (-1);
}

static int	word_length(char const *str, char charset, char **tab, int length)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		len = 0;
		while (str[i] != '\0' && str[i] == charset)
			i++;
		while (str[i] != '\0' && str[i] != charset)
		{
			i++;
			len++;
		}
		if (j < length)
		{
			tab[j] = malloc(sizeof(char) * (len + 1));
			if (!(tab))
				return (free_tab(tab, j - 1));
			j++;
		}
	}
	return (0);
}

static void	word_write(char const *str, char charset, char **tab, int length)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		k = 0;
		while (str[i] != '\0' && str[i] == charset)
			i++;
		while (str[i] != '\0' && str[i] != charset)
		{
			tab[j][k] = str[i];
			k++;
			i++;
		}
		if (j < length)
		{
			tab[j][k] = '\0';
			j++;
		}
	}
	tab[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		len;

	len = word_count(s, c);
	tab = malloc(sizeof(char *) * len);
	if (!(tab))
		return (NULL);
	if (word_length(s, c, tab, len - 1) == -1)
		return (NULL);
	word_write(s, c, tab, len - 1);
	return (tab);
}
