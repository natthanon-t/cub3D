/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 09:59:09 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/04 09:59:51 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_right(t_data *prog)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = prog->p.dirX;
	prog->p.dirX = prog->p.dirX * cos(prog->p.rotSpeed) - \
		prog->p.dirY * sin(prog->p.rotSpeed);
	prog->p.dirY = old_dir_x * sin(prog->p.rotSpeed) + \
		prog->p.dirY * cos(prog->p.rotSpeed);
	old_plane_x = prog->p.planeX;
	prog->p.planeX = prog->p.planeX * cos(prog->p.rotSpeed) - \
		prog->p.planeY * sin(prog->p.rotSpeed);
	prog->p.planeY = old_plane_x * sin(prog->p.rotSpeed) + \
		prog->p.planeY * cos(prog->p.rotSpeed);
}

void	rotate_left(t_data *prog)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = prog->p.dirX;
	prog->p.dirX = prog->p.dirX * cos(-prog->p.rotSpeed) - \
		prog->p.dirY * sin(-prog->p.rotSpeed);
	prog->p.dirY = old_dir_x * sin(-prog->p.rotSpeed) + \
		prog->p.dirY * cos(-prog->p.rotSpeed);
	old_plane_x = prog->p.planeX;
	prog->p.planeX = prog->p.planeX * cos(-prog->p.rotSpeed) - \
		prog->p.planeY * sin(-prog->p.rotSpeed);
	prog->p.planeY = old_plane_x * sin(-prog->p.rotSpeed) + \
		prog->p.planeY * cos(-prog->p.rotSpeed);
}

void	key_press(int key_code, t_data *prog)
{
	//key event
}

void	key_release(int key_code, t_data *prog)
{
	//key event
}
