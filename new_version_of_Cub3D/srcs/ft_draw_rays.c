#include "cub3D.h"

float				dist(float ax, float ay, float bx, float by, float ang)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void				ft_draw_rays(t_cub3D *cub3D)
{
	int mx, my, mp, dof;
	float rx, ry, ra, Xa, Ya;
	ra = cub3D->player->posA;

	int r;
	for (r = 0; r < 1; r++)
	{
		/*
		* Проверка горизонтальных пересечений
		*/
		dof = 0;
		float disH = 1000000;
		float disV = 1000000;
		float horizontalX = cub3D->player->posX;
		float horizontalY = cub3D->player->posY;
		float verticalX = cub3D->player->posX;
		float verticalY = cub3D->player->posY;
		float aTan = -1 / tan(ra);
		float nTan = -1 * tan(ra);
		if (ra > PI)
		{
			ry = (((int)cub3D->player->posY>>6)<<6) - 0.0001;
			rx = (cub3D->player->posY - ry) * aTan + cub3D->player->posX;
			Ya = -64;
			Xa = -Ya * aTan;
		}
		if (ra < PI)
		{
			ry = (((int)cub3D->player->posY>>6)<<6) + 64;
			rx = (cub3D->player->posY - ry) * aTan + cub3D->player->posX;
			Ya = 64;
			Xa = -Ya * aTan;
		}
		if (ra == 0 || ra == PI)
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
				horizontalX = rx;
				horizontalY = ry;
				disH = dist(cub3D->player->posX, cub3D->player->posY, horizontalX, horizontalY, ra);
				dof = LONG_VIEW;
			}
			else
			{
				rx += Xa;
				ry += Ya;
				dof += 1;
			}
			// print_DDALine(cub3D->player->posX, cub3D->player->posY, rx, ry, cub3D, 0x00FFFF00);
		}
		/*
		* Проверка вертикальных пересечений
		*/
		// dof = 0;
		// if (ra > PI2 && ra < PI3)
		// {
		// 	rx = (((int)cub3D->player->posX>>6)<<6) - 0.0001;
		// 	ry = (cub3D->player->posX - rx) * nTan + cub3D->player->posY;
		// 	Xa = -64;
		// 	Ya = -Xa * nTan;
		// }
		// if (ra < PI2 || ra > PI3)
		// {
		// 	rx = (((int)cub3D->player->posX>>6)<<6) + 64;
		// 	ry = (cub3D->player->posX - rx) * nTan + cub3D->player->posY;
		// 	Xa = 64;
		// 	Ya = -Xa * nTan;
		// }
		// if (ra == 0 || ra == PI)
		// {
		// 	rx = cub3D->player->posX;
		// 	ry = cub3D->player->posY;
		// 	dof = 8;
		// }
		// while (dof < LONG_VIEW)
		// {
		// 	mx = (int)(rx)>>6;
		// 	my = (int)(ry)>>6;
		// 	mp = my * cub3D->parser->max_strlen_of_map + mx;
		// 	if (mp > 0 && mp < cub3D->parser->max_strlen_of_map * cub3D->parser->count_of_map_lines
		// 		&& cub3D->array[my][mx] == '1')
		// 	{
		// 		verticalX = rx;
		// 		verticalY = ry;
		// 		disV = dist(cub3D->player->posX, cub3D->player->posY, verticalX, verticalY, ra);
		// 		dof = LONG_VIEW;
		// 	}
		// 	else
		// 	{
		// 		rx += Xa;
		// 		ry += Ya;
		// 		dof += 1;
		// 	}
		// 	if (disV < disH)
		// 	{
		// 		rx = verticalX;
		// 		ry = verticalY;
		// 	}
		// 	if (disH < disV)
		// 	{
		// 		rx = horizontalX;
		// 		ry = horizontalY;
		// 	}
		// }
		print_DDALine(cub3D->player->posX, cub3D->player->posY, rx, ry, cub3D, 0x00FFFFFF);
	}
}