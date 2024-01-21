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

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_DESTROY 17

# define KEY_PRESSED 1
# define KEY_RELEASED 0

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

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
void	exit_error(t_data *prog, char *str1, char *str2);
void	free_prog(t_data *prog);
int		ft_iscub(char *file_name);

/* utils 2 */
void	**ft_realloc2d(char **ptr, size_t size);

#endif
