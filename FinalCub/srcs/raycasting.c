#include "cub3d.h"

void	ft_vector_init(t_cub3d *cub3d, int x)
{
	double	camera_x;

	camera_x = (double)(2 * x / (double)cub3d->scr_w) - 1;
	cub3d->raydir_x = cub3d->player.dir_x + cub3d->plane_x * camera_x;
	cub3d->raydir_y = cub3d->player.dir_y + cub3d->plane_y * camera_x;
	cub3d->map_x = cub3d->player.pos_x;
	cub3d->map_y = cub3d->player.pos_y;
	cub3d->delta_dx = fabs(1 / cub3d->raydir_x);
	cub3d->delta_dy = fabs(1 / cub3d->raydir_y);
}

void	ft_init_steps_dda(t_cub3d *cub3d)
{
	if (cub3d->raydir_x < 0)
	{
		cub3d->step_x = -1;
		cub3d->side_dx = (cub3d->player.pos_x - cub3d->map_x) * cub3d->delta_dx;
	}
	else
	{
		cub3d->step_x = 1;
		cub3d->side_dx = (cub3d->map_x + 1.0 - cub3d->player.pos_x) * cub3d->delta_dx;
	}
	if (cub3d->raydir_y < 0)
	{
		cub3d->step_y = -1;
		cub3d->side_dy = (cub3d->player.pos_y - cub3d->map_y) * cub3d->delta_dy;
	}
	else
	{
		cub3d->step_y = 1;
		cub3d->side_dy = (cub3d->map_y + 1.0 - cub3d->player.pos_y) * cub3d->delta_dy;
	}
}

void	ft_found_walls(t_cub3d *cub3d)
{
	int	hit;

	hit = 0;
//	cub3d->wall_hit = 0;
	while (hit == 0)
	{
		if (cub3d->side_dx < cub3d->side_dy)
		{
			cub3d->side_dx = cub3d->side_dx + cub3d->delta_dx;
			cub3d->map_x = cub3d->map_x + cub3d->step_x;
			if (cub3d->step_x > 0)
				cub3d->side = 0;
			else
				cub3d->side = 1;
		}
		else if (cub3d->side_dx >= cub3d->side_dy)
		{
			cub3d->side_dy = cub3d->side_dy + cub3d->delta_dy;
			cub3d->map_y = cub3d->map_y + cub3d->step_y;
			if (cub3d->step_y > 0)
				cub3d->side = 2;
			else
				cub3d->side = 3;
		}
		if (cub3d->map[cub3d->map_x][cub3d->map_y] == '1')
			hit = 1;
	}
}

void 	ft_calc_distance(t_cub3d *cub3d)
{
	if (cub3d->side == 0 || cub3d->side == 1)
		cub3d->wall_dist
			= (cub3d->map_x - cub3d->player.pos_x
				+ (1 - cub3d->step_x) / 2) / cub3d->raydir_x;
	else if (cub3d->side == 2 || cub3d->side == 3)
		cub3d->wall_dist
			= (cub3d->map_y - cub3d->player.pos_y
				+ (1 - cub3d->step_y) / 2) / cub3d->raydir_y;
	cub3d->line_h = (int)(cub3d->scr_h / cub3d->wall_dist);
	cub3d->draw_start = -cub3d->line_h / 2 + cub3d->scr_h / 2;
	if (cub3d->draw_start < 0)
		cub3d->draw_start = 0;
	cub3d->draw_end = cub3d->line_h / 2 + cub3d->scr_h / 2;
	if (cub3d->draw_end >= cub3d->scr_h)
		cub3d->draw_end = cub3d->scr_h - 1;
}

void	raycasting(t_cub3d *cub3d)
{
	int	x;

	x = 0;
	while (x < cub3d->scr_w)
	{
		ft_vector_init(cub3d, x);
		ft_init_steps_dda(cub3d);
		ft_found_walls(cub3d);
		ft_calc_distance(cub3d);
		draw_all(cub3d, x);
		cub3d->spr.distbuf[x] = cub3d->wall_dist;
		x++;
	}
	 ft_draw_sprites(cub3d);
}
