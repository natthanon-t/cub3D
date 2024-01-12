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
int		ft_iscub(char *file_name);

/* mlx */
void	init_mlx(t_data *prog);

/* key destroy */
int		key_esc(int keycode, t_data *prog);
int		win_cross(t_data *prog);

int		ft_iscub(char *file_name);

#endif
