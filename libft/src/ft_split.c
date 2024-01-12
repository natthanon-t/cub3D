/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:16:45 by ntairatt          #+#    #+#             */
/*   Updated: 2023/02/19 11:00:11 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countword(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		count++;
		while (*s && *s == c)
			s++;
	}
	return (count);
}

static size_t	wordsize(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

static char	*makeword(char const *s, size_t wordsize)
{
	size_t	i;
	char	*w;

	i = 0;
	w = (char *)malloc((wordsize + 1) * sizeof(char));
	if (!w)
		return (0);
	while (wordsize--)
	{
		w[i] = s[i];
		i++;
	}
	w[i] = '\0';
	return (w);
}

static char	**freeword(char **s, int n)
{
	while (n >= 0)
		free(s[n--]);
	free(s);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	**str_sp;
	size_t	i;

	i = 0;
	len = countword(s, c);
	str_sp = (char **)malloc((len + 1) * sizeof(char *));
	if (!str_sp)
		return (0);
	while (i < len)
	{
		while (*s && *s == c)
			s++;
		*(str_sp + i) = makeword(s, wordsize(s, c));
		if (!*(str_sp + i))
			return (freeword(str_sp, i - 1));
		else
		{
			s += wordsize(s, c);
			i++;
		}
	}
	str_sp[len] = 0;
	return (str_sp);
}
