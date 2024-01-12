/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:58:51 by ntairatt          #+#    #+#             */
/*   Updated: 2023/02/19 10:59:43 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dt;
	const char	*sc;

	if (!dest && !src)
		return (0);
	dt = dest;
	sc = src;
	while (n--)
		*dt++ = *sc++;
	return (dest);
}
