#include "cub3d.h"

void		raycasting(t_cub3d *cub)
{
	int x;

	x = 0;
	while (x < cub->res_x)
	{
//		init_vectors(cub, x);
		/**
		 * init_vectors(cub,x);
		 */
			cub->cam_plane = (double)(2 * x / (double)cub->res_x) - 1;
			cub->raydir_x = cub->dir_x + cub->plane_x * cub->cam_plane;
			cub->raydir_y = cub->dir_y + cub->plane_y * cub->cam_plane;
			cub->map_x = cub->pos_x;
			cub->map_y = cub->pos_y;
			cub->delta_dx = fabs(1 / cub->raydir_x);
			cub->delta_dy = fabs(1 / cub->raydir_y);
		/**
		 * end of init_vectors
		 */
//		init_dda(cub);
		/**
		 * init_dda(cub);
		 */
			if (cub->raydir_x < 0)
			{
				cub->step_x = -1;
				cub->side_dx = (cub->pos_x - cub->map_x) * cub->delta_dx;
			}
			else
			{
				cub->step_x = 1;
				cub->side_dx = (cub->map_x + 1.0 - cub->pos_x) * cub->delta_dx;
			}
			if (cub->raydir_y < 0)
			{
				cub->step_y = -1;
				cub->side_dy = (cub->pos_y - cub->map_y) * cub->delta_dy;
			}
			else
			{
				cub->step_y = 1;
				cub->side_dy = (cub->map_y + 1.0 - cub->pos_y) * cub->delta_dy;
			}
		/**
		 * end of init_dda
		 */
//		dda(cub);
		/**
		 * dda(cub);
		 */
			cub->wall_hit = 0;
			while (cub->wall_hit == 0)
			{
				if (cub->side_dx < cub->side_dy)
				{
					cub->side_dx = cub->side_dx + cub->delta_dx;
					cub->map_x = cub->map_x + cub->step_x;
					if (cub->step_x > 0)
						cub->side = 0;
					else
						cub->side = 1;
				}
				else if (cub->side_dx >= cub->side_dy)
				{
					cub->side_dy = cub->side_dy + cub->delta_dy;
					cub->map_y = cub->map_y + cub->step_y;
					if (cub->step_y > 0)
						cub->side = 2;
					else
						cub->side = 3;
				}
				if (cub->map[cub->map_x][cub->map_y] == '1')
					cub->wall_hit = 1;
			}
		/**
		 * end of dda
		 */
//		casting(cub);
		/**
		 * casting(cub);
		 */
			if (cub->side == 0 || cub->side == 1)
				cub->wall_dist = (cub->map_x - cub->pos_x \
							+ (1 - cub->step_x) / 2) / cub->raydir_x;
			else if (cub->side == 2 || cub->side == 3)
				cub->wall_dist = (cub->map_y - cub->pos_y \
							+ (1 - cub->step_y) / 2) / cub->raydir_y;
			cub->line_h = (int)(cub->res_y / cub->wall_dist);
			cub->draw_start = -cub->line_h / 2 + cub->res_y / 2;
			if (cub->draw_start < 0)
				cub->draw_start = 0;
			cub->draw_end = cub->line_h / 2 + cub->res_y / 2;
			if (cub->draw_end >= cub->res_y)
				cub->draw_end = cub->res_y - 1;
		/**
		 * end of casting
		 */
		draw_all(cub, x); // draw.c
		cub->spr.distbuf[x] = cub->wall_dist;
		x++;
	}
	sprites(cub);
}
