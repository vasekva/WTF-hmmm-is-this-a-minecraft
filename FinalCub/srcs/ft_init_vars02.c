#include "cub3d.h"

static void	init_cub(t_cub3d *cub3d)
{
	cub3d->act.up = 0;
	cub3d->act.down = 0;
	cub3d->act.r_left = 0;
	cub3d->act.m_left = 0;
	cub3d->act.r_right = 0;
	cub3d->act.m_right = 0;
	cub3d->act.m_speed = 0.10;
	cub3d->act.r_speed = 0.10;
	cub3d->sprite.distbuf = malloc(sizeof(int *) * cub3d->scr_w);
	if (!cub3d->sprite.distbuf)
		exception(cub3d, TWENTYTWO);
}

static void	init_position(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < cub3d->map_h)
	{
		while (cub3d->map[x][y])
		{
			if (cub3d->map[x][y] == 'N' || cub3d->map[x][y] == 'S'
				|| cub3d->map[x][y] == 'E' || cub3d->map[x][y] == 'W')
			{
				cub3d->player.pos_x = x;
				cub3d->player.pos_y = y;
			}
			y++;
		}
		y = 0;
		x++;
	}
	cub3d->player.pos_x = cub3d->player.pos_x + 0.5;
	cub3d->player.pos_y = cub3d->player.pos_y + 0.5;
}

static void	init_direction(t_cub3d *cub3d)
{
	if (cub3d->map[(int)cub3d->player.pos_x][(int)cub3d->player.pos_y] == 'N')
	{
		cub3d->player.dir_x = -1;
		cub3d->player.dir_y = 0;
	}
	else if (cub3d->map[(int)cub3d->player.pos_x][(int)cub3d->player.pos_y] == 'S')
	{
		cub3d->player.dir_x = 1;
		cub3d->player.dir_y = 0;
	}
	else if (cub3d->map[(int)cub3d->player.pos_x][(int)cub3d->player.pos_y] == 'E')
	{
		cub3d->player.dir_x = 0;
		cub3d->player.dir_y = 1;
	}
	else if (cub3d->map[(int)cub3d->player.pos_x][(int)cub3d->player.pos_y] == 'W')
	{
		cub3d->player.dir_x = 0;
		cub3d->player.dir_y = -1;
	}
}

static void	init_plane(t_cub3d *cub3d)
{
	if (cub3d->map[(int)cub3d->player.pos_x][(int)cub3d->player.pos_y] == 'N'
		|| cub3d->map[(int)cub3d->player.pos_x][(int)cub3d->player.pos_y] == 'S')
	{
		cub3d->move.plane_x = -cub3d->player.dir_y * tan(M_PI * 33 / 180);
		cub3d->move.plane_y = -cub3d->player.dir_x * tan(M_PI * 33 / 180);
	}
	else if (cub3d->map[(int)cub3d->player.pos_x][(int)cub3d->player.pos_y] == 'E'
		|| cub3d->map[(int)cub3d->player.pos_x][(int)cub3d->player.pos_y] == 'W')
	{
		cub3d->move.plane_x = cub3d->player.dir_y * tan(M_PI * 33 / 180);
		cub3d->move.plane_y = cub3d->player.dir_x * tan(M_PI * 33 / 180);
	}
	cub3d->map[(int)cub3d->player.pos_x][(int)cub3d->player.pos_y] = '0';
}

void	ft_init_vars02(t_cub3d *cub3d)
{
	init_cub(cub3d);
	init_position(cub3d);
	init_direction(cub3d);
	init_plane(cub3d);
	ft_count_sprites(cub3d);
}

/*
** (M_PI * 33 / 180) rad = (66 / 2) deg
*/