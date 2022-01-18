#include "cub3d.h"

int			motion(t_cub3d *cub)
{
//	move(cub);
	/**
	 * move(cub);
	 */
		if (cub->act.up == 1)
		{
			if (cub->map[(int)(cub->pos_x + cub->dir_x * cub->act.m_speed)]\
						[(int)(cub->pos_y)] == '0')
				cub->pos_x += cub->dir_x * cub->act.m_speed;
			if (cub->map[(int)(cub->pos_x)]\
						[(int)(cub->pos_y + cub->dir_y * cub->act.m_speed)] == '0')
				cub->pos_y += cub->dir_y * cub->act.m_speed;
		}
		if (cub->act.down == 1)
		{
			if (cub->map[(int)(cub->pos_x - cub->dir_x * cub->act.m_speed)]\
						[(int)(cub->pos_y)] == '0')
				cub->pos_x -= cub->dir_x * cub->act.m_speed;
			if (cub->map[(int)(cub->pos_x)]\
						[(int)(cub->pos_y - cub->dir_y * cub->act.m_speed)] == '0')
				cub->pos_y -= cub->dir_y * cub->act.m_speed;
		}
	/**
	 * end of move
	 */
//	move_side(cub);
	/**
	 * move_side(cub);
	 */
		if (cub->act.m_left == 1)
		{
			if (cub->map[(int)(cub->pos_x - cub->dir_y * cub->act.m_speed)]\
						[(int)(cub->pos_y)] == '0')
				cub->pos_x -= cub->dir_y * cub->act.m_speed;
			if (cub->map[(int)(cub->pos_x)]\
						[(int)(cub->pos_y + cub->dir_x * cub->act.m_speed)] == '0')
				cub->pos_y += cub->dir_x * cub->act.m_speed;
		}
		if (cub->act.m_right == 1)
		{
			if (cub->map[(int)(cub->pos_x + cub->dir_y * cub->act.m_speed)]\
						[(int)(cub->pos_y)] == '0')
				cub->pos_x += cub->dir_y * cub->act.m_speed;
			if (cub->map[(int)(cub->pos_x)]\
						[(int)(cub->pos_y - cub->dir_x * cub->act.m_speed)] == '0')
				cub->pos_y -= cub->dir_x * cub->act.m_speed;
		}
	/**
	 * end of move_side
	 */
//	turn_left(cub);
	/**
	 * turn_left(cub);
	 */
		if (cub->act.r_left == 1)
		{
			cub->olddir_x = cub->dir_x;
			cub->dir_x = cub->dir_x * cos(cub->act.r_speed) \
						- cub->dir_y * sin(cub->act.r_speed);
			cub->dir_y = cub->olddir_x * sin(cub->act.r_speed) \
						+ cub->dir_y * cos(cub->act.r_speed);
			cub->oldplane_x = cub->plane_x;
			cub->plane_x = cub->plane_x * cos(cub->act.r_speed) \
						- cub->plane_y * sin(cub->act.r_speed);
			cub->plane_y = cub->oldplane_x * sin(cub->act.r_speed) \
						+ cub->plane_y * cos(cub->act.r_speed);
		}
	/**
	 * end of turn_left
	 */
//	turn_right(cub);
	/**
	 * turn_right(cub);
	 */
		if (cub->act.r_right == 1)
		{
			cub->olddir_x = cub->dir_x;
			cub->dir_x = cub->dir_x * cos(-cub->act.r_speed) \
							- cub->dir_y * sin(-cub->act.r_speed);
			cub->dir_y = cub->olddir_x * sin(-cub->act.r_speed) \
							+ cub->dir_y * cos(-cub->act.r_speed);
			cub->oldplane_x = cub->plane_x;
			cub->plane_x = cub->plane_x * cos(-cub->act.r_speed) \
							- cub->plane_y * sin(-cub->act.r_speed);
			cub->plane_y = cub->oldplane_x * sin(-cub->act.r_speed) \
							+ cub->plane_y * cos(-cub->act.r_speed);
		}
	/**
	 * end of turn_right
	 */
	raycasting(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->image, 0, 0);
	if (cub->act.hud == 1)
	{
		mlx_string_put(cub->mlx_ptr, cub->win_ptr, 20, 10, 0xFFFFFF, \
														"W, A, S, D : move");
		mlx_string_put(cub->mlx_ptr, cub->win_ptr, 20, 30, 0xFFFFFF, \
														"<- & -> : rotate");
		mlx_string_put(cub->mlx_ptr, cub->win_ptr, 20, 50, 0xFFFFFF, \
														"SHIFT : sprint");
		mlx_string_put(cub->mlx_ptr, cub->win_ptr, 20, 70, 0xFFFFFF, \
														"H : Hide the menu");
		mlx_string_put(cub->mlx_ptr, cub->win_ptr, 20, 90, 0xFFFFFF, \
														"ESC : exit");
	}
	return (0);
}
