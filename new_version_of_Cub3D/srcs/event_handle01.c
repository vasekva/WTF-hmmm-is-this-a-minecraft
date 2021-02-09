#include "cub3D.h"

int     keyrelease_hook(int key, void *param)
{
	t_cub3D *cub3D;

	if (param)
	{
		cub3D = (t_cub3D *)param;
		if (key == LEFT)
		{
			printf("LEFT\n");
		}
		if (key == RIGHT)
		{

			printf("RIGHT\n");
		}
		if (key == UP)
		{
			printf("UP\n");
		}
		if (key == DOWN)
		{
			printf("DOWN\n");
		}
	}
	return (1);
}

int	keypress_hook(int key, void *param)
{
	t_cub3D *cub3D;

	if (param)
	{
		cub3D = (t_cub3D *)param;
		if (key == ESC)
            exit(0);
		if (key == LEFT)
		{
			//cub3D->player->posX -= MOVESPEED;
			cub3D->player->posA -= 0.1;
			if (cub3D->player->posA < 0)
			{
				cub3D->player->posA += 2 * PI;
			}
			cub3D->player->posDirX = cos(cub3D->player->posA) * 5;
			cub3D->player->posDirY = sin(cub3D->player->posA) * 5;
		}
		if (key == RIGHT)
		{
			//cub3D->player->posX += MOVESPEED;
			cub3D->player->posA += 0.1;
			if (cub3D->player->posA > 2 * PI)
			{
				cub3D->player->posA -= 2 *PI;
			}
			cub3D->player->posDirX = cos(cub3D->player->posA) * 5;
			cub3D->player->posDirY = sin(cub3D->player->posA) * 5;
		}
		if (key == UP)
		{
			//cub3D->player->posY -= MOVESPEED;
			cub3D->player->posX += cub3D->player->posDirX;
			cub3D->player->posY += cub3D->player->posDirY;
		}
		if (key == DOWN)
		{
			//cub3D->player->posY += MOVESPEED;
			cub3D->player->posX -= cub3D->player->posDirX;
			cub3D->player->posY -= cub3D->player->posDirY;
		}
	}
	return (1);
}