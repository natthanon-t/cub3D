/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:52:14 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/06 18:19:59 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*get_color(t_data *data, int x, int y)
{
	char	*c;

	c = (char *)data->img.img_addr + (y * \
		data->img.size_line + x * (data->img.bits_per_pixel / 8));
	return (c);
}

int	check_color(char *c)
{
	if (*(unsigned int *)c == L || \
		*(unsigned int *)c == I)
		return (1);
	else
		return (0);
}

void	draw_minimap_util(t_data *data, t_data2 *m, int i, int j)
{
	if (data->map[m->starty][m->startx] == '1')
	{
		if (i == 20 || j == 20 || !i || !j)
			paint_pixel(data, m->res_x + i, m->res_y + j, L);
		else
			paint_pixel(data, m->res_x + i, m->res_y + j, I);
	}
	else if (data->map[m->starty][m->startx] && !check_color(\
			get_color(data, m->res_x + i, m->res_y + j)))
	{
		if (i == 20 || j == 20 || !i || !j)
			paint_pixel(data, m->res_x + i, m->res_y + j, N);
		else
			paint_pixel(data, m->res_x + i, m->res_y + j, E);
	}
}
