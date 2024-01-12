/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:06:18 by ntairatt          #+#    #+#             */
/*   Updated: 2023/02/19 11:00:34 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	n;
	size_t	i;

	i = 0;
	n = ft_strlen(s);
	p = (char *)malloc((n + 1) * sizeof(char));
	if (!p)
		return (0);
	while (n--)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
