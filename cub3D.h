/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:54:41 by ntairatt          #+#    #+#             */
/*   Updated: 2024/02/06 18:15:57 by ntairatt         ###   ########.fr       */
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
int		count_map(char **map, int mode);

/* RGB */
int		rgb_interpret(t_data *prog);

/* Map_read */
int		map_add(t_data *prog, char *line);
int		map_check(t_data *prog);

/* Map_check */
int		map_check(t_data *prog);

/* Vector */
void	vector_init(t_data *prog, size_t x, size_t y);
void	vector_init_util(t_data *prog, size_t x, size_t y);

/* mlx */
int		init_mlx(t_data *prog);
void	paint_pixel(t_data *prog, int x, int y, int color);
void	paint_background(t_data *prog);

/* key destroy */
void	rotate_right(t_data *prog);
void	rotate_left(t_data *prog);
int		key_esc(int keycode, t_data *prog);
int		win_cross(t_data *prog);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);

/* movement */
void	move(t_data *data);

/* minimap */
void	create_minimap(t_data *data);
int		starty_minimap(t_data *data, int max_y);
int		startx_minimap(t_data *data, int max_x);
int		check_color(char *c);
char 	*get_color(t_data *data, int x, int y);
void	draw_minimap_util(t_data *data, t_data2 *m, int i, int j);

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
int		exit_ex(t_data *prog);

/* raycast */
void	raycast(t_data *prog);
void	raycast_util(t_data *prog, int x);

#endif
