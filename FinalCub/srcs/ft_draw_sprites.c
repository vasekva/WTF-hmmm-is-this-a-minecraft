#include "cub3d.h"

void	ft_def_spr_pos(t_cub3d *cub3d, int i)
{
	double	dir_x;
	double	dir_y;
	double	plane_x;

	dir_x = cub3d->player.dir_x;
	dir_y = cub3d->player.dir_y;
	plane_x = cub3d->move.plane_x;
	cub3d->sprite.x = cub3d->spr_crds[cub3d->sprite.sprite_order[i]].x - cub3d->player.pos_x;
	cub3d->sprite.y = cub3d->spr_crds[cub3d->sprite.sprite_order[i]].y - cub3d->player.pos_y;
	cub3d->sprite.inv_det = 1.0 / (plane_x * dir_y - cub3d->move.plane_y * dir_x);
	cub3d->sprite.trans_form_x
		= cub3d->sprite.inv_det
		* (dir_y * cub3d->sprite.x - cub3d->player.dir_x * cub3d->sprite.y);
	cub3d->sprite.trans_form_y
		= cub3d->sprite.inv_det
		* (-cub3d->move.plane_y * cub3d->sprite.x + plane_x * cub3d->sprite.y);
	cub3d->sprite.sprite_screen
		= (int)((cub3d->scr_w / 2)
			* (1.0 + cub3d->sprite.trans_form_x / cub3d->sprite.trans_form_y));
}

void 	ft_def_spr_size(t_cub3d *cub3d)
{
	cub3d->sprite.height = abs((int)(cub3d->scr_h / cub3d->sprite.trans_form_y));
	cub3d->sprite.widht = abs((int)(cub3d->scr_h / cub3d->sprite.trans_form_y));
	cub3d->sprite.start_draw_y = -cub3d->sprite.height / 2 + cub3d->scr_h / 2;
	if (cub3d->sprite.start_draw_y < 0)
		cub3d->sprite.start_draw_y = 0;
	cub3d->sprite.end_draw_y = cub3d->sprite.height / 2 + cub3d->scr_h / 2;
	if (cub3d->sprite.end_draw_y >= cub3d->scr_h)
		cub3d->sprite.end_draw_y = cub3d->scr_h - 1;
	cub3d->sprite.start_draw_x = -cub3d->sprite.widht / 2 + cub3d->sprite.sprite_screen;
	if (cub3d->sprite.start_draw_x < 0)
		cub3d->sprite.start_draw_x = 0;
	cub3d->sprite.end_draw_x = cub3d->sprite.widht / 2 + cub3d->sprite.sprite_screen;
	if (cub3d->sprite.end_draw_x >= cub3d->scr_w)
		cub3d->sprite.end_draw_x = cub3d->scr_w - 1;
}

void 	ft_spr_draw(t_cub3d *cub3d, int x, int i)
{
	int	y;
	int	d;

	y = cub3d->sprite.start_draw_y;
	while (y < cub3d->sprite.end_draw_y)
	{
		d = y * 256 - (cub3d->scr_h - cub3d->sprite.height) * 128;
		cub3d->sprite.sprite_text_y = ((d * cub3d->texture[6].height) / cub3d->sprite.height) / 256;
		get_color(cub3d, 6, cub3d->sprite.sprite_text_x, cub3d->sprite.sprite_text_y);
		color_dist(cub3d, 6, cub3d->sprite.distance[i] / 4);
		if (cub3d->texture[6].color != 0x0
			&& cub3d->sprite.trans_form_y < cub3d->sprite.buf_distance[x])
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
	ft_spr_sort(cub3d->sprite.sprite_order,
		cub3d->sprite.distance, cub3d->sprite.num_of_sprites);
	i = 0;
	while (i < cub3d->sprite.num_of_sprites)
	{
		ft_def_spr_pos(cub3d, i);
		ft_def_spr_size(cub3d);
		x = cub3d->sprite.start_draw_x;
		while (x < cub3d->sprite.end_draw_x && x < cub3d->scr_w)
		{
			cub3d->sprite.sprite_text_x = (int)(256
					* (x - (-cub3d->sprite.widht / 2 + cub3d->sprite.sprite_screen))
					* cub3d->texture[6].width / cub3d->sprite.widht) / 256;
			if (cub3d->sprite.trans_form_y > 0)
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
				cub3d->spr_crds[ind].x = x + 0.5;
				cub3d->spr_crds[ind++].y = y + 0.5;
			}
			y++;
		}
		x++;
	}
	ft_spr_init(cub3d);
}
