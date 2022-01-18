#include "cub3d.h"

void		sprites(t_cub3d *cub)
{
	int x;
	int y;
	int ind;

	x = 0;
	ind = 0;
	while (x < cub->map_h)
	{
		y = 0;
		while (cub->map[x][y])
		{
			if (cub->map[x][y] == '2')
			{
				cub->c_spr[ind].x = x + 0.5;
				cub->c_spr[ind++].y = y + 0.5;
			}
			y++;
		}
		x++;
	}
//	init_sprites(cub);
	/**
	 * init_sprites(cub);
	 */
		int i;
//		int x;

//		create_sorting(cub);
		/**
		 * create_sorting(cub);
		 */
//			int i;

		i = 0;
		while (i < cub->spr.nb_sprite)
		{
			cub->spr.sp_order[i] = i;
			cub->spr.sp_dist[i] = ft_power(cub->pos_x - cub->c_spr[i].x, 2) + \
									ft_power(cub->pos_y - cub->c_spr[i].y, 2);
			i++;
		}
		/**
		 * end of create_sorting
		 */
//		sort_sprites(cub->spr.sp_order, cub->spr.sp_dist, cub->spr.nb_sprite);
		/**
		 * sort_sprites(cub->spr.sp_order, cub->spr.sp_dist, cub->spr.nb_sprite);
		 */
		int gap;
		int swapped;
//			int i;
		int j;

		swapped = 0;
		gap = cub->spr.nb_sprite;
		while (gap > 1 || swapped == 1)
		{
//				calc_gap(&gap);
			/**
			 * calc_gap(&gap);
			 */
			gap = gap * 10 / 13;
			if (gap == 9 || gap == 10)
				gap = 11;
			if (gap < 1)
				gap = 1;
			/**
			 * end of calc_gap
			 */
			swapped = 0;
			i = 0;
			while (i < cub->spr.nb_sprite - gap)
			{
				j = i + gap;
				if (cub->spr.sp_dist[i] < cub->spr.sp_dist[j])
				{
//						ft_swap_dbl(&dist[i], &dist[j]);
					/**
					 * ft_swap_dbl(&dist[i], &dist[j]);
					 */
					double d_temp;

					d_temp = cub->spr.sp_dist[i];
					cub->spr.sp_dist[i] = cub->spr.sp_dist[j];
					cub->spr.sp_dist[j] = d_temp;
					/**
					 * end of ft_swap_dbl
					 */
//						ft_swap_int(&order[i], &order[j]);
					/**
					 * ft_swap_int(&order[i], &order[j]);
					 */
					int i_temp;

					i_temp = cub->spr.sp_order[i];
					cub->spr.sp_order[i] = cub->spr.sp_order[j];
					cub->spr.sp_order[j] = i_temp;
					/**
					 * end of swap_int
					 */
					swapped = 1;
				}
				i++;
			}
		}
		/**
		 * end of sort_sprites
		 */
		i = 0;
		while (i < cub->spr.nb_sprite)
		{
//			sprite_position(cub, i);
			/**
			 * sprite_position(cub, i);
			 */
			cub->spr.sp_x = cub->c_spr[cub->spr.sp_order[i]].x - cub->pos_x;
			cub->spr.sp_y = cub->c_spr[cub->spr.sp_order[i]].y - cub->pos_y;
			cub->spr.inv_det = 1.0 / \
						(cub->plane_x * cub->dir_y - cub->plane_y * cub->dir_x);
			cub->spr.trans_x = cub->spr.inv_det * \
						(cub->dir_y * cub->spr.sp_x - cub->dir_x * cub->spr.sp_y);
			cub->spr.trans_y = cub->spr.inv_det * \
						(-cub->plane_y * cub->spr.sp_x + cub->plane_x * cub->spr.sp_y);
			cub->spr.sp_screen = (int)((cub->res_x / 2) * \
						(1.0 + cub->spr.trans_x / cub->spr.trans_y));
			/**
			 * end of sprite_position
			 */
//			sprite_dimensions(cub);
			/**
			 * sprite_dimensions(cub);
			 */
			cub->spr.sp_h = abs((int)(cub->res_y / cub->spr.trans_y));
			cub->spr.sp_w = abs((int)(cub->res_y / cub->spr.trans_y));
			cub->spr.draw_starty = -cub->spr.sp_h / 2 + cub->res_y / 2;
			if (cub->spr.draw_starty < 0)
				cub->spr.draw_starty = 0;
			cub->spr.draw_endy = cub->spr.sp_h / 2 + cub->res_y / 2;
			if (cub->spr.draw_endy >= cub->res_y)
				cub->spr.draw_endy = cub->res_y - 1;
			cub->spr.draw_startx = -cub->spr.sp_w / 2 + cub->spr.sp_screen;
			if (cub->spr.draw_startx < 0)
				cub->spr.draw_startx = 0;
			cub->spr.draw_endx = cub->spr.sp_w / 2 + cub->spr.sp_screen;
			if (cub->spr.draw_endx >= cub->res_x)
				cub->spr.draw_endx = cub->res_x - 1;
			/**
			 * end of sprite_dimensions
			 */
			x = cub->spr.draw_startx;
			while (x < cub->spr.draw_endx && x < cub->res_x)
			{
				cub->spr.tsp_x = (int)(256 * \
					(x - (-cub->spr.sp_w / 2 + cub->spr.sp_screen)) * \
					cub->tex[6].width / cub->spr.sp_w) / 256;
				if (cub->spr.trans_y > 0)
				{
//					draw_sprites(cub, x, i);
					/**
					 * draw_sprites(cub, x, i);
					 */
					int y;
					int d;

					y = cub->spr.draw_starty;
					while (y < cub->spr.draw_endy)
					{
						d = y * 256 - (cub->res_y - cub->spr.sp_h) * 128;
						cub->spr.tsp_y = ((d * cub->tex[6].height) / cub->spr.sp_h) / 256;
//							get_color(cub, 6, cub->spr.tsp_x, cub->spr.tsp_y);
						/**
						 * get_color(cub, 6, cub->spr.tsp_x, cub->spr.tsp_y);
						 */
						if (cub->spr.tsp_x >= 0 && cub->spr.tsp_x < cub->tex[6].width && cub->spr.tsp_y >= 0 && cub->spr.tsp_y < cub->tex[6].height)
						{
							cub->tex[6].color = \
									*(int*)(cub->tex[6].tex_ptr + \
									(cub->spr.tsp_x * cub->tex[6].bit_pix / 8 + cub->spr.tsp_y * cub->tex[6].size_line));
						}
						else
							cub->tex[6].color = 0x0;
						/**
						 * end of get_color
						 */
//							color_dist(cub, 6, cub->spr.sp_dist[i] / 4);
						/**
						 * color_dist(cub, 6, cub->spr.sp_dist[i] / 4);
						 */
						if (cub->spr.sp_dist[i] / 4 > 2.0)
						{
							cub->tex[6].color = \
									(((int)(((cub->tex[6].color & 0xFF0000) >> 16) / (cub->spr.sp_dist[i] / 4 / 2.0)) << 16) |
									 ((int)(((cub->tex[6].color & 0x00FF00) >> 8) / (cub->spr.sp_dist[i] / 4 / 2.0)) << 8) |
									 (int)((cub->tex[6].color & 0x0000FF) / (cub->spr.sp_dist[i] / 4 / 2.0)));
						}
						/**
						 * end of color_dist
						 */
						if (cub->tex[6].color != 0x0 \
								&& cub->spr.trans_y < cub->spr.distbuf[x])
						{
//								draw_pix(cub, 6, x, y);
							/**
							 * draw_pix(cub, 6, x, y);
							 */
							if (x >= 0 && x < cub->res_x && y >= 0 && y < cub->res_y)
								*(int*)(cub->img_ptr + (cub->res_x * y + x) * cub->bit_pix / 8) = \
										cub->tex[6].color;
							/**
							 * end of draw_pix
							 */
						}
						y++;
					}
					/**
					 * end of draw_sprites
					 */
				}
				x++;
			}
			i++;
		}
	/**
	 * end of init_sprites
	 */
}
