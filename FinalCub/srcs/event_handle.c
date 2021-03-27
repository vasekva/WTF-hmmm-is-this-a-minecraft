#include "cub3d.h"

int	key_press(int key, t_cub3d *cub3d)
{
	if (key == W || key == UP)
		cub3d->keys.up = 1;
	if (key == S || key == DOWN)
		cub3d->keys.down = 1;
	if (key == LEFT)
		cub3d->keys.left = 1;
	if (key == A)
		cub3d->keys.key_a = 1;
	if (key == RIGHT)
		cub3d->keys.right = 1;
	if (key == D)
		cub3d->keys.key_d = 1;
	if (key == SHIFT)
		cub3d->keys.m_speed = 0.20;
	if (key == ESC)
		 exit(0);
	return (0);
}

int	key_release(int key, t_cub3d *cub3d)
{
	if (key == W || key == UP)
		cub3d->keys.up = 0;
	if (key == S || key == DOWN)
		cub3d->keys.down = 0;
	if (key == LEFT)
		cub3d->keys.left = 0;
	if (key == A)
		cub3d->keys.key_a = 0;
	if (key == RIGHT)
		cub3d->keys.right = 0;
	if (key == D)
		cub3d->keys.key_d = 0;
	if (key == SHIFT)
		cub3d->keys.m_speed = 0.10;
	return (0);
}
