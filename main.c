/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:54:49 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/05 19:40:43 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	count_map(char **map, int mode)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (mode == 0)
	{
		j = 0;
		while (map[j])
		{
			k = 0;
			while (map[j][k])
				k++;
			if (k > i)
				i = k;
			j++;
		}
	}
	else if (mode == 1)
	{
		while (map[i])
			i++;
	}
	return (i);
}

void	get_map_data(t_data *data, char **map)
{
	int		j;
	int		k;
	char	**tmp_map;

	j = 0;
	tmp_map = data->map;
	data->map = (char **)malloc(sizeof(char *) * (count_map(map, 1) + 1));
	data->map[count_map(map, 1)] = NULL;
	while (map[j])
	{
		k = 0;
		data->map[j] = (char *)ft_calloc(count_map(map, 0) + 1, sizeof(char));
		while (map[j][k])
		{
			if (map[j][k] != ' ')
				data->map[j][k] = map[j][k];
			k++;
		}
		while (k < count_map(map, 0))
			data->map[j][k++] = ' ';
		j++;
	}
	ft_free_str2d(tmp_map);
}

int	main(int ac, char **av)
{
	t_data	prog;

	if (ac != 2 || ft_iscub(av[1]))
		exit_message(&prog, "Input Argument Error: ", av[1], NULL);
	if (init_data(&prog, av[1]) == EXIT_FAILURE)
		exit_message(&prog, "Init_data failed ", av[1], NULL);
	if (rgb_interpret(&prog) == EXIT_FAILURE)
		exit_message(&prog, "RGB_interpret ", "failed", NULL);
	if (map_read(&prog) == EXIT_FAILURE)
		exit_message(&prog, "Map_read ", "failed", NULL);
	get_map_data(&prog, prog.map);
	if (map_check(&prog) == EXIT_FAILURE)
		exit_message(&prog, "Map_check ", "failed", NULL);
	prog.mlx.mlx = mlx_init();
	prog.mlx.window = mlx_new_window(prog.mlx.mlx, \
		WIN_WIDTH + 300, WIN_HEIGHT, "cub3D");
	if (wall_set(&prog) == EXIT_FAILURE)
		exit_message(&prog, "Wall set ", "failed", NULL);
	mlx_loop_hook(prog.mlx.mlx, &init_mlx, &prog);
	mlx_hook(prog.mlx.window, X_EVENT_KEY_PRESS, 0, &key_press, &prog);
	mlx_hook(prog.mlx.window, X_EVENT_KEY_RELEASE, 0, &key_release, &prog);
	mlx_hook(prog.mlx.window, 17, 0, &exit_ex, &prog);
	mlx_loop(prog.mlx.mlx);
}

char	*remove_nextline(char *line)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!line)
		return (NULL);
	if (line[ft_strlen(line) - 1] == '\n' && ft_strlen(line) > 1)
		;
	else
		return (ft_strdup(line));
	new = (char *)malloc(sizeof(char) * ft_strlen(line));
	if (!new)
		return (NULL);
	while (line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	init_data(t_data *prog, char *filename)
{
	prog->fd = open(filename, O_RDONLY);
	if (prog->fd < 0)
		return (EXIT_FAILURE);
	ft_bzero(prog->rgb, 3);
	ft_bzero(prog->xpm, 5);
	prog->key.w = KEY_RELEASED;
	prog->key.a = KEY_RELEASED;
	prog->key.s = KEY_RELEASED;
	prog->key.d = KEY_RELEASED;
	prog->key.arrow_left = KEY_RELEASED;
	prog->key.arrow_right = KEY_RELEASED;
	prog->p.frameTime = 16 / 1000.0;
	prog->p.moveSpeed = prog->p.frameTime * 5;
	prog->p.rotSpeed = prog->p.frameTime * SENS;
	prog->mlx.window = NULL;
	prog->map = NULL;
	file_read(prog);
	return (EXIT_SUCCESS);
}
