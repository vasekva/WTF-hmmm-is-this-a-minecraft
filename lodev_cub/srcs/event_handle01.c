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

int	keyrelease_hook(int key, void *param)
{
	t_cub3D	*cub3d;

	if (param)
	{
		cub3d = (t_cub3D *)param;
		if (key == LEFT_A)
			cub3d->keys->leftAKey = 0;
		if (key == RIGHT_D)
			cub3d->keys->rightDKey = 0;
		if (key == LEFT)
			cub3d->keys->leftKey = 0;
		if (key == RIGHT)
			cub3d->keys->rightKey = 0;
		if (key == UP)
			cub3d->keys->upKey = 0;
		if (key == DOWN)
			cub3d->keys->downKey = 0;
	}
	return (1);
}

int	keypress_hook(int key, void *param)
{
	t_cub3D	*cub3d;

	if (param)
	{
		cub3d = (t_cub3D *)param;
		if (key == LEFT_A)
			cub3d->keys->leftAKey = 1;
		if (key == RIGHT_D)
			cub3d->keys->rightDKey = 1;
		if (key == LEFT)
			cub3d->keys->leftKey = 1;
		if (key == RIGHT)
			cub3d->keys->rightKey = 1;
		if (key == UP)
			cub3d->keys->upKey = 1;
		if (key == DOWN)
			cub3d->keys->downKey = 1;
		if (key == ESC)
			exit(0);
	}
	return (1);
}
