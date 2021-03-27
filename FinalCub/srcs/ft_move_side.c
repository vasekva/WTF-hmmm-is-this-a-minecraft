#include "cub3d.h"

void 	ft_move_left(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->player.pos_x- cub3d->player.dir_y * cub3d->keys.m_speed)]
		[(int)(cub3d->player.pos_y)] == '0')
		cub3d->player.pos_x -= cub3d->player.dir_y * cub3d->keys.m_speed;
	if (cub3d->map[(int)(cub3d->player.pos_x)]
		[(int)(cub3d->player.pos_y + cub3d->player.dir_x * cub3d->keys.m_speed)] == '0')
		cub3d->player.pos_y += cub3d->player.dir_x * cub3d->keys.m_speed;
}

void 	ft_move_right(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->player.pos_x + cub3d->player.dir_y * cub3d->keys.m_speed)]
		[(int)(cub3d->player.pos_y)] == '0')
		cub3d->player.pos_x += cub3d->player.dir_y * cub3d->keys.m_speed;
	if (cub3d->map[(int)(cub3d->player.pos_x)]
		[(int)(cub3d->player.pos_y - cub3d->player.dir_x * cub3d->keys.m_speed)] == '0')
		cub3d->player.pos_y -= cub3d->player.dir_x * cub3d->keys.m_speed;
}

void 	ft_turn_left(t_cub3d *cub3d)
{
	if (cub3d->keys.left == 1)
	{
		cub3d->move.olddir_x = cub3d->player.dir_x;
		cub3d->player.dir_x
			= cub3d->player.dir_x * cos(cub3d->keys.r_speed)
			- cub3d->player.dir_y * sin(cub3d->keys.r_speed);
		cub3d->player.dir_y
			= cub3d->move.olddir_x * sin(cub3d->keys.r_speed)
			+ cub3d->player.dir_y * cos(cub3d->keys.r_speed);
		cub3d->move.oldplane_x = cub3d->move.plane_x;
		cub3d->move.plane_x
			= cub3d->move.plane_x * cos(cub3d->keys.r_speed)
			- cub3d->move.plane_y * sin(cub3d->keys.r_speed);
		cub3d->move.plane_y
			= cub3d->move.oldplane_x * sin(cub3d->keys.r_speed)
			+ cub3d->move.plane_y * cos(cub3d->keys.r_speed);
	}
}

void 	ft_turn_right(t_cub3d *cub3d)
{
	if (cub3d->keys.right == 1)
	{
		cub3d->move.olddir_x = cub3d->player.dir_x;
		cub3d->player.dir_x
			= cub3d->player.dir_x * cos(-cub3d->keys.r_speed)
			- cub3d->player.dir_y * sin(-cub3d->keys.r_speed);
		cub3d->player.dir_y
			= cub3d->move.olddir_x * sin(-cub3d->keys.r_speed)
			+ cub3d->player.dir_y * cos(-cub3d->keys.r_speed);
		cub3d->move.oldplane_x = cub3d->move.plane_x;
		cub3d->move.plane_x
			= cub3d->move.plane_x * cos(-cub3d->keys.r_speed)
			- cub3d->move.plane_y * sin(-cub3d->keys.r_speed);
		cub3d->move.plane_y
			= cub3d->move.oldplane_x * sin(-cub3d->keys.r_speed)
			+ cub3d->move.plane_y * cos(-cub3d->keys.r_speed);
	}
}

void	ft_move_side(t_cub3d *cub3d)
{
	if (cub3d->keys.key_a == 1)
	{
		ft_move_left(cub3d);
	}
	if (cub3d->keys.key_d == 1)
	{
		ft_move_right(cub3d);
	}
	if (cub3d->keys.left == 1)
	{
		ft_turn_left(cub3d);
	}
	if (cub3d->keys.right == 1)
	{
		ft_turn_right(cub3d);
	}
}
