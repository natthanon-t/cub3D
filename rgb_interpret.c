/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_interpret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:20:43 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/02 23:20:47 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int	ft_tohex(int red, int green, int blue)
{
	return (((red & 0xFF) << 16) | ((green & 0xFF) << 8) | (blue & 0xFF));
}

void	rgb_convert(t_data *prog, int *rgb, size_t index)
{
	if (!index)
		prog->floor_color = ft_tohex(rgb[0], rgb[1], rgb[2]);
	else
		prog->ceiling_color = ft_tohex(rgb[0], rgb[1], rgb[2]);
}

int	ft_isnum(const char *str)
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

int	rgb_check(char **str2d, int *rgb)
{
	size_t	i;
	char	*str;

	i = 0;
	while (str2d[i])
	{
		str = ft_strtrim(str2d[i], " ");
		if (!str)
			return (EXIT_FAILURE);
		if (ft_isnum(str))
			return (free(str), EXIT_FAILURE);
		rgb[i] = ft_atoi(str);
		free(str);
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
		rgb_convert(prog, rgb, i);
		ft_free_str2d(str2d);
		i++;
	}
	return (EXIT_SUCCESS);
}
