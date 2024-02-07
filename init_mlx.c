/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:54:45 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/06 16:48:41 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_mlx(t_data *prog)
{
	prog->img.img_ptr = mlx_new_image(prog->mlx.mlx, WIN_WIDTH + 300, \
		WIN_HEIGHT);
	prog->img.img_addr = (int *)mlx_get_data_addr(prog->img.img_ptr,
			&prog->img.bits_per_pixel, &prog->img.size_line, &prog->img.endian);
	paint_background(prog);
	raycast(prog);
	move(prog);
	create_minimap(prog);
	mlx_put_image_to_window(prog->mlx.mlx, prog->mlx.window, prog->img.img_ptr,
		0, 0);
	mlx_destroy_image(prog->mlx.mlx, prog->img.img_ptr);
	return (0);
}

void	paint_pixel(t_data *prog, int x, int y, int color)
{
	char	*addr;

	addr = (char *)prog->img.img_addr + \
		(y * prog->img.size_line + x * (prog->img.bits_per_pixel / 8));
	*(unsigned int *)addr = color;
}

void	paint_background(t_data *prog)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT / 2)
			paint_pixel(prog, x, y++, prog->ceiling_color);
		x++;
	}
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = (WIN_HEIGHT / 2) - 1;
		while (y < WIN_HEIGHT)
			paint_pixel(prog, x, y++, prog->floor_color);
		x++;
	}
}
