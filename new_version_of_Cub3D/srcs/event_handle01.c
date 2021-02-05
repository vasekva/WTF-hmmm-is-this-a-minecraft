#include "cub3D.h"

int     keyrelease_hook(int key, void *param)
{
	t_cub3D *cub3D;

	if (param)
	{
		cub3D = (t_cub3D *)param;
		if (key == LEFT)
		{
			cub3D->player->bool_left = 0;
			printf("LEFT\n");
		}
		if (key == RIGHT)
		{
			printf("bool before: %d\n", cub3D->player->bool_right);
			cub3D->player->bool_right = 0;
			printf("bool after: %d\n", cub3D->player->bool_right);
			printf("RIGHT\n");
		}
		if (key == UP)
		{
			cub3D->player->bool_up = 0;
			printf("UP\n");
		}
		if (key == DOWN)
		{
			cub3D->player->bool_down = 0;
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
			cub3D->player->bool_left = 1;
			cub3D->player->posX -= 5;
			ft_draw_user(cub3D);
			printf("LEFT\n");
		}
		if (key == RIGHT)
		{
			//printf("bool before: %d\n", cub3D->player->bool_right);
			cub3D->player->bool_right = 1;
			cub3D->player->posX += 5;
			//printf("bool after: %d\n", cub3D->player->bool_right);
			//printf("RIGHT\n");
		}
		if (key == UP)
		{
			cub3D->player->bool_up = 1;
			cub3D->player->posY -= 5;
			//printf("UP\n");
		}
		if (key == DOWN)
		{
			cub3D->player->bool_down = 1;
			cub3D->player->posY += 5;
			//printf("DOWN\n");
		}
	}
	return (1);
}