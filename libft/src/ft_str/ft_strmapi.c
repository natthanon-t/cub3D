/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:17:04 by ntairatt          #+#    #+#             */
/*   Updated: 2023/02/10 12:22:01 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	n;
	char	*sf;

	i = 0;
	n = ft_strlen(s);
	sf = (char *)malloc((n + 1) * sizeof(char));
	if (!sf)
		return (0);
	while (s[i])
	{
		sf[i] = f(i, s[i]);
		i++;
	}
	sf[i] = '\0';
	return (sf);
}
