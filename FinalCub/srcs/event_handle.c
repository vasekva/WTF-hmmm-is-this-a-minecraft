#include "cub3d.h"

int	key_press(int key, t_cub3d *cub3d)
{
	if (key == KEY_W || key == KEY_UP)
		cub3d->act.up = 1;
	if (key == KEY_S || key == KEY_DOWN)
		cub3d->act.down = 1;
	if (key == KEY_LEFT)
		cub3d->act.r_left = 1;
	if (key == KEY_A)
		cub3d->act.m_left = 1;
	if (key == KEY_RIGHT)
		cub3d->act.r_right = 1;
	if (key == KEY_D)
		cub3d->act.m_right = 1;
	if (key == KEY_SHIFT)
		cub3d->act.m_speed = 0.20;
	if (key == KEY_ESC)
		 exit(0);
	if (key == KEY_H)
	{
		if (cub3d->act.hud == 0)
			cub3d->act.hud = 1;
		else
			cub3d->act.hud = 0;
	}
	return (0);
}

int	key_release(int key, t_cub3d *cub3d)
{
	if (key == KEY_W || key == KEY_UP)
		cub3d->act.up = 0;
	if (key == KEY_S || key == KEY_DOWN)
		cub3d->act.down = 0;
	if (key == KEY_LEFT)
		cub3d->act.r_left = 0;
	if (key == KEY_A)
		cub3d->act.m_left = 0;
	if (key == KEY_RIGHT)
		cub3d->act.r_right = 0;
	if (key == KEY_D)
		cub3d->act.m_right = 0;
	if (key == KEY_SHIFT)
		cub3d->act.m_speed = 0.10;
	return (0);
}
