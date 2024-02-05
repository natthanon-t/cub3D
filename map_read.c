/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:08 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/05 10:44:31 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_read(t_data *prog)
{
	char	*line;

	while (1)
	{
		line = get_next_line(prog->fd);
		if (!line)
			break ;
		if (map_add(prog, line) == EXIT_FAILURE)
			exit_message(prog, "Add map error: ", NULL, line);
		free(line);
	}
	return (EXIT_SUCCESS);
}

int	map_add(t_data *prog, char *line)
{
	char	**map;

	if (!prog->map)
	{
		prog->map = (char **)ft_calloc(2, sizeof(char *));
		if (!prog->map)
			return (EXIT_FAILURE);
		prog->map[0] = remove_nextline(line);
	}
	else
	{
		map = ft_realloc2d(prog->map, ft_str2dlen(prog->map) + 1);
		if (!map)
			return (EXIT_FAILURE);
		prog->map = map;
		prog->map[ft_str2dlen(prog->map)] = remove_nextline(line);
	}
	return (EXIT_SUCCESS);
}

int	close_check(t_data *prog, size_t i, size_t j)
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

void	vector_init(t_data *prog, size_t x, size_t y)
{
	prog->p.posX = x + 0.5;
	prog->p.posY = y + 0.5;
	if (prog->map[y][x] == 'N')
	{
		prog->p.dirX = 0;
		prog->p.dirY = -1;
		prog->p.planeX = 0.66;
		prog->p.planeY = 0;
	}
	else if (prog->map[y][x] == 'S')
	{
		prog->p.dirX = 0;
		prog->p.dirY = 1;
		prog->p.planeX = -0.66;
		prog->p.planeY = 0;
	}
}

void	vector_init_util(t_data *prog, size_t x, size_t y)
{
	if (prog->map[y][x] == 'E')
	{
		prog->p.dirX = 1;
		prog->p.dirY = 0;
		prog->p.planeX = 0;
		prog->p.planeY = 0.66;
	}
	else if (prog->map[y][x] == 'W')
	{
		prog->p.dirX = -1;
		prog->p.dirY = 0;
		prog->p.planeX = 0;
		prog->p.planeY = -0.66;
	}
}

int	map_check_util(t_data *prog)
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
				return (EXIT_FAILURE);
			if (prog->map[i][j] == 'N' || prog->map[i][j] == 'S' || \
				prog->map[i][j] == 'E' || prog->map[i][j] == 'W')
			{
				vector_init(prog, i, j);
				player_count++;
			}
			j++;
		}
		i++;
	}
	return (player_count);
}

static int	ft_iseof(t_data *prog, int i)
{
	i++;
	while (prog->map[i])
	{
		if (ft_strlen(prog->map[i]) > 1)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	map_check(t_data *prog)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_str2dlen(prog->map) < 3 || map_check_util(prog) != 1)
		return (EXIT_FAILURE);
	while (prog->map[i])
	{
		j = 0;
		if (ft_strlen(prog->map[i]) < 3 || prog->map[i][j] == '\n')
		{
			if (ft_iseof(prog, i))
				return (EXIT_FAILURE);
		}
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
