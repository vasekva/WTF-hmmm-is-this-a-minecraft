/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:28:08 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/15 14:28:14 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		keyrelease_hook(int key, void *param)
{
	t_cub3D *cub3d;

	if (param)
	{
		cub3d = (t_cub3D *)param;
		key == LEFT_A ? cub3d->keys->leftAKey = 0 : 0;
		key == RIGHT_D ? cub3d->keys->rightDKey = 0 : 0;
		key == LEFT ? cub3d->keys->leftKey = 0 : 0;
		key == RIGHT ? cub3d->keys->rightKey = 0 : 0;
		key == UP ? cub3d->keys->upKey = 0 : 0;
		key == DOWN ? cub3d->keys->downKey = 0 : 0;
	}
	return (1);
}

int		keypress_hook(int key, void *param)
{
	t_cub3D *cub3d;

	if (param)
	{
		cub3d = (t_cub3D *)param;
		key == LEFT_A ? cub3d->keys->leftAKey = 1 : 0;
		key == RIGHT_D ? cub3d->keys->rightDKey = 1 : 0;
		key == LEFT ? cub3d->keys->leftKey = 1 : 0;
		key == RIGHT ? cub3d->keys->rightKey = 1 : 0;
		key == UP ? cub3d->keys->upKey = 1 : 0;
		key == DOWN ? cub3d->keys->downKey = 1 : 0;
		key == ESC ? exit(0) : 0;
	}
	return (1);
}
