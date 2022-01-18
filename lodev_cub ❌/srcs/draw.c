#include "cub3d.h"

void	draw_all(t_cub3d *cub, int x)
{
//	draw_walls(cub, x);
	/**
	 * draw_walls(cub, x);
	 */
	 	/**
	 	 * define_tex_wall(cub);
	 	 */
			int ind;

			ind = 0;
			if (cub->side == 0)
				ind = 0;
			else if (cub->side == 1)
				ind = 1;
			else if (cub->side == 2)
				ind = 2;
			else if (cub->side == 3)
				ind = 3;
		/**
		 * end of define_tex_wall
		 */
		if (cub->side == 0 || cub->side == 1)
			cub->wall_x = cub->pos_y + cub->wall_dist * cub->raydir_y;
		else if (cub->side == 2 || cub->side == 3)
			cub->wall_x = cub->pos_x + cub->wall_dist * cub->raydir_x;
		cub->wall_x = cub->wall_x - floor(cub->wall_x);
		if (cub->tex[ind].texture == 1)
		{
//			set_tex_coor(cub, x, ind);
			/**
			 * sex_tex_coor(cub, x, ind);
			 */
				int y;

				cub->x_coor = (int)(cub->wall_x * (double)(cub->tex[ind].width));
				if ((cub->side == 0 || cub->side == 1) && cub->raydir_x > 0)
					cub->x_coor = cub->tex[ind].width - cub->x_coor - 1;
				if ((cub->side == 2 || cub->side == 3) && cub->raydir_y < 0)
					cub->x_coor = cub->tex[ind].width - cub->x_coor - 1;
				cub->x_coor = abs(cub->x_coor);
				y = cub->draw_start;
				while (y < cub->draw_end)
				{
					cub->y_coor = y * 256 - cub->res_y * 128 + cub->line_h * 128;
					cub->y_coor = cub->y_coor * cub->tex[ind].height / cub->line_h / 256;
					get_color(cub, ind, cub->x_coor, cub->y_coor);
					color_dist(cub, ind, cub->wall_dist);
					draw_pix(cub, ind, x, y);
					y++;
				}
			/**
			 * end of sex_tex_coor
			 */
		}
		else
		{
//			draw_color(cub, x, ind);
			int y;

			y = cub->draw_start;
			while (y < cub->draw_end)
			{
				cub->tex[ind].color = cub->tex[ind].col;
				color_dist(cub, ind, cub->wall_dist);
				draw_pix(cub, ind, x, y);
				y++;
			}
			/**
			 * draw_color(cub, x, ind);
			 */

			/**
			 * end of draw_color(cub, x, ind)
			 */
		}
	/**
	 * end of draw_walls
	 */
//	draw_floor(cub, x);
	/**
	 * draw_floor(cub, x);
	 */
		int y;

//		def_floor_side(cub);
		/**
		 * def_floor_side(cub);
		 */
			if (cub->side == 0)
			{
				cub->flr.fl_x_wall = cub->map_x;
				cub->flr.fl_y_wall = cub->map_y + cub->wall_x;
			}
			else if (cub->side == 1)
			{
				cub->flr.fl_x_wall = cub->map_x + 1.0;
				cub->flr.fl_y_wall = cub->map_y + cub->wall_x;
			}
			else if (cub->side == 2)
			{
				cub->flr.fl_x_wall = cub->map_x + cub->wall_x;
				cub->flr.fl_y_wall = cub->map_y;
			}
			else if (cub->side == 3)
			{
				cub->flr.fl_x_wall = cub->map_x + cub->wall_x;
				cub->flr.fl_y_wall = cub->map_y + 1.0;
			}
		/**
		 * end of def_floor_side(cub)
		 */
		if (cub->draw_end < 0)
			cub->draw_end = cub->res_y;
		y = cub->draw_end;
		while (y < cub->res_y)
		{
			cub->flr.cur_dist = cub->res_y / (2.0 * y - cub->res_y);
			if (cub->tex[4].texture == 1)
			{
//				set_tex_coor(cub, 4);
				/**
				 * set_tex_coor(cub, 4);
				 */
					cub->flr.weight = cub->flr.cur_dist / cub->wall_dist;
					cub->flr.cur_fl_x = cub->flr.weight * cub->flr.fl_x_wall \
							+ (1.0 - cub->flr.weight) * cub->pos_x;
					cub->flr.cur_fl_y = cub->flr.weight * cub->flr.fl_y_wall \
							+ (1.0 - cub->flr.weight) * cub->pos_y;
					cub->flr.fl_tex_x = (int)(cub->flr.cur_fl_x * cub->tex[4].width) \
							% cub->tex[4].width;
					cub->flr.fl_tex_y = (int)(cub->flr.cur_fl_y * cub->tex[4].height) \
								% cub->tex[4].height;
				/**
				 * end of sex_tex_coor
				 */
//				get_color(cub, 4, cub->flr.fl_tex_x, cub->flr.fl_tex_y);
				/**
				 * get_color(cub, 4, cub->flr.fl_tex_x, cub->flr.fl_tex_y);
				 */
					if (cub->flr.fl_tex_x >= 0 && cub->flr.fl_tex_x < cub->tex[4].width && cub->flr.fl_tex_y >= 0 && cub->flr.fl_tex_y < cub->tex[4].height)
					{
						cub->tex[4].color = \
						*(int*)(cub->tex[4].tex_ptr + \
						(cub->flr.fl_tex_x * cub->tex[4].bit_pix / 8 + cub->flr.fl_tex_y * cub->tex[4].size_line));
					}
					else
						cub->tex[4].color = 0x0;
				/**
				 * end of get_color
				 */
			}
			else
				cub->tex[4].color = cub->tex[4].col;
//			color_dist(cub, 4, cub->flr.cur_dist);
			/**
			 * color_dist(cub, 4, cub->flr.cur_dist);
			 */
				if (cub->flr.cur_dist > 2.0)
				{
					cub->tex[4].color = \
					(((int)(((cub->tex[4].color & 0xFF0000) >> 16) / (cub->flr.cur_dist / 2.0)) << 16) |
					((int)(((cub->tex[4].color & 0x00FF00) >> 8) / (cub->flr.cur_dist / 2.0)) << 8) |
					 (int)((cub->tex[4].color & 0x0000FF) / (cub->flr.cur_dist / 2.0)));
				}
			/**
			 * end of color_dist
			 */
//			draw_pix(cub, 4, x, y);
			/**
			 * draw_pix(cub, 4, x, y);
			 */
			if (x >= 0 && x < cub->res_x && y >= 0 && y < cub->res_y)
				*(int*)(cub->img_ptr + (cub->res_x * y + x) * cub->bit_pix / 8) = \
				cub->tex[4].color;
			/**
			 * end of draw_pix
			 */
			y++;
		}
	/**
	 * end of draw_floor
	 */
	if (cub->tex[5].tex_path \
	&& !ft_strncmp(cub->tex[5].tex_path, "textures/c_sky", 12))
	{
//		draw_sky(cub, x);
		/**
		 * draw_sky(cub, x);
		 */
			int y;
			int skytex;

			y = 0;
			while (y < cub->draw_start)
			{
				skytex = \
			abs((int)(x - cub->tex[5].width * (M_PI / 2) \
			* atan(cub->dir_y / (cub->dir_x + 0.01))) \
			* cub->tex[5].bit_pix / 8 \
			+ y * cub->tex[5].size_line);
				cub->tex[5].color = *(int*)(cub->tex[5].tex_ptr + skytex);
				{
//					draw_pix(cub, 5, x, y);
					/**
					 * draw_pix(cub, 5, x, y);
					 */
						if (x >= 0 && x < cub->res_x && y >= 0 && y < cub->res_y)
							*(int*)(cub->img_ptr + (cub->res_x * y + x) * cub->bit_pix / 8) = \
							cub->tex[5].color;
					/**
					 * end of draw_pix
					 */
				}
				y++;
			}
		/**
		 * end of draw_sky
		 */
	}
	else
	{
//		draw_ceiling(cub, x);
		/**
		 * draw_ceiling(cub, x);
		 */
			int y;

			y = 0;
			while (y < cub->draw_start)
			{
				cub->flr.cur_dist = -cub->res_y / (2.0 * y - cub->res_y);
				if (cub->tex[5].texture == 1)
				{
//					set_tex_coor(cub, 5);
					/**
					 * set_tex_coor(cub, 5);
					 */
						cub->flr.weight = cub->flr.cur_dist / cub->wall_dist;
						cub->flr.cur_fl_x = cub->flr.weight * cub->flr.fl_x_wall \
							+ (1.0 - cub->flr.weight) * cub->pos_x;
						cub->flr.cur_fl_y = cub->flr.weight * cub->flr.fl_y_wall \
							+ (1.0 - cub->flr.weight) * cub->pos_y;
						cub->flr.fl_tex_x = (int)(cub->flr.cur_fl_x * cub->tex[5].width) \
							% cub->tex[5].width;
						cub->flr.fl_tex_y = (int)(cub->flr.cur_fl_y * cub->tex[5].height) \
								% cub->tex[5].height;
					/**
					 * end of sex_tex_coor
					 */
//					get_color(cub, 5, cub->flr.fl_tex_x, cub->flr.fl_tex_y);
					/**
					 * get_color(cub, 5, cub->flr.fl_tex_x, cub->flr.fl_tex_y);
					 */
						if (cub->flr.fl_tex_x >= 0 && cub->flr.fl_tex_x < cub->tex[5].width && cub->flr.fl_tex_y >= 0 && cub->flr.fl_tex_y < cub->tex[5].height)
						{
							cub->tex[5].color = \
							*(int*)(cub->tex[5].tex_ptr + \
							(cub->flr.fl_tex_x * cub->tex[5].bit_pix / 8 + cub->flr.fl_tex_y * cub->tex[5].size_line));
						}
						else
								cub->tex[5].color = 0x0;
					/**
					 * end of get_color
					 */
				}
				else
					cub->tex[5].color = cub->tex[5].col;
//				color_dist(cub, 5, cub->flr.cur_dist);
				/**
				 * color_dist(cub, 5, cub->flr.cur_dist);
				 */
				if (cub->flr.cur_dist > 2.0)
				{
					cub->tex[5].color = \
					(((int)(((cub->tex[5].color & 0xFF0000) >> 16) / (cub->flr.cur_dist / 2.0)) << 16) |
					 ((int)(((cub->tex[5].color & 0x00FF00) >> 8) / (cub->flr.cur_dist / 2.0)) << 8) |
		 			(int)((cub->tex[5].color & 0x0000FF) / (cub->flr.cur_dist / 2.0)));
				}
				/**
				 * end of color_dist
				 */
//				draw_pix(cub, 5, x, y);
				/**
				 * draw_pix(cub, 5, x, y);
				 */
				if (x >= 0 && x < cub->res_x && y >= 0 && y < cub->res_y)
					*(int*)(cub->img_ptr + (cub->res_x * y + x) * cub->bit_pix / 8) = \
					cub->tex[5].color;
				/**
				 * end of draw_pix
				 */
				y++;
			}
		/**
		 * end of draw_ceiling
		 */
	}
}
