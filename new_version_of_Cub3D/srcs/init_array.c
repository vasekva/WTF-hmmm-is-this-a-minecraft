#include "cub3D.h"

/*
* Функция проверяет строку с пробелами на наличие
* символов карты и лишних символов
*/
static int		check_line_for_map(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			if (line[i] == '1')
			{
				return (1);
			}
			else
			{
				printf("ERROR"); //TODO вывод ошибок
				return (-1);
			}
		}
		i++;
	}
	return (0);
}

/*
* Функция проверяет отсутствие лишних 
* символов в строке карты
*/
static int		ft_check_line_map(char *line, int number_of_line, t_cub3D *cub3D)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != '2'
				&& line[i] != 'N' && line[i] != 'S'
				&& line[i] != 'W' && line[i] != 'E')
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

/*
* Считывает строки и ищет символы, хар-ие карту,
* если пробел - в строке с пробелом ищутся спец. символы,
* если единица - проверяется строка и дальше строка
* записывается в массив
*/
static void		read_and_copy_in_array(t_cub3D *cub3D)
{
	char	*line;
	int		number_of_line;
	int 	fd;
	int		i;

	i = 0;
	number_of_line = 0;
	fd = open(cub3D->file_path, O_RDONLY);
	while((i = get_next_line(fd, &line)) >= 0)
    {
		if (line[0] == ' ')
		{
			if (check_line_for_map(line) == 1)
			{
				// printf("%s\n", line);
				cub3D->array[number_of_line] = (char *)malloc(cub3D->parser->max_strlen_of_map + 1);
				ft_strcpy(cub3D->array[number_of_line], line);
				number_of_line++;
			}
		}
		if (line[0] == '1')
		{	
			if (ft_check_line_map(line, number_of_line, cub3D) == -1)
			{
				printf("Строка N%d имеет невалидные символы!\n", number_of_line);
			}
			else
			{
				cub3D->array[number_of_line] = (char *)malloc(ft_strlen(line) + 1);
				ft_strcpy(cub3D->array[number_of_line], line);
				number_of_line++;
			}
		}
		if (i == 0)
			break;
    }
}

void			init_array(t_cub3D *cub3D)
{
	int		y = cub3D->parser->count_of_map_lines;

	cub3D->array = (char **)malloc(y + 1);
	cub3D->array[y] = NULL;
	read_and_copy_in_array(cub3D);
}