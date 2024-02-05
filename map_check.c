/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:57:54 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/05 19:46:37 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	close_check(t_data *prog, size_t i, size_t j)
{
	if (prog->map[i][j] == '0' || (prog->map[i][j] != '1' && \
		prog->map[i][j] != ' '))
	{
		if (!i || !prog->map[i + 1] || !j || !prog->map[i][j + 1])
			return (EXIT_FAILURE);
		else if (prog->map[i - 1] && prog->map[i - 1][j] && \
			prog->map[i - 1][j] == ' ')
			return (EXIT_FAILURE);
		else if (prog->map[i + 1] && prog->map[i + 1][j] && \
			prog->map[i + 1][j] == ' ')
			return (EXIT_FAILURE);
		else if (prog->map[i] && prog->map[i][j - 1] && \
			prog->map[i][j - 1] == ' ')
			return (EXIT_FAILURE);
		else if (prog->map[i] && prog->map[i][j + 1] && \
			prog->map[i][j + 1] == ' ')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	map_check_util(t_data *prog)
{
	size_t	i;
	size_t	j;
	int		player_count;

	i = 0;
	player_count = 0;
	while (prog->map[i])
	{
		j = 0;
		while (prog->map[i][j])
		{
			if (!ft_strchr("01NSEW ", prog->map[i][j]))
				return (0);
			if (prog->map[i][j] == 'N' || prog->map[i][j] == 'S' || \
				prog->map[i][j] == 'E' || prog->map[i][j] == 'W')
			{
				vector_init(prog, j, i);
				player_count++;
			}
			j++;
		}
		i++;
	}
	return (player_count);
}

int	map_check(t_data *prog)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (map_check_util(prog) != 1)
		return (EXIT_FAILURE);
	close(prog->fd);
	while (prog->map[i])
	{
		j = 0;
		while (prog->map[i][j])
		{
			if (close_check(prog, i, j))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
