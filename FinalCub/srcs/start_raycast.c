#include "cub3d.h"

static void	ft_vector_init(t_cub3d *cub3d, int x)
{
	double	camera_x;

	camera_x = (double)(2 * x / (double)cub3d->scr_w) - 1;
	cub3d->dda2d.ray_dir_x
		= cub3d->player.dir_x + cub3d->move.plane_x * camera_x;
	cub3d->dda2d.ray_dir_y
		= cub3d->player.dir_y + cub3d->move.plane_y * camera_x;
	cub3d->dda2d.map_x = cub3d->player.pos_x;
	cub3d->dda2d.map_y = cub3d->player.pos_y;
	cub3d->dda2d.delta_dx = fabs(1 / cub3d->dda2d.ray_dir_x);
	cub3d->dda2d.delta_dy = fabs(1 / cub3d->dda2d.ray_dir_y);
}

static void	ft_init_steps_dda(t_cub3d *cub3d, double dx, double dy)
{
	dx = cub3d->dda2d.delta_dx;
	dy = cub3d->dda2d.delta_dy;
	if (cub3d->dda2d.ray_dir_x < 0)
	{
		cub3d->dda2d.step_x = -1;
		cub3d->dda2d.side_dx = (cub3d->player.pos_x - cub3d->dda2d.map_x) * dx;
	}
	else
	{
		cub3d->dda2d.step_x = 1;
		cub3d->dda2d.side_dx
			= (cub3d->dda2d.map_x + 1.0 - cub3d->player.pos_x) * dx;
	}
	if (cub3d->dda2d.ray_dir_y < 0)
	{
		cub3d->dda2d.step_y = -1;
		cub3d->dda2d.side_dy = (cub3d->player.pos_y - cub3d->dda2d.map_y) * dy;
	}
	else
	{
		cub3d->dda2d.step_y = 1;
		cub3d->dda2d.side_dy
			= (cub3d->dda2d.map_y + 1.0 - cub3d->player.pos_y) * dy;
	}
}

static void	ft_found_walls(t_cub3d *cub3d, int hit)
{
	while (hit == 0)
	{
		if (cub3d->dda2d.side_dx < cub3d->dda2d.side_dy)
		{
			cub3d->dda2d.side_dx = cub3d->dda2d.side_dx + cub3d->dda2d.delta_dx;
			cub3d->dda2d.map_x = cub3d->dda2d.map_x + cub3d->dda2d.step_x;
			if (cub3d->dda2d.step_x > 0)
				cub3d->dda3d.side = 0;
			else
				cub3d->dda3d.side = 1;
		}
		else if (cub3d->dda2d.side_dx >= cub3d->dda2d.side_dy)
		{
			cub3d->dda2d.side_dy = cub3d->dda2d.side_dy + cub3d->dda2d.delta_dy;
			cub3d->dda2d.map_y = cub3d->dda2d.map_y + cub3d->dda2d.step_y;
			if (cub3d->dda2d.step_y > 0)
				cub3d->dda3d.side = 2;
			else
				cub3d->dda3d.side = 3;
		}
		if (cub3d->map[cub3d->dda2d.map_x][cub3d->dda2d.map_y] == '1')
			hit = 1;
	}
}

static void 	ft_calc_distance(t_cub3d *cub3d)
{
	if (cub3d->dda3d.side == 0 || cub3d->dda3d.side == 1)
		cub3d->dda3d.wall_dist
			= (cub3d->dda2d.map_x - cub3d->player.pos_x
				+ (1 - cub3d->dda2d.step_x) / 2) / cub3d->dda2d.ray_dir_x;
	else if (cub3d->dda3d.side == 2 || cub3d->dda3d.side == 3)
		cub3d->dda3d.wall_dist
			= (cub3d->dda2d.map_y - cub3d->player.pos_y
				+ (1 - cub3d->dda2d.step_y) / 2) / cub3d->dda2d.ray_dir_y;
	cub3d->dda3d.line_h = (int)(cub3d->scr_h / cub3d->dda3d.wall_dist);
	cub3d->dda3d.draw_start = -cub3d->dda3d.line_h / 2 + cub3d->scr_h / 2;
	if (cub3d->dda3d.draw_start < 0)
		cub3d->dda3d.draw_start = 0;
	cub3d->dda3d.draw_end = cub3d->dda3d.line_h / 2 + cub3d->scr_h / 2;
	if (cub3d->dda3d.draw_end >= cub3d->scr_h)
		cub3d->dda3d.draw_end = cub3d->scr_h - 1;
}

void	start_raycast(t_cub3d *cub3d)
{
	int	x;

	x = 0;
	while (x < cub3d->scr_w)
	{
		ft_vector_init(cub3d, x);
		ft_init_steps_dda(cub3d, 0, 0);
		ft_found_walls(cub3d, 0);
		ft_calc_distance(cub3d);
		draw_all(cub3d, x);
		cub3d->sprite.buf_distance[x] = cub3d->dda3d.wall_dist;
		x++;
	}
	ft_draw_sprites(cub3d);
}
