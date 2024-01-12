/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:17:19 by ntairatt          #+#    #+#             */
/*   Updated: 2023/02/10 07:39:33 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmpset(char const s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	end;
	size_t	start;
	size_t	i;

	end = ft_strlen(s1);
	start = 0;
	i = 0;
	while (cmpset(s1[start], set) && *s1)
		start++;
	while (cmpset(s1[end - 1], set) && end > start)
		end--;
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (0);
	while (start < end)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
