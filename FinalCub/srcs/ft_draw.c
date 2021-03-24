#include "cub3d.h"

void	ft_draw_sky(t_cub3d *cub3d, int x)
{
	int	y;
	int	skytex;

	y = 0;
	while (y < cub3d->draw_start)
	{
		skytex
			= abs((int)(x - cub3d->tex[5].width * (M_PI / 2)
					* atan(cub3d->dir_y / (cub3d->dir_x + 0.01)))
				*cub3d->tex[5].bit_pix / 8 + y * cub3d->tex[5].size_line);
		cub3d->tex[5].color = *(int *)(cub3d->tex[5].tex_ptr + skytex);
		{
			draw_pix(cub3d, 5, x, y);
		}
		y++;
	}
}

void	ft_draw_ceiling(t_cub3d *cub3d, int x)
{
	int	y;

	y = 0;
	while (y < cub3d->draw_start)
	{
		cub3d->flr.cur_dist = -cub3d->res_y / (2.0 * y - cub3d->res_y);
		if (cub3d->tex[5].texture == 1)
		{
			ft_set_tex_coor(cub3d, 5);
			get_color(cub3d, 5, cub3d->flr.fl_tex_x, cub3d->flr.fl_tex_y);
		}
		else
			cub3d->tex[5].color = cub3d->tex[5].col;
		color_dist(cub3d, 5, cub3d->flr.cur_dist);
		draw_pix(cub3d, 5, x, y);
		y++;
	}
}

void	draw_all(t_cub3d *cub3d, int x)
{
	ft_draw_walls(cub3d, x);
	ft_draw_floor(cub3d, x);
	if (cub3d->tex[5].tex_path
		&& !ft_strncmp(cub3d->tex[5].tex_path, "textures/c_sky", 12))
	{
		ft_draw_sky(cub3d, x);
	}
	else
	{
		ft_draw_ceiling(cub3d, x);
	}
}