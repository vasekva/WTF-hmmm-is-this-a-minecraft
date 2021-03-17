/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_def_player_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:50:47 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/16 14:50:50 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_check_raydir_x(t_cub3D *cub3d)
{
	if (cub3d->player->rayDirX < 0)
	{
		cub3d->player->stepX = -1;
		cub3d->player->dda->sideDistX
			= (cub3d->player->player_point->posX - cub3d->player->mapX)
			* cub3d->player->dda->deltaDistX;
	}
	else
	{
		cub3d->player->stepX = 1;
		cub3d->player->dda->sideDistX
			= (cub3d->player->mapX + 1.0 - cub3d->player->player_point->posX)
			* cub3d->player->dda->deltaDistX;
	}
}

static void	ft_check_raydir_y(t_cub3D *cub3d)
{
	if (cub3d->player->rayDirY < 0)
	{
		cub3d->player->stepY = -1;
		cub3d->player->dda->sideDistY
			= (cub3d->player->player_point->posY - cub3d->player->mapY)
			* cub3d->player->dda->deltaDistY;
	}
	else
	{
		cub3d->player->stepY = 1;
		cub3d->player->dda->sideDistY
			= (cub3d->player->mapY + 1.0 - cub3d->player->player_point->posY)
			* cub3d->player->dda->deltaDistY;
	}
}

void	ft_def_player_dir(t_cub3D *cub3d)
{
	cub3d->player->dda->deltaDistX = sqrt(1
			+ (cub3d->player->rayDirY * cub3d->player->rayDirY)
			/ (cub3d->player->rayDirX * cub3d->player->rayDirX));
	cub3d->player->dda->deltaDistY = sqrt(1
			+ (cub3d->player->rayDirX * cub3d->player->rayDirX)
			/ (cub3d->player->rayDirY * cub3d->player->rayDirY));
	ft_check_raydir_x(cub3d);
	ft_check_raydir_y(cub3d);
}
