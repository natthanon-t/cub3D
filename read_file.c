#include "cub3D.h"

void	read_file(t_data *prog)
{
	char	*line;

	while (ft_str2dlen(prog->xpm) != 4 || ft_str2dlen(prog->rgb) != 2)
	{
		line = get_next_line(prog->fd);
		if (!line)
			return ;
		if (init_bg(prog, line))
		{
			free(line);
			exit_message(prog, "Init Background: ", line);
		}
		free(line);
	}
}

int	init_bg(t_data *prog, char *line)
{
	char **str2d;

	str2d = NULL;
	if (line && ft_strlen(line) > 2 && (!ft_strncmp(line, "F ", 2) || \
				!ft_strncmp(line, "C ", 2)))
		init_rgb(prog, line);
	else
	{
		str2d = ft_split(line, ' ');
		if (str2d && ft_str2dlen(str2d) == 2)
			init_wall(prog, str2d);
		else
			return (1);
	}
	if (str2d)
		ft_free_str2d(str2d);
	return (0);
}

void	init_rgb(t_data *prog, char *line)
{
	char *tmp_line;

	tmp_line = line;
	if (!ft_strncmp(tmp_line, "F ", 2))
	{
		tmp_line += 2;
		prog->rgb[0] = ft_strdup(tmp_line);
	}
	else if (!ft_strncmp(tmp_line, "C ", 2))
	{
		tmp_line += 2;
		prog->rgb[1] = ft_strdup(tmp_line);
	}
}

void	init_wall(t_data *prog, char **str)
{
	if (!ft_strncmp(str[0], "NO", 2))
		prog->xpm[0] = ft_strdup(str[1]);
	else if (!ft_strncmp(str[0], "SO", 2))
		prog->xpm[1] = ft_strdup(str[1]);
	else if (!ft_strncmp(str[0], "WE", 2))
		prog->xpm[2] = ft_strdup(str[1]);
	else if (!ft_strncmp(str[0], "EA", 2))
		prog->xpm[3] = ft_strdup(str[1]);
}
