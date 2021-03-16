/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:00:04 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/15 19:00:08 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_env		*init_env(t_env *env, t_cub3D *cub3d)
{
	int w;
	int h;

	w = cub3d->screen->w;
	h = cub3d->screen->h;
	env = malloc(sizeof(t_env));
	env->win = NULL;
	env->mlx = NULL;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, w, h, "Cub3D");
	return (env);
}

t_mlx		*init_mlx_img(t_mlx *mlx_img)
{
	mlx_img = malloc(sizeof(t_mlx));
	mlx_img->img = NULL;
	mlx_img->addr = NULL;
	mlx_img->bits_per_pixel = 0;
	mlx_img->line_length = 0;
	mlx_img->endian = 0;
	return (mlx_img);
}

t_keys		*init_keys(t_keys *keys)
{
	keys = malloc(sizeof(t_keys));
	keys->leftKey = 0;
	keys->rightKey = 0;
	keys->upKey = 0;
	keys->downKey = 0;
	keys->escKey = 0;
	keys->rightDKey = 0;
	keys->leftAKey = 0;
	return (keys);
}

t_player_point *init_player_point(t_player_point *point)
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

t_dda *init_dda(t_dda *dda)
{
	dda = malloc(sizeof(t_dda));
	dda->hit = 0;
	dda->perpWallDist = 0;
	dda->side = 0;
	return (dda);
}

t_player	*init_player(t_player *player)
{
	player = malloc(sizeof(t_player));
	player->cameraX = 0;
	player->mapX = 0;
	player->mapY = 0;
	player->player_point = init_player_point(NULL);
	player->dda = init_dda(NULL);
//	player->dda = init_dda(NULL);
//	player->posX = 22;
//	player->posY = 12;
//	player->dirX = -1;
//	player->dirY = 0;
//	player->planeX = 0;
//	player->planeY = 0.66;
	player->rayDirX = 0;
	player->rayDirY = 0;
	player->stepX = 0;
	player->stepY = 0;
	player->deltaDistX = 0;
	player->deltaDistY = 0;
	player->sideDistX = 0;
	player->sideDistY = 0;
	return (player);
}
