#include "cub3D.h"

void	p_move_forward(t_data *data)
{
	int	i;
	int	j;

	i = (int)data->p.posY;
	j = (int)(data->p.posX + data->p.dirX
			* data->p.moveSpeed);
	if (data->map[i][j] != '1')
		data->p.posX += data->p.dirX * data->p.moveSpeed;
	i = (int)(data->p.posY + data->p.dirY * data->p.moveSpeed);
	j = (int)data->p.posX;
	if (data->map[i][j] != '1')
		data->p.posY += data->p.dirY * data->p.moveSpeed;
}

void	p_move_backwards(t_data *data)
{
	int	i;
	int	j;

	i = (int)data->p.posY;
	j = (int)(data->p.posX - data->p.dirX
			* data->p.moveSpeed);
	if (data->map[i][j] != '1')
		data->p.posX -= data->p.dirX * data->p.moveSpeed;
	i = (int)(data->p.posY - data->p.dirY * data->p.moveSpeed);
	j = (int)data->p.posX;
	if (data->map[i][j] != '1')
		data->p.posY -= data->p.dirY * data->p.moveSpeed;
}

void	p_move_left(t_data *data)
{
	int	i;
	int	j;

	i = (int)data->p.posY;
	j = (int)(data->p.posX + data->p.dirY * data->p.moveSpeed);
	if (data->map[i][j] != '1')
		data->p.posX += data->p.dirY * data->p.moveSpeed;
	i = (int)(data->p.posY - data->p.dirX * data->p.moveSpeed);
	j = (int)data->p.posX;
	if (data->map[i][j] != '1')
		data->p.posY -= data->p.dirX * data->p.moveSpeed;
}

void	p_move_right(t_data *data)
{
	int	i;
	int	j;

	i = (int)data->p.posY;
	j = (int)(data->p.posX - data->p.dirY * data->p.moveSpeed);
	if (data->map[i][j] != '1')
		data->p.posX -= data->p.dirY * data->p.moveSpeed;
	i = (int)(data->p.posY + data->p.dirX * data->p.moveSpeed);
	j = (int)data->p.posX;
	if (data->map[i][j] != '1')
		data->p.posY += data->p.dirX * data->p.moveSpeed;
}

void	move(t_data *data)
{
	if (data->key.w == KEY_PRESSED)
		p_move_forward(data);
	if (data->key.s == KEY_PRESSED)
		p_move_backwards(data);
	if (data->key.a == KEY_PRESSED)
		p_move_left(data);
	if (data->key.d == KEY_PRESSED)
		p_move_right(data);
	if (data->key.arrow_left == KEY_PRESSED)
		rotate_left(data);
	if (data->key.arrow_right == KEY_PRESSED)
		rotate_right(data);
}
