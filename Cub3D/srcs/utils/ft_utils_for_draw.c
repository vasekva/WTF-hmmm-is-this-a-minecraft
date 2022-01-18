#include "cub3d.h"

void	ft_set_tex_coor(t_cub3d *cub3d, int i)
{
	cub3d->floor.weight = cub3d->floor.distance / cub3d->dda3d.wall_dist;
	cub3d->floor.x
		= cub3d->floor.weight * cub3d->floor.wall_x
		+ (1.0 - cub3d->floor.weight) * cub3d->player.pos_x;
	cub3d->floor.y
		= cub3d->floor.weight * cub3d->floor.wall_y
		+ (1.0 - cub3d->floor.weight) * cub3d->player.pos_y;
	cub3d->floor.texture_x
		= (int)(cub3d->floor.x * cub3d->texture[5].width)
		% cub3d->texture[5].width;
	cub3d->floor.texture_y = (int)(cub3d->floor.y * cub3d->texture[5].height)
		% cub3d->texture[5].height;
}

void	get_color(t_cub3d *cub3d, int ind, int x, int y)
{
	if (x >= 0 && x < cub3d->texture[ind].width
		&& y >= 0 && y < cub3d->texture[ind].height)
	{
		cub3d->texture[ind].color
			= *(int *)(cub3d->texture[ind].ptr_texture
				+ (x * cub3d->texture[ind].bits_per_pixel
					/ 8 + y * cub3d->texture[ind].line_length));
	}
	else
		cub3d->texture[ind].color = 0x0;
}

void	color_dist(t_cub3d *cub3d, int ind, double dis)
{
	int	r;
	int	g;
	int	b;

	r = cub3d->texture[ind].color & 0xFF0000;
	g = cub3d->texture[ind].color & 0x00FF00;
	b = cub3d->texture[ind].color & 0x0000FF;
	if (dis > 2.0)
	{
		cub3d->texture[ind].color
			= (((int)(((r) >> 16) / (dis / 2.0)) << 16)
				| ((int)(((g) >> 8) / (dis / 2.0)) << 8)
				| (int)((b) / (dis / 2.0)));
	}
}

void	draw_pix(t_cub3d *cub3d, int ind, int x, int y)
{
	if (x >= 0 && x < cub3d->scr_w && y >= 0 && y < cub3d->scr_h)
		*(int *)(cub3d->mlx->p_img + (cub3d->scr_w * y + x)
				* cub3d->mlx->bits_per_pixel / 8)
			= cub3d->texture[ind].color;
}
