/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:17:24 by ntairatt          #+#    #+#             */
/*   Updated: 2023/11/22 15:35:14 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;
	size_t	n;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		ss = (char *)malloc(sizeof(char));
		if (!ss)
			return (0);
		ss[0] = '\0';
		return (ss);
	}
	n = start + len;
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ss = (char *)malloc((len + 1) * sizeof(char));
	if (!ss)
		return (0);
	while (start < n && s[start])
		ss[i++] = s[start++];
	ss[i] = '\0';
	return (ss);
}
