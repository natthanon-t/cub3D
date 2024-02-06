/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:03 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/06 11:04:02 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	file_read(t_data *prog)
{
	char	*line;

	while (ft_str2dlen(prog->xpm) != 4 || ft_str2dlen(prog->rgb) != 2)
	{
		line = get_next_line(prog->fd);
		if (!line)
			return ;
		if (bg_init(prog, line) == EXIT_FAILURE)
			exit_message(prog, "Init Background: ", NULL, line);
		free(line);
	}
}

int	bg_init(t_data *prog, char *line)
{
	char	**str2d;
	char	*tmp_line;

	str2d = NULL;
	if (line[0] == '\n')
		return (EXIT_SUCCESS);
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		rgb_init(prog, line);
	else
	{
		tmp_line = remove_nextline(line);
		str2d = ft_split(tmp_line, ' ');
		if (str2d && ft_str2dlen(str2d) == 2)
			wall_init(prog, str2d);
		else
			return (EXIT_FAILURE);
		free(tmp_line);
	}
	return (EXIT_SUCCESS);
}

void	rgb_init(t_data *prog, char *line)
{
	char	*tmp_line;

	tmp_line = line;
	if (!ft_strncmp(tmp_line, "F ", 2))
	{
		tmp_line += 2;
		prog->rgb[0] = remove_nextline(tmp_line);
	}
	else if (!ft_strncmp(tmp_line, "C ", 2))
	{
		tmp_line += 2;
		prog->rgb[1] = remove_nextline(tmp_line);
		prog->xpm[4] = 0;
		prog->rgb[2] = 0;
	}
}

void	wall_init(t_data *prog, char **str)
{
	if (!ft_strncmp(str[0], "NO", 3))
		prog->xpm[0] = ft_strdup(str[1]);
	else if (!ft_strncmp(str[0], "SO", 3))
		prog->xpm[1] = ft_strdup(str[1]);
	else if (!ft_strncmp(str[0], "WE", 3))
		prog->xpm[2] = ft_strdup(str[1]);
	else if (!ft_strncmp(str[0], "EA", 3))
		prog->xpm[3] = ft_strdup(str[1]);
	if (str)
		ft_free_str2d(str);
}
