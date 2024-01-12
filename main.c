#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data	prog;

	if (ac != 2 || ft_iscub(av[1]))
		return (1);
	prog.key.w = KEY_RELEASED;
	prog.key.a = KEY_RELEASED;
	prog.key.s = KEY_RELEASED;
	prog.key.d = KEY_RELEASED;
	prog.key.arrow_left = KEY_RELEASED;
	prog.key.arrow_right = KEY_RELEASED;
	//prog.ceiling_color = ;
	//prog.floor_color = ;
	init_data(&prog, av[1]);
	init_mlx(&prog);
}

int	init_data(t_data *prog, char *filename)
{
	size_t	len;

	prog->fd = open(filename, O_RDONLY);
	if (prog->fd < 0)
		return (-1);

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
