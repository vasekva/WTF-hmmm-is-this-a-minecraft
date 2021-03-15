/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:29:10 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/15 14:29:12 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_print_error(char *str)
{
	int i;

	i = 0;
	write(1, "Parameter '", 11);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "' has already been specified!\n\n", 31);
	exit(0);
}

static int	ft_check_struct(char *str, t_cub3D *cub3d)
{
	if (str[0] == 'S' && str[1] != 'O')
		if (cub3d->map->sprite != NULL)
			ft_print_error("S");
	if (str[0] == 'S' && str[1] == 'O')
		if (cub3d->map->south != NULL)
			ft_print_error("SO");
	if (str[0] == 'N' && str[1] == 'O')
		if (cub3d->map->north != NULL)
			ft_print_error("NO");
	if (str[0] == 'W' && str[1] == 'E')
		if (cub3d->map->west != NULL)
			ft_print_error("WE");
	if (str[0] == 'E' && str[1] == 'A')
		if (cub3d->map->east != NULL)
			ft_print_error("EA");
	return (1);
}

static int	ft_read_path(char *str, int start, int len, t_cub3D *cub3d)
{
	ft_check_struct(str, cub3d);
	if (str[0] == 'S' && str[1] != 'O')
		cub3d->map->sprite = ft_substr(str, start, len);
	if (str[0] == 'S' && str[1] == 'O')
		cub3d->map->south = ft_substr(str, start, len);
	if (str[0] == 'N' && str[1] == 'O')
		cub3d->map->north = ft_substr(str, start, len);
	if (str[0] == 'W' && str[1] == 'E')
		cub3d->map->west = ft_substr(str, start, len);
	if (str[0] == 'E' && str[1] == 'A')
		cub3d->map->east = ft_substr(str, start, len);
	return (0);
}

int			ft_parse_path(char *str, t_cub3D *cub3d)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (str[0] == 'S' && str[1] != 'O')
		i++;
	else
		i += 2;
	if (str[i] != ' ')
	{
		exception(FOUR);
	}
	while (str[i] == ' ')
		i++;
	len = ft_strlen(&str[i]);
	if (len == 0)
	{
		exception(EIGHT);
	}
	else
	{
		ft_read_path(str, i, len, cub3d);
	}
	return (0);
}
