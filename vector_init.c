/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:56:45 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/05 18:56:58 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	vector_init(t_data *prog, size_t x, size_t y)
{
	prog->p.posX = x + 0.5;
	prog->p.posY = y + 0.5;
	if (prog->map[y][x] == 'N')
	{
		prog->p.dirX = 0;
		prog->p.dirY = -1;
		prog->p.planeX = 0.66;
		prog->p.planeY = 0;
	}
	else if (prog->map[y][x] == 'S')
	{
		prog->p.dirX = 0;
		prog->p.dirY = 1;
		prog->p.planeX = -0.66;
		prog->p.planeY = 0;
	}
	vector_init_util(prog, x, y);
}

void	vector_init_util(t_data *prog, size_t x, size_t y)
{
	if (prog->map[y][x] == 'E')
	{
		prog->p.dirX = 1;
		prog->p.dirY = 0;
		prog->p.planeX = 0;
		prog->p.planeY = 0.66;
	}
	else if (prog->map[y][x] == 'W')
	{
		prog->p.dirX = -1;
		prog->p.dirY = 0;
		prog->p.planeX = 0;
		prog->p.planeY = -0.66;
	}
}
