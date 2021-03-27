#include "cub3d.h"

void	ft_draw_sky(t_cub3d *cub3d, int x)
{
	int	y;
	int	skytex;

	y = 0;
	while (y < cub3d->dda3d.draw_start)
	{
		skytex
			= abs((int)(x - cub3d->texture[5].width * (M_PI / 2)
					* atan(cub3d->player.dir_y / (cub3d->player.dir_x + 0.01)))
				*cub3d->texture[5].bits_per_pixel / 8 + y * cub3d->texture[5].line_length);
		cub3d->texture[5].color = *(int *)(cub3d->texture[5].ptr_texture + skytex);
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
	while (y < cub3d->dda3d.draw_start)
	{
		cub3d->floor.distance = -cub3d->scr_h / (2.0 * y - cub3d->scr_h);
		if (cub3d->texture[5].texture == 1)
		{
			ft_set_tex_coor(cub3d, 5);
			get_color(cub3d, 5, cub3d->floor.texture_x, cub3d->floor.texture_y);
		}
		else
			cub3d->texture[5].color = cub3d->texture[5].column;
		color_dist(cub3d, 5, cub3d->floor.distance);
		draw_pix(cub3d, 5, x, y);
		y++;
	}
}

void	draw_all(t_cub3d *cub3d, int x)
{
	ft_draw_walls(cub3d, x);
	ft_draw_floor(cub3d, x);
	if (cub3d->texture[5].path_texture
		&& !ft_strncmp(cub3d->texture[5].path_texture, "textures/c_sky", 12))
	{
		ft_draw_sky(cub3d, x);
	}
	else
	{
		ft_draw_ceiling(cub3d, x);
	}
}
