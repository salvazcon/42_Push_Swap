/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:16:17 by saazcon-          #+#    #+#             */
/*   Updated: 2023/04/11 17:55:19 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_free_split(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)ft_strlen(s) < start)
	{
		dst = calloc(sizeof(char), 1);
		if (!dst)
			return (NULL);
		return (dst);
	}
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	dst = calloc(sizeof(char), len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (len > i)
	{
		dst[i] = s[start + i];
		i++;
	}
	return (dst);
}

static int	ft_lword(char *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i + len] != c && s[i + len] != '\0')
		len++;
	return (len);
}

static int	ft_nword(char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (words);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	int		nword;
	int		j;
	int		i;

	if (!s)
		return (NULL);
	nword = ft_nword(s, c);
	split = calloc(sizeof(char *), (nword + 1));
	if (!split)
		return (NULL);
	j = 0;
	i = 0;
	while (j < nword)
	{
		while (s[i] == c)
			i++;
		split[j] = ft_substr(s, i, ft_lword(s, i, c));
		if (!split[j])
			return (ft_free_split(split, j));
		i = i + ft_lword(s, i, c);
		j++;
	}
	split[j] = NULL;
	return (split);
}
