/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:23 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/06 14:48:57 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**ft_realloc2d(char **ptr, size_t size)
{
	size_t	i;
	char	**temp;

	i = 0;
	temp = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!temp)
		return (NULL);
	while (ptr[i])
	{
		temp[i] = ptr[i];
		i++;
	}
	temp[i] = NULL;
	temp[i + 1] = NULL;
	free(ptr);
	return (temp);
}

int	exit_ex(t_data *prog)
{
	int	i;

	i = 0;
	while (i < 4)
		free(prog->xpm[i++]);
	if (prog->map)
		ft_free_str2d(prog->map);
	mlx_destroy_window(prog->mlx.mlx, prog->mlx.window);
	return (exit(EXIT_SUCCESS), 0);
}
