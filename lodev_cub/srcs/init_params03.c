/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:00:01 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/16 15:00:04 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_player_point	*init_player_point(t_player_point *point)
{
	point = malloc(sizeof(t_player_point));
	point->posX = 22;
	point->posY = 12;
	point->dirX = -1;
	point->dirY = 0;
	point->planeX = 0;
	point->planeY = 0.66;
	return (point);
}

t_dda			*init_dda(t_dda *dda)
{
	dda = malloc(sizeof(t_dda));
	dda->side = 0;
	dda->deltaDistX = 0;
	dda->deltaDistY = 0;
	dda->sideDistX = 0;
	dda->sideDistY = 0;
	dda->perpWallDist = 0;
	return (dda);
}

t_player		*init_player(t_player *player)
{
	player = malloc(sizeof(t_player));
	player->cameraX = 0;
	player->mapX = 0;
	player->mapY = 0;
	player->player_point = init_player_point(NULL);
	player->dda = init_dda(NULL);
	player->rayDirX = 0;
	player->rayDirY = 0;
	player->stepX = 0;
	player->stepY = 0;
	return (player);
}
