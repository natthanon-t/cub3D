/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:54:41 by ntairatt          #+#    #+#             */
/*   Updated: 2024/01/27 16:13:54 by ntairatt         ###   ########.fr       */
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

void	read_file(t_data *prog);
int		init_bg(t_data *prog, char *line);
void	init_rgb(t_data *prog, char *line);
void	init_wall(t_data *prog, char **str);
int		read_map(t_data *prog);

/* mlx */
void	init_mlx(t_data *prog);

/* key destroy */
int		key_esc(int keycode, t_data *prog);
int		win_cross(t_data *prog);

/* utils 1 */
void	ft_free_str2d(char **str);
size_t	ft_str2dlen(char **str);
void	exit_message(t_data *prog, char *str1, char *str2);
void	free_prog(t_data *prog);
int		ft_iscub(char *file_name);

/* utils 2 */
char	**ft_realloc2d(char **ptr, size_t size);

#endif
