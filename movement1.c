/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 09:59:09 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/05 18:55:14 by ntairatt         ###   ########.fr       */
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

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit_ex(data);
	else if (keycode == KEY_W)
		data->key.w = KEY_PRESSED;
	else if (keycode == KEY_S)
		data->key.s = KEY_PRESSED;
	else if (keycode == KEY_A)
		data->key.a = KEY_PRESSED;
	else if (keycode == KEY_D)
		data->key.d = KEY_PRESSED;
	else if (keycode == KEY_LEFT)
		data->key.arrow_left = KEY_PRESSED;
	else if (keycode == KEY_RIGHT)
		data->key.arrow_right = KEY_PRESSED;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key.w = KEY_RELEASED;
	else if (keycode == KEY_S)
		data->key.s = KEY_RELEASED;
	else if (keycode == KEY_A)
		data->key.a = KEY_RELEASED;
	else if (keycode == KEY_D)
		data->key.d = KEY_RELEASED;
	else if (keycode == KEY_LEFT)
		data->key.arrow_left = KEY_RELEASED;
	else if (keycode == KEY_RIGHT)
		data->key.arrow_right = KEY_RELEASED;
	return (0);
}
