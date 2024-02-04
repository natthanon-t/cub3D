/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:54:49 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/04 10:42:48 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	if (wall_set(&prog) == EXIT_FAILURE)
		exit_message(&prog, "Wall set ", "failed", NULL);
	//init_mlx(&prog);
}

static void	key_set_released(t_data *prog)
{
	prog->key.w = KEY_RELEASED;
	prog->key.a = KEY_RELEASED;
	prog->key.s = KEY_RELEASED;
	prog->key.d = KEY_RELEASED;
	prog->key.arrow_left = KEY_RELEASED;
	prog->key.arrow_right = KEY_RELEASED;
}

int	init_data(t_data *prog, char *filename)
{
	prog->fd = open(filename, O_RDONLY);
	if (prog->fd < 0)
		return (EXIT_FAILURE);
	ft_bzero(prog->rgb, 3);
	ft_bzero(prog->xpm, 5);
	key_set_released(prog);
	prog->p.frameTime = 16 / 1000.0;
	prog->p.moveSpeed = prog->p.frameTime * 5;
	prog->p.rotSpeed = prog->p.frameTime * SENS;
	prog->mlx.window = NULL;
	prog->map = NULL;
	file_read(prog);
	return (EXIT_SUCCESS);
}
