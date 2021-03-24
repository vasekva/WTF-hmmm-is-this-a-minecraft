#include "cub3d.h"	

int	ft_start_game(t_cub3d *cub3d)
{
	if (cub3d->act.up == 1 || cub3d->act.down == 1)
		ft_move_forw_bacw(cub3d);
	if (cub3d->act.m_left == 1 || cub3d->act.m_right == 1
		|| cub3d->act.r_left == 1 || cub3d->act.r_right == 1)
		ft_move_side(cub3d);
	raycasting(cub3d);
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr, cub3d->image, 0, 0);
	if (cub3d->act.hud == 1)
	{
		mlx_string_put(cub3d->mlx_ptr, cub3d->win_ptr, 10, 20, 0xFFFFFF,
			"W, A, S, D : move");
		mlx_string_put(cub3d->mlx_ptr, cub3d->win_ptr, 30, 20, 0xFFFFFF,
			"<- & -> : rotate");
		mlx_string_put(cub3d->mlx_ptr, cub3d->win_ptr, 50, 20, 0xFFFFFF,
			"SHIFT : sprint");
		mlx_string_put(cub3d->mlx_ptr, cub3d->win_ptr, 70, 20, 0xFFFFFF,
			"H : Hide the menu");
		mlx_string_put(cub3d->mlx_ptr, cub3d->win_ptr, 90, 20, 0xFFFFFF,
			"ESC : exit");
	}
	return (0);
}
