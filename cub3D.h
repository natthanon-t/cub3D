/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:54:41 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/04 10:41:42 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "cub3D_struct.h"

/* main */

int		init_data(t_data *prog, char *filename);
void	file_read(t_data *prog);
int		bg_init(t_data *prog, char *line);
void	rgb_init(t_data *prog, char *line);
void	wall_init(t_data *prog, char **str);
int		map_read(t_data *prog);

/* RGB */
int		rgb_interpret(t_data *prog);

/* Map_read */
int		map_add(t_data *prog, char *line);

/* mlx */
void	init_mlx(t_data *prog);

/* key destroy */
int		key_esc(int keycode, t_data *prog);
int		win_cross(t_data *prog);

/* wall_set */
int		wall_set(t_data *prog);

/* utils 1 */
void	ft_free_str2d(char **str);
size_t	ft_str2dlen(char **str);
void	exit_message(t_data *prog, char *str1, char *str2, char *str_free);
void	free_prog(t_data *prog);
int		ft_iscub(char *file_name);

/* utils 2 */
char	**ft_realloc2d(char **ptr, size_t size);

#endif
