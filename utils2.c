/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:23 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/05 08:33:35 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**ft_realloc2d(char **ptr, size_t size)
{
	size_t	i;
	char	**temp;

	i = 0;
	temp = (char **)ft_calloc(size + 1 , sizeof(char *));
	if (!temp)
		return (NULL);
	while (ptr[i])
	{
		temp[i] = ptr[i];
		i++;
	}
	//ft_free_str2d(ptr);
	return (temp);
}
