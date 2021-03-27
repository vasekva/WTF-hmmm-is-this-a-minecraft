#include "cub3d.h"	

int	ft_start_game(t_cub3d *cub3d)
{
	if (cub3d->act.up == 1 || cub3d->act.down == 1)
		ft_move_forw_bacw(cub3d);
	if (cub3d->act.m_left == 1 || cub3d->act.m_right == 1
		|| cub3d->act.r_left == 1 || cub3d->act.r_right == 1)
		ft_move_side(cub3d);
	raycasting(cub3d);
	mlx_put_image_to_window(cub3d->mlx->mlx_ptr,
		cub3d->mlx->win_ptr, cub3d->mlx->image, 0, 0);
	return (0);
}
