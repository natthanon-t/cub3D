/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:06:29 by ntairatt          #+#    #+#             */
/*   Updated: 2023/02/11 13:54:24 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if ((char)c == 0)
		return ((char *)s + ft_strlen(s));
	while (i--)
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
	}
	return (0);
}
