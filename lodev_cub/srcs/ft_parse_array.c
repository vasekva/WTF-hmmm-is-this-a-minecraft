/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:28:51 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/15 14:28:52 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_structs(t_cub3D *cub3d)
{
	if (cub3d->screen->h == -1 && cub3d->screen->w == -1)
		return (-1);
	if (cub3d->map->north == NULL || cub3d->map->south == NULL
		|| cub3d->map->west == NULL || cub3d->map->east == NULL
		|| cub3d->map->sprite == NULL)
		return (-1);
	if (cub3d->ceiling->r == -1 || cub3d->ceiling->g == -1
		|| cub3d->ceiling->b == -1 || cub3d->floor->r == -1
		|| cub3d->floor->g == -1 || cub3d->floor->b == -1)
		return (-1);
	return (0);
}

int	ft_parse_array(char *str, t_cub3D *cub3d, int c)
{
	if (ft_check_structs(cub3d) == -1)
		exception(TWENTYSEVEN);
	if (str[0] != ' ' && str[0] != '1')
		exception(TWENTYEIGHT);
	if (str[ft_strlen(str) - 1] != '1')
		exception(TWENTYNINE);
	while (str[c] == ' ')
		c++;
	while (str[c] != '\0')
	{
		if (str[c] == 'W' || str[c] == 'E' || str[c] == 'S' || str[c] == 'N')
		{
			if (cub3d->array->count_player_point == 1)
				exception(THIRTY);
			cub3d->array->count_player_point++;
		}
		if (str[c] != '0' && str[c] != '1' && str[c] != '2' && str[c] != 'W'
			&& str[c] != 'E' && str[c] != 'S' && str[c] != 'N')
			exception(THIRTYONE);
		c++;
	}
	cub3d->array->size++;
	return (0);
}
