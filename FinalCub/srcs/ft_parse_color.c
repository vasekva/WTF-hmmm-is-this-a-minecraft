#include "cub3d.h"

static int	ft_pow(int num, int i)
{
	int count;

	count = 0;
	while (count < i)
	{
		num *= 10;
		count++;
	}
	return (num);
}

/*
* Используется парсером в ft_parse_screen_size
*/
int			ft_parse_int(char *str)
{
	int i;
	int	sum;
	int len;

	len = ft_strlen(str);
	i = 0;
	sum = 0;
	while (i < len)
	{
		int n = str[len - (i + 1)] - '0';
		sum = sum + ft_pow(n, i);
		i++;
	}
	return (sum);
}

int		create_rgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}

/*
* Проверка запятых в строке
*/
static int ft_check_comma(char *str)
{
	int 	i;
	int		count_comma;

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

static int	ft_skip_spaces_and_zeros(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	if (!ft_isdigit(str[i]))
	{
		if (str[i] == '-')
		{
			exception(TWENTYSEVEN);
		}
		else
		{
			exception(TWENTYEIGHT);
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

static int	ft_read_color(char *str, int i, int ind, char value, t_cub3d *cub3d)
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
		exception(TWENTYSIX);
	}
	if (str[i] != ',' && str[i] != '\0')
	{
		exception(FIFTEEN);
	}
	else
		i++;
	ft_write_color(color, value, cub3d);
	return (i);
}

static int	ft_check_colors(char *line, int ind, t_cub3d *cub3d)
{
	int i;

	i = 1;
	i = ft_read_color(line, i, ind, 'R', cub3d);
	i = ft_read_color(line, i, ind, 'G', cub3d);
	i = ft_read_color(line, i, ind, 'B', cub3d);
	printf("|%d|%d|%d|\n", cub3d->color.r, cub3d->color.g, cub3d->color.b);
	cub3d->tex[ind].col = create_rgb(cub3d->color.r, cub3d->color.g, cub3d->color.b);
	return (0);
}

int	ft_parse_color(char *line, int ind, t_cub3d *cub3d)
{
	int	i;

	i = 1;
	i++;
	ft_check_colors(line, ind, cub3d);
	return (0);
}