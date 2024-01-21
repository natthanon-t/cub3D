#include "cub3D.h"

int	read_map(t_data *prog)
{
	char *line;

	while (1)
	{
		line = get_next_line(prog->fd);
		if (!line)
			break ;
		if (add_map(prog, line))
		{
			exit_message(prog, "Add map error: ", line);
			free(line);
		}
		free(line);
	}
	return (0);
}

int	add_map(t_data *prog, char *line)
{
	char	**map;

	if (!prog->map)
	{
		prog->map = (char *)malloc(sizeof(char *) * 2)
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