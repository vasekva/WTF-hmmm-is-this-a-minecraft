#include "cub3d.h"

void	ft_def_coord_texfloor(t_cub3d *cub3d)
{
	if (cub3d->dda3d.side == 0)
	{
		cub3d->floor.wall_x = cub3d->dda2d.map_x;
		cub3d->floor.wall_y = cub3d->dda2d.map_y + cub3d->wall_x;
	}
	else if (cub3d->dda3d.side == 1)
	{
		cub3d->floor.wall_x = cub3d->dda2d.map_x + 1.0;
		cub3d->floor.wall_y = cub3d->dda2d.map_y + cub3d->wall_x;
	}
	else if (cub3d->dda3d.side == 2)
	{
		cub3d->floor.wall_x = cub3d->dda2d.map_x + cub3d->wall_x;
		cub3d->floor.wall_y = cub3d->dda2d.map_y;
	}
	else if (cub3d->dda3d.side == 3)
	{
		cub3d->floor.wall_x = cub3d->dda2d.map_x + cub3d->wall_x;
		cub3d->floor.wall_y = cub3d->dda2d.map_y + 1.0;
	}
}

void	ft_draw_floor(t_cub3d *cub3d, int x)
{
	int	y;

	ft_def_coord_texfloor(cub3d);
	if (cub3d->dda3d.draw_end < 0)
		cub3d->dda3d.draw_end = cub3d->scr_h;
	y = cub3d->dda3d.draw_end;
	while (y < cub3d->scr_h)
	{
		cub3d->floor.distance = cub3d->scr_h / (2.0 * y - cub3d->scr_h);
		if (cub3d->texture[4].texture == 1)
		{
			ft_set_tex_coor(cub3d, 4);
			get_color(cub3d, 4, cub3d->floor.texture_x, cub3d->floor.texture_y);
		}
		else
			cub3d->texture[4].color = cub3d->texture[4].column;
		color_dist(cub3d, 4, cub3d->floor.distance);
		draw_pix(cub3d, 4, x, y);
		y++;
	}
}
