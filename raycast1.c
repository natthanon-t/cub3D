#include "cub3D.h"

static void	calculate_ray(t_data *prog, int x)
{
	prog->p.cameraX = (2 * x) / (WIN_WIDTH - 1);
	prog->p.rayDirX = prog->p.dirX + prog->p.planeX * prog->p.cameraX;
	prog->p.rayDirY = prog->p.dirY + prog->p.planeY * prog->p.cameraX;
	prog->p.mapX = (int)prog->p.posX;
	prog->p.mapY = (int)prog->p.posY;
	if (prog->p.rayDirX == 0)
		prog->p.deltaDistX = 1e30;
	else
		prog->p.deltaDistX = fabs(1 / prog->p.rayDirX);
	if (prog->p.rayDirY == 0)
		prog->p.deltaDistY = 1e30;
	else
		prog->p.deltaDistY = fabs(1 / prog->p.rayDirY);
	prog->p.hit = 0;	
}

void	raycast(t_data *prog)
{
	int	x;

	while (x < WIN_WIDTH)
	{
		calculate_ray(prog, x);
	}
}