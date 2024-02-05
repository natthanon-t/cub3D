/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:44:04 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/05 18:16:06 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	calculate_ray(t_data *prog, int x)
{
	prog->p.cameraX = (2 * x) / (double)WIN_WIDTH - 1;
	prog->p.rayDirX = prog->p.dirX + prog->p.planeX * prog->p.cameraX;
	prog->p.rayDirY = prog->p.dirY + prog->p.planeY * prog->p.cameraX;
	prog->p.mapX = (int)prog->p.posX;
	prog->p.mapY = (int)prog->p.posY;
	if (prog->p.rayDirX == 0)
		prog->p.deltaDistX = 1e30;
	else
		prog->p.deltaDistX = fabs(1 / prog->p.rayDirX);
	if (prog->p.rayDirY == 0)
		prog->p.deltaDistY = 1e30;
	else
		prog->p.deltaDistY = fabs(1 / prog->p.rayDirY);
	prog->p.hit = 0;
}

static void	calculate_step_init_sidedist(t_data *prog)
{
	if (prog->p.rayDirX < 0)
	{
		prog->p.stepX = -1;
		prog->p.sideDistX = (prog->p.posX - prog->p.mapX) * prog->p.deltaDistX;
	}
	else
	{
		prog->p.stepX = 1;
		prog->p.sideDistX = (prog->p.mapX + 1.0 - prog->p.posX) * \
			prog->p.deltaDistX;
	}
	if (prog->p.rayDirY < 0)
	{
		prog->p.stepY = -1;
		prog->p.sideDistY = (prog->p.posY - prog->p.mapY) * prog->p.deltaDistY;
	}
	else
	{
		prog->p.stepY = 1;
		prog->p.sideDistY = (prog->p.mapY + 1.0 - prog->p.posY) * \
			prog->p.deltaDistY;
	}
}

static void	set_wall_nbr(t_data *prog)
{
	if (prog->p.side == 0)
	{
		if (prog->p.mapX > prog->p.posX)
			prog->p.texture_nbr = 1;
		else
			prog->p.texture_nbr = 3;
	}
	else
	{
		if (prog->p.mapY > prog->p.posY)
			prog->p.texture_nbr = 2;
		else
			prog->p.texture_nbr = 0;
	}
}

static void	ft_dda(t_data *prog)
{
	while (prog->p.hit == 0)
	{
		if (prog->p.sideDistX < prog->p.sideDistY)
		{
			prog->p.sideDistX += prog->p.deltaDistX;
			prog->p.mapX += prog->p.stepX;
			prog->p.side = 0;
		}
		else
		{
			prog->p.sideDistY += prog->p.deltaDistY;
			prog->p.mapY += prog->p.stepY;
			prog->p.side = 1;
		}
		if (prog->map[prog->p.mapY][prog->p.mapX] == '1')
		{
			prog->p.hit = 1;
			set_wall_nbr(prog);
		}
	}
}

void	raycast(t_data *prog)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		calculate_ray(prog, x);
		calculate_step_init_sidedist(prog);
		ft_dda(prog);
		raycast_util(prog, x);
		x++;
	}
}
