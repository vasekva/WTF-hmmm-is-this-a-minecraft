/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:28:32 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/15 14:28:34 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
** В ft_check_last_lines сначала пропускаются пробельные символы и проверяется,
** является ли первый символ после пробела стеной
**
** В ft_check_top_lines идет проходка по пробельным символам верхней строки, в
** процессе которой в цикле идет проходка по каждому столбцу, первый два if'a
** проверяют закрыта ли карта сверху под пробельными символами, третий if
** проверяет закрыт ли внешний угол, имеющий стены справа и снизу и
** последний цикл проверяет не пробельные символы
**
** В ft_check_longline проверяется строка, длинна которой больше следующей
** первый if проверяет есть ли стена в предыдущем символе, если разница длин = 1
** если разница > 1 проверяется каждый выпирающий символ и наличие относительно
** этого символа стены сверху и снизу
**
** В ft_check_middle_lines в цикле идет проход по пробельным символам
** в процессе которого первые два if'a проверяют символы сверху и снизу на
** наличие 0 || 2, третий if проверяет следующий по строке дальше символ, если
** это 0 || 2 - ошибка
**
** В ft_check_array cначала проверяется размер массива, если он < 2 - ошибка,
** дальше проверяется расположение этой строки: верхняя, нижняя или остальные
** и вызывается одна из функций: ft_check_top_lines, ft_check_last_lines или
** ft_check_middle_lines, дополнительно последний if проверяет разницу длин
** текущей строки и следующей, если нынешняя имеет большую длинну, то вызывается
** ft_check_longline
*/

void	ft_check_last_lines(t_cub3D *cub3d)
{
	int	j;
	int	i;

	j = 0;
	i = cub3d->array->size - 1;
	while (cub3d->array->map_arr[i][j] == ' ')
	{
		j++;
	}
	if (cub3d->array->map_arr[i][j] != '1')
		exception(TWENTYFOUR);
}

void	ft_check_top_lines(t_cub3D *cub3d, int line, int j)
{
	while (cub3d->array->map_arr[0][j] != '\0'
		&& cub3d->array->map_arr[0][j] == ' ')
	{
		line = -1;
		while (cub3d->array->map_arr[++line] != NULL)
		{
			if (cub3d->array->map_arr[line][j] == '0'
				|| cub3d->array->map_arr[line][j] == '2')
				exception(TWENTYONE);
			if (cub3d->array->map_arr[line][j] == '1')
				break ;
			if (cub3d->array->map_arr[line][j + 1] == '1'
				&& cub3d->array->map_arr[line + 1] != NULL
				&& cub3d->array->map_arr[line + 1][j] == '1')
				if (cub3d->array->map_arr[line + 1][j + 1] == '0')
					exception(TWENTYFIVE);
		}
		j++;
	}
	while (cub3d->array->map_arr[0][j] != '\0')
	{
		if (cub3d->array->map_arr[0][j] != '1')
			exception(TWENTYONE);
		j++;
	}
}

void	ft_check_longline(t_cub3D *cub3d, int line, int diff)
{
	int		i;
	char	c;

	if (diff < 0)
		diff *= -1;
	i = ft_strlen(cub3d->array->map_arr[line]) - 1;
	if (diff == 1 && cub3d->array->map_arr[line][i - 1] != '1')
		exception(TWENTYFIVE);
	else
	{
		while (i > (ft_strlen(cub3d->array->map_arr[line + 1]) - 1)
			|| i > (ft_strlen(cub3d->array->map_arr[line - 1]) - 1))
		{
			c = cub3d->array->map_arr[line][i];
			if (c != '1')
				exception(TWENTYSIX);
			i--;
		}
		c = cub3d->array->map_arr[line][i];
		if (c == '0')
			exception(TWENTYFIVE);
	}
}

void	ft_check_middle_lines(t_cub3D *cub3d, int i)
{
	int	j;

	j = 0;
	while (cub3d->array->map_arr[i][j] == ' ')
	{
		if (cub3d->array->map_arr[i - 1][j] == '0')
			exception(TWENTYTWO);
		if ((cub3d->array->map_arr[i + 1][j] == '0'
				|| cub3d->array->map_arr[i + 1][j] == '2')
			&& cub3d->array->map_arr[i + 1] != NULL)
			exception(TWENTYTHREE);
		if (cub3d->array->map_arr[i][j + 1] == '0'
			|| cub3d->array->map_arr[i][j + 1] == '2')
			exception(TWENTYFOUR);
		j++;
	}
}

void	ft_check_array(t_cub3D *cub3d)
{
	int	i;
	int	diff;

	i = 0;
	if (cub3d->array->size < 2)
		exception(EIGHTEEN);
	while (cub3d->array->map_arr[i] != NULL)
	{
		if ((i != cub3d->array->size - 1)
			&& (diff = ft_strlen(cub3d->array->map_arr[i + 1])
					- ft_strlen(cub3d->array->map_arr[i])) != 0)
		{
			if (diff < 0)
				ft_check_longline(cub3d, i, diff);
			else
				ft_check_longline(cub3d, i + 1, diff);
		}
		if (i == 0)
			ft_check_top_lines(cub3d, -1, 0);
		else if (i > 0 && i < cub3d->array->size - 1)
			ft_check_middle_lines(cub3d, i);
		else
			ft_check_last_lines(cub3d);
		i++;
	}
}
