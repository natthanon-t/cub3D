/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:08 by ntairatt          #+#    #+#             */
/*   Updated: 2024/01/27 15:55:09 by ntairatt         ###   ########.fr       */
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
		if (map_add(prog, line))
		{
			exit_message(prog, "Add map error: ", line);
			free(line);
		}
		free(line);
	}
	return (0);
}

int	map_add(t_data *prog, char *line)
{
	char	**map;

	if (!prog->map)
	{
		prog->map = (char *)malloc(sizeof(char *) * 2);
		if (!prog->map)
			return (1);
		prog->map[0] = ft_strdup(line);
		prog->map[1] = NULL;
	}
	else
	{
		map = ft_realloc2d(prog->map, ft_str2dlen(prog->map) + 1);
		if (!map)
			return (1);
		prog->map = map;
		prog->map[ft_str2dlen(prog->map)] = ft_strdup(line);
	}
	return (0);
}

int	close_check(t_data *prog, size_t i, size_t j)
{
	if (prog->map[i][j] == '0' || (prog->map[i][j] != '1' && \
		prog->map[i][j] != ' '))
	{
		if (!i || !prog->map[i + 1] || !j || !prog->map[i][j + 1])
			return (1);
		else if (prog->map[i - 1] && prog->map[i - 1][j] && \
			prog->map[i - 1][j] == ' ')
			return (1);
		else if (prog->map[i + 1] && prog->map[i + 1][j] && \
			prog->map[i + 1][j] == ' ')
			return (1);
		else if (prog->map[i] && prog->map[i][j - 1] && \
			prog->map[i][j - 1] == ' ')
			return (1);
		else if (prog->map[i] && prog->map[i][j + 1] && \
			prog->map[i][j + 1] == ' ')
			return (1);
	}
	return (0);
}

int	map_check_util(t_data *prog)
{
	size_t	i;
	size_t	j;
	int		count;

	i = 0;
	count = 0;
	while (prog->map[i])
	{
		j = 0;
		while (prog->map[i][j])
		{
			if (!ft_strchr("01NSEW ", prog->map[i][j]))
				return (1);
			// if (equal N S E W)
			// vector init
			// count ++
			j++;
		}
		i++;
	}
}

int	map_check(t_data *prog)
{
	size_t	i;
	size_t	j;

	i = 0;
	// char_check ----------------|
	//                            |
	//                            V
	if (ft_str2dlen(prog->map) < 3)
		return (1);
	while (prog->map[i])
	{
		j = 0;
		if (!ft_strlen(prog->map[i]))
		{
			// is_end;
		}
		while (prog->map[i][j])
		{
			//if (floodfill)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
