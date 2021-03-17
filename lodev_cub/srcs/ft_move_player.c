/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:49:28 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/16 14:49:32 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_backward(t_cub3D *cub3d, double move_speed)
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;

	pos_x = cub3d->player->player_point->posX;
	pos_y = cub3d->player->player_point->posY;
	dir_x = cub3d->player->player_point->dirX;
	dir_y = cub3d->player->player_point->dirY;
	if (cub3d->array->map_arr
		[(int)(pos_x - dir_x * move_speed)][(int)(pos_y)] == '0')
		cub3d->player->player_point->posX -= dir_x * move_speed;
	if (cub3d->array->map_arr
		[(int)pos_x][(int)(pos_y - dir_y * move_speed)] == '0')
		cub3d->player->player_point->posY -= dir_y * move_speed;
}

void	ft_move_forward(t_cub3D *cub3d, double move_speed)
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;

	pos_x = cub3d->player->player_point->posX;
	pos_y = cub3d->player->player_point->posY;
	dir_x = cub3d->player->player_point->dirX;
	dir_y = cub3d->player->player_point->dirY;
	if (cub3d->array->map_arr
		[(int)(pos_x + dir_x * move_speed)][(int)(pos_y)] == '0')
		cub3d->player->player_point->posX += dir_x * move_speed;
	if (cub3d->array->map_arr
		[(int)(pos_x)][(int)(pos_y + dir_y * move_speed)] == '0')
		cub3d->player->player_point->posY += dir_y * move_speed;
}

void	ft_move_right(t_cub3D *cub3d, double root_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub3d->player->player_point->dirX;
	cub3d->player->player_point->dirX
		= cub3d->player->player_point->dirX
		* cos(-root_speed)
		- cub3d->player->player_point->dirY * sin(-root_speed);
	cub3d->player->player_point->dirY
		= old_dir_x * sin(-root_speed)
		+ (cub3d->player->player_point->dirY * cos(-root_speed));
	old_plane_x = cub3d->player->player_point->planeX;
	cub3d->player->player_point->planeX
		= cub3d->player->player_point->planeX * cos(-root_speed)
		- cub3d->player->player_point->planeY * sin(-root_speed);
	cub3d->player->player_point->planeY
		= old_plane_x * sin(-root_speed)
		+ cub3d->player->player_point->planeY * cos(-root_speed);
}

void	ft_move_left(t_cub3D *cub3d, double rotspeed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub3d->player->player_point->dirX;
	cub3d->player->player_point->dirX
		= cub3d->player->player_point->dirX * cos(rotspeed)
		- cub3d->player->player_point->dirY * sin(rotspeed);
	cub3d->player->player_point->dirY = old_dir_x * sin(rotspeed)
		+ cub3d->player->player_point->dirY * cos(rotspeed);
	old_plane_x = cub3d->player->player_point->planeX;
	cub3d->player->player_point->planeX
		= cub3d->player->player_point->planeX * cos(rotspeed)
		- cub3d->player->player_point->planeY * sin(rotspeed);
	cub3d->player->player_point->planeY
		= old_plane_x * sin(rotspeed)
		+ cub3d->player->player_point->planeY * cos(rotspeed);
}

void	ft_move_player(t_cub3D *cub3d)
{
	double	frame_time;
	double	move_speed;
	double	root_speed;

	frame_time = (3 - 2.99) / 1000.0;
	move_speed = frame_time * 5.0;
	root_speed = frame_time * 3.0;
	if (cub3d->keys->rightDKey == 1)
	{
		ft_move_right(cub3d, root_speed);
	}
	if (cub3d->keys->leftAKey == 1)
	{
		ft_move_left(cub3d, root_speed);
	}
	if (cub3d->keys->upKey == 1)
	{
		ft_move_forward(cub3d, move_speed);
	}
	if (cub3d->keys->downKey == 1)
	{
		ft_move_backward(cub3d, move_speed);
	}
}
