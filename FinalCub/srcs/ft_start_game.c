#include "cub3d.h"	

int	ft_start_game(t_cub3d *cub3d)
{
	if (cub3d->keys.up == 1 || cub3d->keys.down == 1)
		ft_move_forw_bacw(cub3d);
	if (cub3d->keys.key_a == 1 || cub3d->keys.key_d == 1
		|| cub3d->keys.left == 1 || cub3d->keys.right == 1)
		ft_move_side(cub3d);
	start_raycast(cub3d);
	mlx_put_image_to_window(cub3d->mlx->p_mlx,
		cub3d->mlx->p_win, cub3d->mlx->image, 0, 0);
	return (0);
}
