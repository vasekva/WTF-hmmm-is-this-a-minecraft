#include "cub3d.h"

void 	ft_move_left(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->pos_x - cub3d->dir_y * cub3d->act.m_speed)]
		[(int)(cub3d->pos_y)] == '0')
		cub3d->pos_x -= cub3d->dir_y * cub3d->act.m_speed;
	if (cub3d->map[(int)(cub3d->pos_x)]
		[(int)(cub3d->pos_y + cub3d->dir_x * cub3d->act.m_speed)] == '0')
		cub3d->pos_y += cub3d->dir_x * cub3d->act.m_speed;
}

void 	ft_move_right(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->pos_x + cub3d->dir_y * cub3d->act.m_speed)]
		[(int)(cub3d->pos_y)] == '0')
		cub3d->pos_x += cub3d->dir_y * cub3d->act.m_speed;
	if (cub3d->map[(int)(cub3d->pos_x)]
		[(int)(cub3d->pos_y - cub3d->dir_x * cub3d->act.m_speed)] == '0')
		cub3d->pos_y -= cub3d->dir_x * cub3d->act.m_speed;
}

void 	ft_turn_left(t_cub3d *cub3d)
{
	if (cub3d->act.r_left == 1)
	{
		cub3d->olddir_x = cub3d->dir_x;
		cub3d->dir_x
			= cub3d->dir_x * cos(cub3d->act.r_speed)
			- cub3d->dir_y * sin(cub3d->act.r_speed);
		cub3d->dir_y
			= cub3d->olddir_x * sin(cub3d->act.r_speed)
			+ cub3d->dir_y * cos(cub3d->act.r_speed);
		cub3d->oldplane_x = cub3d->plane_x;
		cub3d->plane_x
			= cub3d->plane_x * cos(cub3d->act.r_speed)
			- cub3d->plane_y * sin(cub3d->act.r_speed);
		cub3d->plane_y
			= cub3d->oldplane_x * sin(cub3d->act.r_speed)
			+ cub3d->plane_y * cos(cub3d->act.r_speed);
	}
}

void 	ft_turn_right(t_cub3d *cub3d)
{
	if (cub3d->act.r_right == 1)
	{
		cub3d->olddir_x = cub3d->dir_x;
		cub3d->dir_x
			= cub3d->dir_x * cos(-cub3d->act.r_speed)
			- cub3d->dir_y * sin(-cub3d->act.r_speed);
		cub3d->dir_y
			= cub3d->olddir_x * sin(-cub3d->act.r_speed)
			+ cub3d->dir_y * cos(-cub3d->act.r_speed);
		cub3d->oldplane_x = cub3d->plane_x;
		cub3d->plane_x
			= cub3d->plane_x * cos(-cub3d->act.r_speed)
			- cub3d->plane_y * sin(-cub3d->act.r_speed);
		cub3d->plane_y
			= cub3d->oldplane_x * sin(-cub3d->act.r_speed)
			+ cub3d->plane_y * cos(-cub3d->act.r_speed);
	}
}

void	ft_move_side(t_cub3d *cub3d)
{
	if (cub3d->act.m_left == 1)
	{
		ft_move_left(cub3d);
	}
	if (cub3d->act.m_right == 1)
	{
		ft_move_right(cub3d);
	}
	if (cub3d->act.r_left == 1)
	{
		ft_turn_left(cub3d);
	}
	if (cub3d->act.r_right == 1)
	{
		ft_turn_right(cub3d);
	}
}
