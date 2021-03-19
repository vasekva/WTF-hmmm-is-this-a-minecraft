#include "cub3d.h"

void	get_color(t_cub3d *cub, int ind, int x, int y)
{
	if (x >= 0 && x < cub->tex[ind].width && y >= 0 && y < cub->tex[ind].height)
	{
		cub->tex[ind].color = \
		*(int*)(cub->tex[ind].tex_ptr + \
		(x * cub->tex[ind].bit_pix / 8 + y * cub->tex[ind].size_line));
	}
	else
		cub->tex[ind].color = 0x0;
}

void	color_dist(t_cub3d *cub, int ind, double dis)
{
	if (dis > 2.0)
	{
		cub->tex[ind].color = \
		(((int)(((cub->tex[ind].color & 0xFF0000) >> 16) / (dis / 2.0)) << 16) |
		((int)(((cub->tex[ind].color & 0x00FF00) >> 8) / (dis / 2.0)) << 8) |
		(int)((cub->tex[ind].color & 0x0000FF) / (dis / 2.0)));
	}
}

void	draw_pix(t_cub3d *cub, int ind, int x, int y)
{
	if (x >= 0 && x < cub->res_x && y >= 0 && y < cub->res_y)
		*(int*)(cub->img_ptr + (cub->res_x * y + x) * cub->bit_pix / 8) = \
		cub->tex[ind].color;
}
