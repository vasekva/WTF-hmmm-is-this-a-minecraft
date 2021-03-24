#include "cub3d.h"

void 	ft_move_forward(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->pos_x + cub3d->dir_x * cub3d->act.m_speed)]
		[(int)(cub3d->pos_y)] == '0')
		cub3d->pos_x += cub3d->dir_x * cub3d->act.m_speed;
	if (cub3d->map[(int)(cub3d->pos_x)]
		[(int)(cub3d->pos_y + cub3d->dir_y * cub3d->act.m_speed)] == '0')
		cub3d->pos_y += cub3d->dir_y * cub3d->act.m_speed;
}

void 	ft_move_backward(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->pos_x - cub3d->dir_x * cub3d->act.m_speed)]
		[(int)(cub3d->pos_y)] == '0')
		cub3d->pos_x -= cub3d->dir_x * cub3d->act.m_speed;
	if (cub3d->map[(int)(cub3d->pos_x)]
		[(int)(cub3d->pos_y - cub3d->dir_y * cub3d->act.m_speed)] == '0')
		cub3d->pos_y -= cub3d->dir_y * cub3d->act.m_speed;
}

void	ft_move_forw_bacw(t_cub3d *cub3d)
{
	if (cub3d->act.up == 1)
	{
		ft_move_forward(cub3d);
	}
	if (cub3d->act.down == 1)
	{
		ft_move_backward(cub3d);
	}
}