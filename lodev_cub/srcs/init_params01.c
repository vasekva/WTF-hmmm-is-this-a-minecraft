/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:59:55 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/15 18:59:59 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_screen	*init_screen(t_screen *screen)
{
	if (!screen)
		screen = (t_screen *)malloc(sizeof(t_screen));
	screen->w = -1;
	screen->h = -1;
	return (screen);
}

t_floor	*init_floor(t_floor *floor)
{
	if (!floor)
		floor = (t_floor *)malloc(sizeof(t_floor));
	floor->r = -1;
	floor->g = -1;
	floor->b = -1;
	return (floor);
}

t_ceiling	*init_ceiling(t_ceiling *ceiling)
{
	if (!ceiling)
		ceiling = (t_ceiling *)malloc(sizeof(t_ceiling));
	ceiling->r = -1;
	ceiling->g = -1;
	ceiling->b = -1;
	return (ceiling);
}

t_map	*init_map(t_map *map)
{
	if (!map)
		map = (t_map *)malloc(sizeof(t_map));
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;
	map->sprite = NULL;
	return (map);
}

t_array	*init_array(t_array *array)
{
	if (!array)
		array = (t_array *)malloc(sizeof(t_array));
	array->count_player_point = 0;
	array->size = 0;
	array->map_arr = NULL;
	return (array);
}
