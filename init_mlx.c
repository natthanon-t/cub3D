/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:54:45 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/04 22:48:45 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_mlx(t_data *prog)
{
	prog->mlx.mlx = mlx_init();
	prog->mlx.window = mlx_new_window(prog->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	prog->img.img_ptr = mlx_new_image(prog->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	prog->img.img_addr = mlx_get_data_addr(prog->img.img_ptr,
			&prog->img.bits_per_pixel, &prog->img.size_line, &prog->img.endian);
	raycast(prog);
	mlx_put_image_to_window(prog->mlx.mlx, prog->mlx.window, prog->img.img_ptr,
		0, 0);
	//mlx_key_hook(prog->mlx.window, key_esc, prog);
	//mlx_hook(prog->mlx.window, ON_KEYDOWN, 0, &key_press, prog);
	//mlx_hook(prog->mlx.window, ON_KEYUP, 0, &key_release, prog);
	//mlx_hook(prog->mlx.window, ON_DESTROY, 0, win_cross, prog);
	mlx_loop(prog->mlx.mlx);
}

void	paint_pixel(t_data *prog, size_t x, size_t y, int color)
{
	char *addr;

	addr = (char *)prog->img.img_addr + \
		(y * prog->img.size_line + x * (prog->img.bits_per_pixel / 8));
	*(unsigned int *)addr = color;
}

void	paint_background(t_data *prog)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT / 2)
			paint_pixel(prog, x, y, prog->ceiling_color);
		x++;
	}
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = (WIN_WIDTH / 2) - 1;
		while (y < WIN_HEIGHT)
			paint_pixel(prog, x, y, prog->floor_color);
		x++;
	}
}

/*int	key_esc(int keycode, t_data *prog)
{
	if (keycode == 53)
	{
		//something freeing here
		//free_map(prog->map);
		//mlx_destroy_image(prog->mlx.mlx, prog->img.img_ptr);
		//mlx_destroy_window(prog->mlx.mlx, prog->mlx.window);
		//exit(0);
	}
	return (EXIT_FAILURE);
}

int	win_cross(t_data *prog)
{
	//something freeing here
	//free_map(prog->map);
	//mlx_destroy_image(prog->mlx.mlx, prog->img.img_ptr);
	//mlx_destroy_window(prog->mlx.mlx, prog->mlx.window);
	//exit(0);
}*/
