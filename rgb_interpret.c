/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_interpret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:20:43 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/05 16:08:43 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static unsigned int	ft_tohex(int red, int green, int blue)
{
	return (((red & 0xFF) << 16) | ((green & 0xFF) << 8) | (blue & 0xFF));
}

static int	ft_isnum(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (EXIT_SUCCESS);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	rgb_check(char **str2d, int *rgb)
{
	size_t	i;

	i = 0;
	while (str2d[i])
	{
		if (ft_isnum(str2d[i]) == EXIT_FAILURE)
			return (free(str2d[i]), EXIT_FAILURE);
		rgb[i] = ft_atoi(str2d[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	rgb_interpret(t_data *prog)
{
	size_t	i;
	char	**str2d;
	int		rgb[3];

	i = 0;
	while (prog->rgb[i])
	{
		str2d = ft_split(prog->rgb[i], ',');
		if (!str2d || ft_str2dlen(str2d) != 3 || rgb_check(str2d, rgb))
			return (EXIT_FAILURE);
		if (!i)
			prog->floor_color = ft_tohex(rgb[0], rgb[1], rgb[2]);
		else
			prog->ceiling_color = ft_tohex(rgb[0], rgb[1], rgb[2]);
		ft_free_str2d(str2d);
		i++;
	}
	return (EXIT_SUCCESS);
}
