/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:15 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/05 08:57:33 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	wall_add(t_data *prog, size_t i)
{
	int	x;
	int	y;

	y = 0;
	while (y < prog->img_src[i].height)
	{
		x = 0;
		while (x < prog->img_src[i].width)
		{
			prog->wall_arr[i][prog->img_src[i].height * y + x] = \
				prog->img_src[i].img_addr[prog->img_src[i].height * y + x];
			x++;
		}
		y++;
	}
}

int	wall_set(t_data *prog)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		prog->img_src[i].img_ptr = mlx_xpm_file_to_image(prog->mlx.mlx, \
				prog->xpm[i], &prog->img_src[i].width, \
				&prog->img_src[i].height);
		if (!prog->img_src[i].img_ptr)
			return (EXIT_FAILURE);
		prog->img_src[i].img_addr = mlx_get_data_addr(prog->img_src[i].img_ptr, \
			&prog->img_src[i].bits_per_pixel, &prog->img_src[i].size_line, \
			&prog->img_src[i].endian);
		if (!prog->img_src[i].img_addr)
			return (EXIT_FAILURE);
		wall_add(prog, i);
		mlx_destroy_image(prog->mlx.mlx, prog->img_src[i].img_ptr);
		i++;
	}
	return (EXIT_SUCCESS);
}
