#include "cub3d.h"

void	ft_def_spr_pos(t_cub3d *cub3d, int i)
{
	double	dir_x;
	double	dir_y;
	double	plane_x;

	dir_x = cub3d->player.dir_x;
	dir_y = cub3d->player.dir_y;
	plane_x = cub3d->plane_x;
	cub3d->spr.sp_x = cub3d->c_spr[cub3d->spr.sp_order[i]].x - cub3d->player.pos_x;
	cub3d->spr.sp_y = cub3d->c_spr[cub3d->spr.sp_order[i]].y - cub3d->player.pos_y;
	cub3d->spr.inv_det = 1.0 / (plane_x * dir_y - cub3d->plane_y * dir_x);
	cub3d->spr.trans_x
		= cub3d->spr.inv_det
		* (dir_y * cub3d->spr.sp_x - cub3d->player.dir_x * cub3d->spr.sp_y);
	cub3d->spr.trans_y
		= cub3d->spr.inv_det
		* (-cub3d->plane_y * cub3d->spr.sp_x + plane_x * cub3d->spr.sp_y);
	cub3d->spr.sp_screen
		= (int)((cub3d->scr_w / 2)
			* (1.0 + cub3d->spr.trans_x / cub3d->spr.trans_y));
}

void 	ft_def_spr_size(t_cub3d *cub3d)
{
	cub3d->spr.sp_h = abs((int)(cub3d->scr_h / cub3d->spr.trans_y));
	cub3d->spr.sp_w = abs((int)(cub3d->scr_h / cub3d->spr.trans_y));
	cub3d->spr.draw_starty = -cub3d->spr.sp_h / 2 + cub3d->scr_h / 2;
	if (cub3d->spr.draw_starty < 0)
		cub3d->spr.draw_starty = 0;
	cub3d->spr.draw_endy = cub3d->spr.sp_h / 2 + cub3d->scr_h / 2;
	if (cub3d->spr.draw_endy >= cub3d->scr_h)
		cub3d->spr.draw_endy = cub3d->scr_h - 1;
	cub3d->spr.draw_startx = -cub3d->spr.sp_w / 2 + cub3d->spr.sp_screen;
	if (cub3d->spr.draw_startx < 0)
		cub3d->spr.draw_startx = 0;
	cub3d->spr.draw_endx = cub3d->spr.sp_w / 2 + cub3d->spr.sp_screen;
	if (cub3d->spr.draw_endx >= cub3d->scr_w)
		cub3d->spr.draw_endx = cub3d->scr_w - 1;
}

void 	ft_spr_draw(t_cub3d *cub3d, int x, int i)
{
	int	y;
	int	d;

	y = cub3d->spr.draw_starty;
	while (y < cub3d->spr.draw_endy)
	{
		d = y * 256 - (cub3d->scr_h - cub3d->spr.sp_h) * 128;
		cub3d->spr.tsp_y = ((d * cub3d->tex[6].height) / cub3d->spr.sp_h) / 256;
		get_color(cub3d, 6, cub3d->spr.tsp_x, cub3d->spr.tsp_y);
		color_dist(cub3d, 6, cub3d->spr.sp_dist[i] / 4);
		if (cub3d->tex[6].color != 0x0
			&& cub3d->spr.trans_y < cub3d->spr.distbuf[x])
		{
			draw_pix(cub3d, 6, x, y);
		}
		y++;
	}
}

void	ft_spr_init(t_cub3d *cub3d)
{
	int	i;
	int	x;

	ft_def_spr_dist(cub3d);
	ft_spr_sort(cub3d->spr.sp_order,
		cub3d->spr.sp_dist, cub3d->spr.nb_sprite);
	i = 0;
	while (i < cub3d->spr.nb_sprite)
	{
		ft_def_spr_pos(cub3d, i);
		ft_def_spr_size(cub3d);
		x = cub3d->spr.draw_startx;
		while (x < cub3d->spr.draw_endx && x < cub3d->scr_w)
		{
			cub3d->spr.tsp_x = (int)(256
					* (x - (-cub3d->spr.sp_w / 2 + cub3d->spr.sp_screen))
					* cub3d->tex[6].width / cub3d->spr.sp_w) / 256;
			if (cub3d->spr.trans_y > 0)
			{
				ft_spr_draw(cub3d, x, i);
			}
			x++;
		}
		i++;
	}
}

void	ft_draw_sprites(t_cub3d *cub3d)
{
	int	x;
	int	y;
	int	ind;

	x = 0;
	ind = 0;
	while (x < cub3d->map_h)
	{
		y = 0;
		while (cub3d->map[x][y])
		{
			if (cub3d->map[x][y] == '2')
			{
				cub3d->c_spr[ind].x = x + 0.5;
				cub3d->c_spr[ind++].y = y + 0.5;
			}
			y++;
		}
		x++;
	}
	ft_spr_init(cub3d);
}
