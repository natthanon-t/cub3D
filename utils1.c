/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:18 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/02 23:04:54 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_str2d(char **str)
{
	size_t	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		free(str[i++]);
	free(str);
}

size_t	ft_str2dlen(char **str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (EXIT_SUCCESS);
	while (str[i])
		i++;
	return (i);
	
}

void	free_prog(t_data *prog)
{
	if (prog->map)
		ft_free_str2d(prog->map);
	//if (prog->mlx.window)
	//	mlx_destroy_window(prog->mlx.mlx, prog->mlx.window);
}

void	exit_message(t_data *prog, char *str1, char *str2)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd("\n", 2);
	close(prog->fd);
	exit(EXIT_FAILURE);
}

int	ft_iscub(char *file_name)
{
	char	*type;
	int		i;
	int		check;

	type = ".cub";
	check = 1;
	i = ft_strlen(file_name) - 4;
	if (i <= 0)
		return (check);
	else if (!ft_strncmp(&file_name[i], type, 4) && file_name[i])
		check = 0;
	return (check);
}
