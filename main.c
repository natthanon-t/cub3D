/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:54:49 by ntairatt          #+#    #+#             */
/*   Updated: 2024/01/27 15:54:50 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data	prog;

	if (ac != 2 || ft_iscub(av[1]))
		exit_message(&prog, "Input Argument Error: ", av[1]);
	//if (init_data(&prog, av[1]))
	//	exit_message(&prog, "init_data failed ", av[1]);
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
	prog->map = NULL;
	//prog->ceiling_color = ;
	//prog->floor_color = ;
	read_file(prog);
	return (0);
}
