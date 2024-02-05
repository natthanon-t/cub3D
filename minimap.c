/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:47:05 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/05 19:30:26 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_minimap(t_data *data, t_data2 *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= 20)
	{
		j = -1;
		while (++j <= 20)
		{
			if (m->res_y + j < 300 && m->res_x + i < WIN_WIDTH \
				+ 300 && data->map[m->starty][m->startx] == '1'\
				&& (i == 20 || j == 20 || i == 0 || j == 0))
				paint_pixel(data, m->res_x + i, m->res_y + j, 0x33001a);
			else if (m->res_y + j < 300 && m->res_x + i < WIN_WIDTH + 300 && \
				data->map[m->starty][m->startx] \
				&& (i == 20 || j == 20 || i == 0 || j == 0))
				paint_pixel(data, m->res_x + i, m->res_y + j, 0x1a000d);
			else if (m->res_y + j < 300 && m->res_x + i < WIN_WIDTH + 300 && \
				data->map[m->starty][m->startx] == '1')
				paint_pixel(data, m->res_x + i, m->res_y + j, 0x00000033);
			else if (m->res_y + j < 300 && m->res_x + i < WIN_WIDTH + 300 && \
				data->map[m->starty][m->startx])
				paint_pixel(data, m->res_x + i, m->res_y + j, 0x00999999);
		}
	}
}

void	draw_player(t_data *data, int starty, int startx)
{
	int		x;
	int		y;
	int		startxx;
	int		startyy;
	char	*addr;

	startxx = WIN_WIDTH + (data->p.posX - startx) * 20 - 5;
	startyy = (data->p.posY - starty) * 20 - 5;
	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			addr = (char *)data->img.img_addr + ((startyy + y) * \
				data->img.size_line \
				+ (startxx + x) * (data->img.bits_per_pixel / 8));
			if (*(unsigned int *)addr != 0x00000033 && \
				*(unsigned int *)addr != 0x33001a)
				paint_pixel(data, startxx + x, startyy + y, 0x009933);
			y += 1;
		}
		x += 1;
	}
}

void	draw_ray_scan2(t_data *data, double j, double posx, double posy)
{
	int			i;
	double		old_dir_x;
	double		dirx;
	double		diry;
	char		*addr;

	i = -1;
	old_dir_x = data->p.dirX;
	dirx = data->p.dirX * cos(j * M_PI / 180) \
		- data->p.dirY * sin(j * M_PI / 180);
	diry = old_dir_x * sin(j * M_PI / 180) \
		+ data->p.dirY * cos(j * M_PI / 180);
	while (++i < 300)
	{
		addr = (char *)data->img.img_addr + (int)posy * data->img.size_line \
			+ (int)posx * (data->img.bits_per_pixel / 8);
		if (*(unsigned int *)addr == 0x00999999 || \
			*(unsigned int *)addr == 0x1a000d || \
			*(unsigned int *)addr == 0x009933)
		{
			paint_pixel(data, (int)posx, (int)posy, 0x009933);
			posx += dirx;
			posy += diry;
		}
	}
}

void	draw_ray_scan(t_data *data)
{
	double		j;
	double		posx;
	double		posy;

	j = -33;
	while (j <= 33)
	{
		posx = (WIN_WIDTH + (data->p.posX - \
			startx_minimap(data, count_map(data->map, 0))) * 20);
		posy = (data->p.posY - \
			starty_minimap(data, count_map(data->map, 1))) * 20;
		draw_ray_scan2(data, j, posx, posy);
		j += 3;
	}
}

void	create_minimap(t_data *data)
{
	t_data2	minimap;

	minimap.res_x = WIN_WIDTH;
	minimap.res_y = 0;
	minimap.starty = starty_minimap(data, count_map(data->map, 1));
	minimap.startx = startx_minimap(data, count_map(data->map, 0));
	while (data->map[minimap.starty])
	{
		minimap.startx = startx_minimap(data, count_map(data->map, 0));
		while (data->map[minimap.starty][minimap.startx])
		{
			draw_minimap(data, &minimap);
			minimap.startx++;
			minimap.res_x += 20;
		}
		minimap.res_x = WIN_WIDTH;
		minimap.res_y += 20;
		minimap.starty++;
	}
	draw_player(data, starty_minimap(data, count_map(data->map, 1)), \
		startx_minimap(data, count_map(data->map, 0)));
	draw_ray_scan(data);
}
