#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data	prog;

	if (ac != 2 || ft_iscub(av[1]))
		exit_error(&prog, "Input Argument Error ", av[1]);
	//if (init_data(&prog, av[1]))
	//	exit_error(&prog, "init_data failed ", av[1]);
	//init_mlx(&prog);
}

int	init_data(t_data *prog, char *filename)
{
	size_t	len;

	prog->fd = open(filename, O_RDONLY);
	if (prog->fd < 0)
		return (1);
	ft_bzero(prog->rgb, 3);
	ft_bzero(prog->xpm, 5);
	prog->key.w = KEY_RELEASED;
	prog->key.a = KEY_RELEASED;
	prog->key.s = KEY_RELEASED;
	prog->key.d = KEY_RELEASED;
	prog->key.arrow_left = KEY_RELEASED;
	prog->key.arrow_right = KEY_RELEASED;
	prog->mlx.window = NULL;
	//prog->ceiling_color = ;
	//prog->floor_color = ;
	read_file(prog);
	return (0);
}

int	ft_iscub(char *file_name)
{
	char	*type;
	int		i;
	int		check;

	type = ".cub";
	check = 1;
	i = ft_strlen(file_name) - 4;
	if (i <= 0)
		return (check);
	else if (!ft_strncmp(&file_name[i], type, 4) && file_name[i])
		check = 0;
	return (check);
}

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
			exit_error(prog, "Init Background ", line);
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
