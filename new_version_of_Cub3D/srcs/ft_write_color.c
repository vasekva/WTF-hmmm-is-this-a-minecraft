#include "cub3D.h"

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
int 	ft_write_color(char *str, char flag, t_cub3D *cub3D)
{
	int		r;
	int		g;
	int		b;
	int 	i;
	int 	len;

	i = 0;
	len = 0;

	//TODO распределить код по функциям

	//printf("CHECK_COLOR: %s\n", str);
	if (flag != 'C' && flag != 'F')
		printf("ERROR\n"); //TODO сделать вывод ошибок
	while (!ft_isdigit(str[i]))
		i++;
	if (ft_check_comma(&str[i]) == -1)
		printf("ERROR\n"); //TODO сделать вывод ошибок

	while (ft_isdigit(str[i]))
	{
		len++;
		i++;
	}
	if (str[i + 1] == ' ')
		printf("ERROR\n"); //TODO сделать вывод ошибок
	r = ft_parse_int(ft_substr(str, i - len, len));
	len = 0;

	while (ft_isdigit(str[++i]))
	{
		len++;
	}
	if (str[i + 1] == ' ')
		printf("ERROR\n"); //TODO сделать вывод ошибок
	g = ft_parse_int(ft_substr(str, i - len, len));
	len = 0;

	while (ft_isdigit(str[++i]))
	{
		len++;
	}
	b = ft_parse_int(ft_substr(str, i - len, len));
	/*
	*  Проверка флага, куда закидывать цветв RGB
	*/
	if (flag == 'F')
	{
		cub3D->floor->r = r;
		cub3D->floor->g = g;
		cub3D->floor->b = b;
	}
	else
	{
		cub3D->ceiling->r = r;
		cub3D->ceiling->g = g;
		cub3D->ceiling->b = b;
	}
	return (0);
}