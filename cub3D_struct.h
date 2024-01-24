#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		x_update;
	int		y_update;
	int		color;
}				t_point;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_key
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		arrow_right;
	int		arrow_left;
}				t_key;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}				t_mlx;

typedef struct s_data
{
	int				fd;
	char			**map;
	char			*xpm[5];
	char			*rgb[3];
	unsigned long	floor_color;
	unsigned long	ceiling_color;
	t_mlx			mlx;
	t_img			img;
	t_key			key;
}				t_data;

#endif
