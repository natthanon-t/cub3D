/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:23 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/02 23:05:24 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**ft_realloc2d(char **ptr, size_t size)
{
	size_t	i;
	char	**temp;

	i = 0;
	temp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!temp)
		return (NULL);
	while (ptr[i])
	{
		temp[i] = ptr[i];
		i++;
	}
	temp[size - 1] = NULL;
	ft_free_str2d(ptr);
	return (temp);
}
