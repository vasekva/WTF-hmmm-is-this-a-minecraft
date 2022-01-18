#include "cub3d.h"

static void 	ft_move_forward(t_cub3d *cub3d)
{
	if (cub3d->map
		[(int)(cub3d->player.pos_x + cub3d->player.dir_x * cub3d->keys.m_speed)]
		[(int)(cub3d->player.pos_y)] == '0')
		cub3d->player.pos_x += cub3d->player.dir_x * cub3d->keys.m_speed;
	if (cub3d->map[(int)(cub3d->player.pos_x)]
		[(int)(cub3d->player.pos_y + cub3d->player.dir_y * cub3d->keys.m_speed)]
		== '0')
		cub3d->player.pos_y += cub3d->player.dir_y * cub3d->keys.m_speed;
}

static void 	ft_move_backward(t_cub3d *cub3d)
{
	if (cub3d->map
		[(int)(cub3d->player.pos_x - cub3d->player.dir_x * cub3d->keys.m_speed)]
		[(int)(cub3d->player.pos_y)] == '0')
		cub3d->player.pos_x -= cub3d->player.dir_x * cub3d->keys.m_speed;
	if (cub3d->map[(int)(cub3d->player.pos_x)]
		[(int)(cub3d->player.pos_y - cub3d->player.dir_y * cub3d->keys.m_speed)]
		== '0')
		cub3d->player.pos_y -= cub3d->player.dir_y * cub3d->keys.m_speed;
}

void	ft_move_forw_bacw(t_cub3d *cub3d)
{
	if (cub3d->keys.up == 1)
		ft_move_forward(cub3d);
	if (cub3d->keys.down == 1)
		ft_move_backward(cub3d);
}
