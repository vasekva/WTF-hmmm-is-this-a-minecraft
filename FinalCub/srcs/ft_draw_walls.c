#include "cub3d.h"

static int 	ft_def_wall_for_tex(t_cub3d *cub3d)
{
	int	i;

	if (cub3d->dda3d.side == 0)
		i = 0;
	else if (cub3d->dda3d.side == 1)
		i = 1;
	else if (cub3d->dda3d.side == 2)
		i = 2;
	else if (cub3d->dda3d.side == 3)
		i = 3;
	return (i);
}

static void	ft_texturing_wall(t_cub3d *cub3d, int x, int i)
{
	int	y;
	int	coord_x;
	int	coord_y;

	coord_x = (int)(cub3d->wall_x * (double)(cub3d->texture[i].width));
	if ((cub3d->dda3d.side == 0 || cub3d->dda3d.side == 1)
		&& cub3d->dda2d.ray_dir_x > 0)
		coord_x = cub3d->texture[i].width - coord_x - 1;
	if ((cub3d->dda3d.side == 2 || cub3d->dda3d.side == 3)
		&& cub3d->dda2d.ray_dir_y < 0)
		coord_x = cub3d->texture[i].width - coord_x - 1;
	coord_x = abs(coord_x);
	y = cub3d->dda3d.draw_start;
	while (y < cub3d->dda3d.draw_end)
	{
		coord_y = y * 256 - cub3d->scr_h * 128 + cub3d->dda3d.line_h * 128;
		coord_y
			= coord_y * cub3d->texture[i].height / cub3d->dda3d.line_h / 256;
		get_color(cub3d, i, coord_x, coord_y);
		color_dist(cub3d, i, cub3d->dda3d.wall_dist);
		draw_pix(cub3d, i, x, y);
		y++;
	}
}

void 	ft_draw_walls(t_cub3d *cub3d, int x)
{
	int	ind;
	int	y;

	ind = ft_def_wall_for_tex(cub3d);
	if (cub3d->dda3d.side == 0 || cub3d->dda3d.side == 1)
		cub3d->wall_x = cub3d->player.pos_y + cub3d->dda3d.wall_dist
			* cub3d->dda2d.ray_dir_y;
	else if (cub3d->dda3d.side == 2 || cub3d->dda3d.side == 3)
		cub3d->wall_x = cub3d->player.pos_x + cub3d->dda3d.wall_dist
			* cub3d->dda2d.ray_dir_x;
	cub3d->wall_x = cub3d->wall_x - floor(cub3d->wall_x);
	if (cub3d->texture[ind].texture == 1)
		ft_texturing_wall(cub3d, x, ind);
	else
	{
		y = cub3d->dda3d.draw_start;
		while (y < cub3d->dda3d.draw_end)
		{
			cub3d->texture[ind].color = cub3d->texture[ind].column;
			color_dist(cub3d, ind, cub3d->dda3d.wall_dist);
			draw_pix(cub3d, ind, x, y);
			y++;
		}
	}
}
