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

t_env	*init_env(t_env *env, t_cub3D *cub3d)
{
	int	w;
	int	h;

	w = cub3d->screen->w;
	h = cub3d->screen->h;
	env = malloc(sizeof(t_env));
	env->win = NULL;
	env->mlx = NULL;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, w, h, "Cub3D");
	return (env);
}

t_mlx	*init_mlx_img(t_mlx *mlx_img)
{
	mlx_img = malloc(sizeof(t_mlx));
	mlx_img->img = NULL;
	mlx_img->addr = NULL;
	mlx_img->bits_per_pixel = 0;
	mlx_img->line_length = 0;
	mlx_img->endian = 0;
	return (mlx_img);
}

t_keys	*init_keys(t_keys *keys)
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

t_walls	*init_walls(t_walls *walls)
{
	walls = malloc(sizeof(t_walls));
	walls->lineHeight = 0;
	walls->drawStart = 0;
	walls->drawEnd = 0;
	walls->color = 0;
	return (walls);
}
