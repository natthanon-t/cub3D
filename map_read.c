/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:08 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/06 14:24:55 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	start_init(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr("01NSEW", str[i]))
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

int	map_read(t_data *prog)
{
	char	*line;

	while (1)
	{
		line = get_next_line(prog->fd);
		if (!line)
			break ;
		if (start_init(line) == EXIT_SUCCESS)
		{
			while (1)
			{
				if (map_add(prog, line) == EXIT_FAILURE)
					exit_message(prog, "Add map error: ", NULL, line);
				free(line);
				line = get_next_line(prog->fd);
				if (!line)
					break ;
			}
		}
		else
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
		prog->map[0] = ft_strtrim(line, "\n");
	}
	else
	{
		map = ft_realloc2d(prog->map, ft_str2dlen(prog->map) + 1);
		if (!map)
			return (EXIT_FAILURE);
		prog->map = map;
		prog->map[ft_str2dlen(prog->map)] = ft_strtrim(line, "\n");
	}
	return (EXIT_SUCCESS);
}
