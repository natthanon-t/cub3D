/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:16:58 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/02 13:43:19 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fs;
	size_t	i;

	i = 0;
	fs = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char)));
	if (!fs)
		return (NULL);
	while (*s1)
	{
		fs[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		fs[i] = *s2++;
		i++;
	}
	fs[i] = '\0';
	return (fs);
}
