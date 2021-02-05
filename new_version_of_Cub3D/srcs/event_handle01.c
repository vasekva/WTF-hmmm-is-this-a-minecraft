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
			cub3D->player->posX -= 5;
		}
		if (key == RIGHT)
		{

			cub3D->player->posX += 5;
		}
		if (key == UP)
		{
			cub3D->player->posY -= 5;
		}
		if (key == DOWN)
		{
			cub3D->player->posY += 5;
		}
	}
	return (1);
}