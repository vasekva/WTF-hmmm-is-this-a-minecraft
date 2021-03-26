#include "cub3d.h"

void	ft_set_tex_coor(t_cub3d *cub3d, int i)
{
	cub3d->flr.weight = cub3d->flr.cur_dist / cub3d->wall_dist;
	cub3d->flr.cur_fl_x
		= cub3d->flr.weight * cub3d->flr.fl_x_wall
		+ (1.0 - cub3d->flr.weight) * cub3d->pos_x;
	cub3d->flr.cur_fl_y
		= cub3d->flr.weight * cub3d->flr.fl_y_wall
		+ (1.0 - cub3d->flr.weight) * cub3d->pos_y;
	cub3d->flr.fl_tex_x
		= (int)(cub3d->flr.cur_fl_x * cub3d->tex[5].width)
		% cub3d->tex[5].width;
	cub3d->flr.fl_tex_y = (int)(cub3d->flr.cur_fl_y * cub3d->tex[5].height)
		% cub3d->tex[5].height;
}

void	get_color(t_cub3d *cub, int ind, int x, int y)
{
	if (x >= 0 && x < cub->tex[ind].width && y >= 0 && y < cub->tex[ind].height)
	{
		cub->tex[ind].color
			= *(int *)(cub->tex[ind].tex_ptr
				+ (x * cub->tex[ind].bit_pix
					/ 8 + y * cub->tex[ind].size_line));
	}
	else
		cub->tex[ind].color = 0x0;
}

void	color_dist(t_cub3d *cub, int ind, double dis)
{
	int	r;
	int	g;
	int	b;

	r = cub->tex[ind].color & 0xFF0000;
	g = cub->tex[ind].color & 0x00FF00;
	b = cub->tex[ind].color & 0x0000FF;
	if (dis > 2.0)
	{
		cub->tex[ind].color
			= (((int)(((r) >> 16) / (dis / 2.0)) << 16)
				| ((int)(((g) >> 8) / (dis / 2.0)) << 8)
				| (int)((b) / (dis / 2.0)));
	}
}

void	draw_pix(t_cub3d *cub3d, int ind, int x, int y)
{
	if (x >= 0 && x < cub3d->res_x && y >= 0 && y < cub3d->res_y)
		*(int *)(cub3d->mlx->img_ptr + (cub3d->res_x * y + x)
				* cub3d->mlx->bit_pix / 8)
			= cub3d->tex[ind].color;
}
