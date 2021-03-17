/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:29:32 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/15 14:29:34 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_perform_dda(t_cub3D *cub3d)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (cub3d->player->dda->sideDistX < cub3d->player->dda->sideDistY)
		{
			cub3d->player->dda->sideDistX += cub3d->player->dda->deltaDistX;
			cub3d->player->mapX += cub3d->player->stepX;
			cub3d->player->dda->side = 0;
		}
		else
		{
			cub3d->player->dda->sideDistY += cub3d->player->dda->deltaDistY;
			cub3d->player->mapY += cub3d->player->stepY;
			cub3d->player->dda->side = 1;
		}
		if (cub3d->array->map_arr[cub3d->player->mapX]
			[cub3d->player->mapY] > '0')
			hit = 1;
	}
}

void	ft_calc_distance(t_cub3D *cub3d, int x)
{
	int	y;

	if (cub3d->player->dda->side == 0)
		cub3d->player->dda->perpWallDist
			= (cub3d->player->mapX - cub3d->player->player_point->posX
				+ (1 - cub3d->player->stepX) / 2) / cub3d->player->rayDirX;
	else
		cub3d->player->dda->perpWallDist
			= (cub3d->player->mapY - cub3d->player->player_point->posY
				+ (1 - cub3d->player->stepY) / 2) / cub3d->player->rayDirY;
	cub3d->walls->lineHeight = (int)(cub3d->screen->h
			/ cub3d->player->dda->perpWallDist);
	cub3d->walls->drawStart
		= -cub3d->walls->lineHeight / 2 + cub3d->screen->h / 2;
	if (cub3d->walls->drawStart < 0)
		cub3d->walls->drawStart = 0;
	cub3d->walls->drawEnd = cub3d->walls->lineHeight / 2 + cub3d->screen->h / 2;
	if (cub3d->walls->drawEnd >= cub3d->screen->h)
		cub3d->walls->drawEnd = cub3d->screen->h - 1;
	cub3d->walls->color = create_rgb(255, 255, 255);
	y = cub3d->walls->drawStart - 1;
	while (++y < cub3d->walls->drawEnd)
	{
		my_mlx_pixel_put(cub3d->mlx_img, x, y, cub3d->walls->color);
	}
}

void	ft_start_game(t_cub3D *cub3d, int x)
{
	cub3d->env->img
		= mlx_new_image(cub3d->env->mlx, cub3d->screen->w, cub3d->screen->h);
	cub3d->mlx_img->addr
		= mlx_get_data_addr(cub3d->env->img,
			&cub3d->mlx_img->bits_per_pixel,
			&cub3d->mlx_img->line_length, &cub3d->mlx_img->endian);
	while (x < cub3d->screen->w)
	{
		cub3d->player->cameraX = 2 * x / (double)(cub3d->screen->w) - 1;
		cub3d->player->rayDirX
			= cub3d->player->player_point->dirX
			+ (cub3d->player->player_point->planeX * cub3d->player->cameraX);
		cub3d->player->rayDirY
			= cub3d->player->player_point->dirY
			+ (cub3d->player->player_point->planeY * cub3d->player->cameraX);
		cub3d->player->mapX = (int)(cub3d->player->player_point->posX);
		cub3d->player->mapY = (int)(cub3d->player->player_point->posY);
		ft_def_player_dir(cub3d);
		ft_perform_dda(cub3d);
		ft_calc_distance(cub3d, x);
		ft_move_player(cub3d);
		x++;
	}
	mlx_put_image_to_window(cub3d->env->mlx, cub3d->env->win,
		cub3d->env->img, 0, 0);
}
