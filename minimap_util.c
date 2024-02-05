/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:30:40 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/05 19:31:00 by ntairatt         ###   ########.fr       */
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
		starty = max_y - 15;
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
