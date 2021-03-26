#include "cub3d.h"

/*
* Проверка запятых в строке
*/
static int	ft_check_comma(char *str)
{
	int	i;
	int	count_comma;

	i = 0;
	count_comma = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 44)
			count_comma++;
		i++;
	}
	if (count_comma != 2)
		return (-1);
	return (0);
}

/*
* Считывает параметры цветов из входной строки
* и в зависимости от флага (F, C) записывает
* результат в нужную структуру
*/
static int	ft_write_color(int color,
	char symb_of_color, t_cub3d *cub3d)
{
	if (symb_of_color == 'R')
		cub3d->color.r = color;
	if (symb_of_color == 'G')
		cub3d->color.g = color;
	if (symb_of_color == 'B')
		cub3d->color.b = color;
	return (0);
}

static int	ft_skip_spaces_and_zeros(t_cub3d *cub3d, char *str, int i)
{
	while (str[i] == ' ')
		i++;
	if (!ft_isdigit(str[i]))
	{
		if (str[i] == '-')
		{
			exception(cub3d, TWENTYSEVEN);
		}
		else
		{
			exception(cub3d, TWENTYEIGHT);
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

static int	ft_read_color(char *str, int i, char value, t_cub3d *cub3d)
{
	int		len;
	int		color;
	char	*tmp;

	len = 0;
	i = ft_skip_spaces_and_zeros(cub3d, str, i) - 1;
	while (ft_isdigit(str[++i]))
		len++;
	if (len > 4)
		exception(cub3d, THIRTYFOUR);
	tmp = ft_substr(str, i - len, len);
	color = ft_atoi(tmp);
	free(tmp);
	if (color > 255)
	{
		exception(cub3d, TWENTYSIX);
	}
	if (str[i] != ',' && str[i] != '\0')
	{
		exception(cub3d, FIFTEEN);
	}
	else
		i++;
	ft_write_color(color, value, cub3d);
	return (i);
}

int	ft_parse_color(char *line, int ind, t_cub3d *cub3d)
{
	int	i;

	i = 1;
	i = ft_read_color(line, i, 'R', cub3d);
	i = ft_read_color(line, i, 'G', cub3d);
	i = ft_read_color(line, i, 'B', cub3d);
	cub3d->tex[ind].col
		= create_rgb(cub3d->color.r, cub3d->color.g, cub3d->color.b);
	return (0);
}
