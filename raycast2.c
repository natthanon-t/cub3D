/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:43:58 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/05 00:11:34 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	calculate_perpendicular_ray(t_data *prog)
{
	if (prog->p.side == 0)
		prog->p.perpWallDist = prog->p.sideDistX - prog->p.deltaDistX;
	else
		prog->p.perpWallDist = prog->p.sideDistY - prog->p.deltaDistY;
}

static void	calculate_highest_lowest_pixel(t_data *prog)
{
	prog->p.drawStart = -prog->p.lineHeight / 2 + WIN_HEIGHT / 2;
	if (prog->p.drawStart < 0)
		prog->p.drawStart = 0;
	prog->p.drawEnd = prog->p.lineHeight / 2 + WIN_HEIGHT / 2;
	if (prog->p.drawEnd >= WIN_HEIGHT)
		prog->p.drawEnd = WIN_HEIGHT - 1;
}

static void	calculate_wall_hit(t_data *prog)
{
	if (prog->p.side == 0)
		prog->p.wallX = prog->p.posY + prog->p.perpWallDist * prog->p.rayDirX;
	else
		prog->p.wallX = prog->p.posX + prog->p.perpWallDist * prog->p.rayDirX;
	prog->p.wallX -= floor(prog->p.wallX);
	prog->p.texX = (int)(prog->p.wallX * (double)TEXTURE_WIDTH);
	if (prog->p.side == 0 && prog->p.rayDirX > 0)
		prog->p.texX = TEXTURE_WIDTH - prog->p.texX - 1;
	if (prog->p.side == 1 && prog->p.rayDirY < 0)
		prog->p.texX = TEXTURE_WIDTH - prog->p.texX - 1;
}

static void	draw_vertical_stripe(t_data *prog, int x)
{
	double	step;
	double	tex_pos;
	double	y;

	step = 1.0 * TEXTURE_HEIGHT / prog->p.lineHeight;
	tex_pos = (prog->p.drawStart - WIN_HEIGHT / 2 + prog->p.lineHeight / 2) * \
		step;
	y = prog->p.drawStart;
	while (y < prog->p.drawEnd)
	{
		prog->p.texY = (int)tex_pos & (TEXTURE_HEIGHT - 1);
		tex_pos += step;
		prog->p.color = prog->wall_arr[prog->p.texture_nbr][TEXTURE_HEIGHT * \
			prog->p.texY + prog->p.texX];
		if (prog->p.side == 1)
			prog->p.color = (prog->p.color >> 1) & 8355711;
		paint_pixel(prog, (size_t)x, (size_t)y, prog->p.color);
		y++;
	}
}

void	raycast_util(t_data *prog, int x)
{
	calculate_perpendicular_ray(prog);
	prog->p.lineHeight = (int)(WIN_HEIGHT / prog->p.perpWallDist);
	calculate_highest_lowest_pixel(prog);
	calculate_wall_hit(prog);
	draw_vertical_stripe(prog, x);
}
