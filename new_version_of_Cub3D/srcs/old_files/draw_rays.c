#include "cub3D.h"

void		draw_rays(t_cub3D *cub3D)
{
	int mapX = cub3D->parser->max_strlen_of_map;
	int mapY = cub3D->parser->count_of_map_lines;
	double posY = cub3D->player->posY;
	double posX = cub3D->player->posX;

	int r, mx, my, mp, dof;
	float rx, ry, ra, xo, yo;
	ra = cub3D->player->posA;

	for (r = 0; r < 1; r++)
	{
		dof = 0;
		float aTan = -1 / tan(ra);
		if (ra > PI)
		{
			ry = (((int)posY>>6)<<6) - 0.0001;
			rx = (posY - ry) * aTan + posX;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < PI)
		{
			ry = (((int)posY>>6)<<6) + 64;
			rx = (posY - ry) * aTan + posX;
			yo = 64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = posX;
			ry = posY;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx)>>6;
			my = (int)(ry)>>6;
			mp = my * mapX + mx;
			if (mp < mapX * mapY && cub3D->array[my][mx] == 1)
			{
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		print_DDALine(posX, posY, rx, ry, cub3D);
	}
}