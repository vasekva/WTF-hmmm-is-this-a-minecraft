#include "cub3D.h"

int     keyrelease_hook(int key, void *param)
{
	t_cub3D *cub3D;

	if (param)
	{
		cub3D = (t_cub3D *)param;
		key == LEFT_A ? cub3D->player->leftAKey = 0 : 0;
		key == RIGHT_D ? cub3D->player->rightDKey = 0 : 0;
		key == LEFT ? cub3D->player->leftKey = 0 : 0;
		key == RIGHT ? cub3D->player->rightKey = 0 : 0;
		key == UP ? cub3D->player->upKey = 0 : 0;
		key == DOWN ? cub3D->player->downKey = 0 : 0;
	}
	return (1);
}

int	keypress_hook(int key, void *param)
{
	t_cub3D *cub3D;

	if (param)
	{
		cub3D = (t_cub3D *)param;
		key == LEFT_A ? cub3D->player->leftAKey = 1 : 0;
		key == RIGHT_D ? cub3D->player->rightDKey = 1 : 0;
		key == LEFT ? cub3D->player->leftKey = 1 : 0;
		key == RIGHT ? cub3D->player->rightKey = 1 : 0;
		key == UP ? cub3D->player->upKey = 1 : 0;
		key == DOWN ? cub3D->player->downKey = 1 : 0;
		key == ESC ? exit(0) : 0;
	}
	return (1);
}