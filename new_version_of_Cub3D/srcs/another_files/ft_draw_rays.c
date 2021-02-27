#include "cub3D.h"

float				dist(float ax, float ay, float bx, float by, float ang)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void				ft_draw_rays(t_cub3D *cub3D)
{
	int mapX = cub3D->parser->max_strlen_of_map;
	int mapY = cub3D->parser->count_of_map_lines;

	int mx, my, mp, dof;
	float rx, ry, ra, xo, yo;
	ra = cub3D->player->posA;

	int r;
	for (r = 0; r < 1; r++)
	{
		/*
		* Проверка горизонтальных пересечений
		*/
		dof = 0;
		float disH = 1000000;
		float hx = cub3D->player->posX;
		float hy = cub3D->player->posY;
		float aTan = -1 / tan(ra);
		if (ra > PI) // looking up
		{
			ry = (((int)cub3D->player->posY>>6)<<6) - 0.0001;
			rx = (cub3D->player->posY - ry) * aTan + cub3D->player->posX;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < PI)
		{
			ry = (((int)cub3D->player->posY>>6)<<6) + 64;
			rx = (cub3D->player->posY - ry) * aTan + cub3D->player->posX;
			yo = 64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI) // loking straight left or right
		{
			rx = cub3D->player->posX;
			ry = cub3D->player->posY;
			dof = LONG_VIEW;
		}
		while (dof < LONG_VIEW)
		{
			mx = (int)(rx)>>6;
			my = (int)(ry)>>6;
			mp = my * cub3D->parser->max_strlen_of_map + mx;
			if (mp > 0 && mp < cub3D->parser->max_strlen_of_map * cub3D->parser->count_of_map_lines
				&& cub3D->array[my][mx] == '1')
			{
				hx = rx;
				hy = ry;
				disH = dist(cub3D->player->posX, cub3D->player->posY, hx, hy, ra);
				dof = LONG_VIEW;
			}
			else
			{ 
				rx += xo;
				ry += yo;
				dof += 1;
			}
			// print_DDALine(cub3D->player->posX, cub3D->player->posY, rx, ry, cub3D, 0x00FFFF00);
		}
		/*
		* Проверка вертикальных пересечений
		*/
		dof = 0;
		float disV = 1000000;
		float vx = cub3D->player->posX;
		float vy = cub3D->player->posY;
		float nTan = -tan(ra);
		if (ra > PI2 && ra < PI3) // looking left
		{
			rx = (((int)cub3D->player->posX>>6)<<6) - 0.0001;
			ry = (cub3D->player->posX - rx) * nTan + cub3D->player->posY;
			xo = -64;
			yo = -xo * nTan;
		}
		if (ra < PI2 || ra > PI3) // looking right
		{
			rx = (((int)cub3D->player->posX>>6)<<6) + 64;
			ry = (cub3D->player->posX - rx) * nTan + cub3D->player->posY;
			xo = 64;
			yo = -xo * nTan;
		}
		if (ra == 0 || ra == PI) // looking straight up or down
		{
			rx = cub3D->player->posX;
			ry = cub3D->player->posY;
			dof = 8;
		}
		while (dof < LONG_VIEW)
		{
			mx = (int)(rx)>>6;
			my = (int)(ry)>>6;
			mp = my * mapX + mx;
			if (mp > 0 && mp < mapX * mapY
				&& cub3D->array[my][mx] == '1')
			{
				vx = rx;
				vy = ry;
				disV = dist(cub3D->player->posX, cub3D->player->posY, vx, vy, ra);
				dof = LONG_VIEW;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			} 
			if (disV < disH)
			{
				rx = vx;
				ry = vy;
			}
			if (disH < disV)
			{
				rx = hx;
				ry = hy;
			}
		}
		print_DDALine(cub3D->player->posX, cub3D->player->posY, rx, ry, cub3D, 0x00FFFFFF);
	}
}