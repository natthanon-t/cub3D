/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:23:27 by ntairatt          #+#    #+#             */
/*   Updated: 2023/02/19 10:59:50 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dt;
	const char	*sc;

	if (!dest && !src)
		return (0);
	dt = dest;
	sc = src;
	if (dt < sc)
	{
		while (n--)
			*dt++ = *sc++;
	}
	else
	{
		while (n--)
			*(dt + n) = *(sc + n);
	}
	return (dest);
}
