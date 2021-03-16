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

int				ft_abs(int num)
{
	return (num < 0 ? -num : num);
}

static void		my_mlx_pixel_put(t_mlx *mlx_img, int x, int y, int color)
{
	char	*dst;

	dst = mlx_img->addr + (y * mlx_img->line_length + x
		* (mlx_img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int				create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void			ft_check_raydir_x(t_cub3D *cub3d)
{
	if (cub3d->player->rayDirX < 0)
	{
		cub3d->player->stepX = -1;
		cub3d->player->sideDistX = (cub3d->player->player_point->posX
			- cub3d->player->mapX) * cub3d->player->deltaDistX;
	}
	else
	{
		cub3d->player->stepX = 1;
		cub3d->player->sideDistX = (cub3d->player->mapX + 1.0
			- cub3d->player->player_point->posX) * cub3d->player->deltaDistX;
	}
}

void			ft_check_raydir_y(t_cub3D *cub3d)
{
	if (cub3d->player->rayDirY < 0)
	{
		cub3d->player->stepY = -1;
		cub3d->player->sideDistY = (cub3d->player->player_point->posY
			- cub3d->player->mapY) * cub3d->player->deltaDistY;
	}
	else
	{
		cub3d->player->stepY = 1;
		cub3d->player->sideDistY = (cub3d->player->mapY + 1.0
			- cub3d->player->player_point->posY) * cub3d->player->deltaDistY;
	}
}

void			ft_def_player_dir(t_cub3D *cub3d)
{
	cub3d->player->deltaDistX = sqrt(1 + (cub3d->player->rayDirY
		* cub3d->player->rayDirY) /
		(cub3d->player->rayDirX * cub3d->player->rayDirX));
	cub3d->player->deltaDistY = sqrt(1 + (cub3d->player->rayDirX
		* cub3d->player->rayDirX) /
		(cub3d->player->rayDirY * cub3d->player->rayDirY));
	ft_check_raydir_x(cub3d);
	ft_check_raydir_y(cub3d);
}

void			ft_perform_dda(t_cub3D *cub3d)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (cub3d->player->sideDistX < cub3d->player->sideDistY)
		{
			cub3d->player->sideDistX += cub3d->player->deltaDistX;
			cub3d->player->mapX += cub3d->player->stepX;
			cub3d->player->dda->side = 0;
		}
		else
		{
			cub3d->player->sideDistY += cub3d->player->deltaDistY;
			cub3d->player->mapY += cub3d->player->stepY;
			cub3d->player->dda->side = 1;
		}
		if (cub3d->array->map_arr[cub3d->player->mapX]
			[cub3d->player->mapY] > '0')
			hit = 1;
	}
}

void			ft_calc_distance(t_cub3D *cub3d, int x)
{
	int y;

	if (cub3d->player->dda->side == 0)
		cub3d->player->dda->perpWallDist = (cub3d->player->mapX
			- cub3d->player->player_point->posX
			+ (1 - cub3d->player->stepX) / 2) / cub3d->player->rayDirX;
	else
		cub3d->player->dda->perpWallDist = (cub3d->player->mapY
			- cub3d->player->player_point->posY
			+ (1 - cub3d->player->stepY) / 2) / cub3d->player->rayDirY;
	cub3d->walls->lineHeight = (int)(cub3d->screen->h
			/ cub3d->player->dda->perpWallDist);
	cub3d->walls->drawStart = -cub3d->walls->lineHeight
			/ 2 + cub3d->screen->h / 2;
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

void			ft_start_game(t_cub3D *cub3d)
{
	int x;

	x = 0;
	cub3d->env->img = mlx_new_image(cub3d->env->mlx,
		cub3d->screen->w, cub3d->screen->h);
	cub3d->mlx_img->addr = mlx_get_data_addr(cub3d->env->img,
		&cub3d->mlx_img->bits_per_pixel, &cub3d->mlx_img->line_length,
			&cub3d->mlx_img->endian);
	while (x < cub3d->screen->w)
	{
		cub3d->player->cameraX = 2 * x / (double)(cub3d->screen->w) - 1;
		cub3d->player->rayDirX = cub3d->player->player_point->dirX
			+ (cub3d->player->player_point->planeX * cub3d->player->cameraX);
		cub3d->player->rayDirY = cub3d->player->player_point->dirY
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
