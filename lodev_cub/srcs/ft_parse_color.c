/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:29:01 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/15 14:29:02 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
** ft_parse_color() сперва проверяет, что после символа цвета стоит пробел,
** после вызывает функцию ft_check_colors() в которой сперва проверяется то, что
** переменные не были инициализированы, после три раза вызывается функция
** ft_read_color(), которая в самом начале вызывает ft_skip_spaces_and_zeros(),
** пропускающую все пробелы и нули, а так же проверяет символ после пропущенных,
** после возвращает индекс первого числового значения
** ft_read_color() высчитывает длинну числового значения, после чего передает ее
** в ft_atoi() в который передается число, вырезанное с помощью ft_substr(), в
** конце проверяется валидность значения цвета и символа после числового знач-ия
** и вызывается ft_write_color() и в нужную структуру под определенным цветом
** заносятся значения.
*/

static int		ft_write_color(int color,
	char symb_of_color, t_cub3D *cub3d)
{
	if (cub3d->identifier == 'F')
	{
		if (symb_of_color == 'R')
			cub3d->floor->r = color;
		if (symb_of_color == 'G')
			cub3d->floor->g = color;
		if (symb_of_color == 'B')
			cub3d->floor->b = color;
	}
	if (cub3d->identifier == 'C')
	{
		if (symb_of_color == 'R')
			cub3d->ceiling->r = color;
		if (symb_of_color == 'G')
			cub3d->ceiling->g = color;
		if (symb_of_color == 'B')
			cub3d->ceiling->b = color;
	}
	return (0);
}

static int		ft_skip_spaces_and_zeros(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	if (!ft_isdigit(str[i]))
	{
		if (str[i] == '-')
		{
			exception(NINE);
		}
		else
		{
			exception(TEN);
		}
	}
	if (str[i] == '0')
	{
		while (str[i] == '0')
		{
			i++;
		}
	}
	return (i);
}

static int		ft_read_color(char *str, int i, char value, t_cub3D *cub3d)
{
	int		len;
	int		color;

	len = 0;
	i = ft_skip_spaces_and_zeros(str, i) - 1;
	while (ft_isdigit(str[++i]))
		len++;
	color = ft_atoi(ft_substr(str, i - len, len));
	if (color > 255)
	{
		exception(ELEVEN);
	}
	if (str[i] != ',' && str[i] != '\0')
	{
		exception(TWELVE);
	}
	else
		i++;
	ft_write_color(color, value, cub3d);
	return (i);
}

static int		ft_check_colors(char *str, int i, t_cub3D *cub3d)
{
	if (cub3d->identifier == 'F')
	{
		if (cub3d->floor->r != -1
			|| cub3d->floor->g != -1 || cub3d->floor->b != -1)
		{
			exception(THIRTEEN);
		}
	}
	if (cub3d->identifier == 'C')
	{
		if (cub3d->ceiling->r != -1 || cub3d->ceiling->g != -1
		|| cub3d->ceiling->b != -1)
		{
			exception(FOURTEEN);
		}
	}
	i = ft_read_color(str, i, 'R', cub3d);
	i = ft_read_color(str, i, 'G', cub3d);
	i = ft_read_color(str, i, 'B', cub3d);
	return (0);
}

int				ft_parse_color(char *str, t_cub3D *cub3d)
{
	int i;

	i = 1;
	cub3d->identifier = str[0];
	if (str[i] != ' ')
	{
		exception(FOUR);
	}
	i++;
	ft_check_colors(str, i, cub3d);
	return (0);
}
