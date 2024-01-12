/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:06:21 by ntairatt          #+#    #+#             */
/*   Updated: 2023/02/19 11:00:50 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dt_len;

	if (!size)
		return (ft_strlen(src));
	dt_len = ft_strlen(dst);
	if (dt_len > size)
		return (ft_strlen(src) + size);
	while (*src && dt_len < size - 1)
	{
		dst[dt_len] = *src++;
		dt_len++;
	}
	dst[dt_len] = '\0';
	return (ft_strlen(src) + ft_strlen(dst));
}
