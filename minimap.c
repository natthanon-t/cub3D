/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:47:05 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/05 18:02:45 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	starty_minimap(t_data *data, int max_y)
{
	int	starty;

	starty = 0;
	if (max_y <= 15 || (int)data->p.posY < 7)
		starty = 0;
	else if ((int)data->p.posY + 7 >= max_y)
		starty =  max_y - 15;
	else
		starty = (int)data->p.posY - 7;
	return (starty);
}

int	startx_minimap(t_data *data, int max_x)
{
	int	startx;

	startx = 0;
	if (max_x <= 15 || (int)data->p.posX < 7)
			startx = 0;
	else if ((int)data->p.posX + 7 >= max_x)
		startx = max_x - 15;
	else
		startx = (int)data->p.posX - 7;
	return (startx);
}

void	draw_minimap(t_data *data, int startx, int starty, \
	int res_x, int res_y)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 20)
	{
		j = 0;
		while (j <= 20)
		{
			if (res_y + j < 300 && res_x + i < WIN_WIDTH + 300 && data->map[starty][startx] == '1'\
				&& (i == 20 || j == 20 || i == 0 || j == 0))
				paint_pixel(data, res_x + i, res_y + j, 0x33001a);
			else if (res_y + j < 300 && res_x + i < WIN_WIDTH + 300 && data->map[starty][startx]\
				&& (i == 20 || j == 20 || i == 0 || j == 0))
				paint_pixel(data, res_x + i, res_y + j, 0x1a000d);
			else if (res_y + j < 300 && res_x + i < WIN_WIDTH + 300 && data->map[starty][startx] == '1')
				paint_pixel(data, res_x + i, res_y + j, 0x00000033);
			else if (res_y + j < 300 && res_x + i < WIN_WIDTH + 300 && data->map[starty][startx])
				paint_pixel(data, res_x + i, res_y + j, 0x00999999);
			j++;
		}
		i++;
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
			if (*(unsigned int *)addr != 0x00000033 && *(unsigned int *)addr != 0x33001a)
				paint_pixel(data, startxx + x, startyy + y, 0x009933);
			y += 1;
		}
		x += 1;
	}
}

void	draw_ray_scan(t_data *data)
{
	double		i;
	double		j;
	double	posx;
	double	posy;
	double	old_dir_x;
	double	dirx;
	double	diry;
	char	*addr;

	j = -33;
	while(j <= 33)
	{
		i = 0;
		posx = (WIN_WIDTH + (data->p.posX - startx_minimap(data, count_map(data->map, 0))) * 20);
		posy = (data->p.posY - starty_minimap(data, count_map(data->map, 1))) * 20;
		old_dir_x = data->p.dirX;
		dirx = data->p.dirX * cos(j * M_PI / 180) \
			- data->p.dirY * sin(j * M_PI / 180);
		diry = old_dir_x * sin(j * M_PI / 180) \
			+ data->p.dirY * cos(j * M_PI / 180);
		while (i < 300)
		{
			addr = (char *)data->img.img_addr + (int)posy * \
					data->img.size_line + (int)(posx) * \
					(data->img.bits_per_pixel / 8);
			if (*(unsigned int *)addr == 0x00999999 || *(unsigned int *)addr == 0x1a000d || *(unsigned int *)addr == 0x009933)
			{
				paint_pixel(data, (int)posx, (int)posy, 0x009933);
				posx += dirx;
				posy += diry;
			}
			i++;
		}
		j += 3;
	}
}

void	create_minimap(t_data *data)
{
	int		res_x;
	int		res_y;
	int		startx;
	int		starty;

	res_x = WIN_WIDTH;
	res_y = 0;
	starty = starty_minimap(data, count_map(data->map, 1));
	startx = startx_minimap(data, count_map(data->map, 0));
	while (data->map[starty])
	{
		startx = startx_minimap(data, count_map(data->map, 0));
		while (data->map[starty][startx])
		{
			draw_minimap(data, startx, starty, res_x, res_y);
			startx++;
			res_x += 20;
		}
		res_x = WIN_WIDTH;
		res_y += 20;
		starty++;
	}
	draw_player(data, starty_minimap(data, count_map(data->map, 1)), \
		startx_minimap(data, count_map(data->map, 0)));
	draw_ray_scan(data);
}
