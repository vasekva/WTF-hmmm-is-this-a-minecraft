#include "cub3D.h"

int     keyrelease_hook(int key, void *param)
{
	t_cub3D *cub3D;

	if (param)
	{
		cub3D = (t_cub3D *)param;
		key == LEFT_A ? cub3D->keys->leftAKey = 0 : 0;
		key == RIGHT_D ? cub3D->keys->rightDKey = 0 : 0;
		key == LEFT ? cub3D->keys->leftKey = 0 : 0;
		key == RIGHT ? cub3D->keys->rightKey = 0 : 0;
		key == UP ? cub3D->keys->upKey = 0 : 0;
		key == DOWN ? cub3D->keys->downKey = 0 : 0;
	}
	return (1);
}

int	keypress_hook(int key, void *param)
{
	t_cub3D *cub3D;

	if (param)
	{
		cub3D = (t_cub3D *)param;
		key == LEFT_A ? cub3D->keys->leftAKey = 1 : 0;
		key == RIGHT_D ? cub3D->keys->rightDKey = 1 : 0;
		key == LEFT ? cub3D->keys->leftKey = 1 : 0;
		key == RIGHT ? cub3D->keys->rightKey = 1 : 0;
		key == UP ? cub3D->keys->upKey = 1 : 0;
		key == DOWN ? cub3D->keys->downKey = 1 : 0;
		key == ESC ? exit(0) : 0;
	}
	return (1);
}