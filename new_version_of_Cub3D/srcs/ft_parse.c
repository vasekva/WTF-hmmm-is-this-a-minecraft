#include "cub3D.h"
#include "libft.h"

void	ft_read_map(char *str)
{

}

int 	check_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			if (str[i] == '1')
			{
				ft_read_map(&str[i]);
				return (0);
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

int 	ft_parse_screen_size(char *str, t_cub3D *cub3D)
{
	int len;
	int i;

	len = 0;
	i = 0;
	if (str[ft_strlen(str) - 1] == ' ')
		printf("ERROR"); //TODO вывод ошибок

	/*
	 * СНИЗУ КОСТЫЛЬ
	 * */
	else
	{
		while (!ft_isdigit(str[i]))
			i++;
		while (ft_isdigit(str[i]))
		{
			len++;
			i++;
		}
		cub3D->screen->w = ft_parse_int(ft_substr(str, i - len, len));
		len = 0;
		while (!ft_isdigit(str[i]))
			i++;
		while (ft_isdigit(str[i]))
		{
			len++;
			i++;
		}
		cub3D->screen->h = ft_parse_int(ft_substr(str, i - len, len));
		printf("W: %d H: %d\n", cub3D->screen->w, cub3D->screen->h);
	}
	return (0);
}

int 	ft_read_path(char *str, t_cub3D *cub3D, char *flag)
{
	t_map map;
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] != ' ')
		i++;
	while (str[i] == ' ')
		i++;
	len = ft_strlen(&str[i]);
	if (flag[0] == 'S' && flag[1] == '\0')
		cub3D->map->sprite = ft_substr(&str[i], 0, len);
	if (flag[0] == 'S' && flag[1] == 'O')
		cub3D->map->south = ft_substr(&str[i], 0, len);
	if (flag[0] == 'N' && flag[1] == 'O')
		cub3D->map->north = ft_substr(&str[i], 0, len);
	if (flag[0] == 'W' && flag[1] == 'E')
		cub3D->map->west = ft_substr(&str[i], 0, len);
	if (flag[0] == 'E' && flag[1] == 'A')
		cub3D->map->east = ft_substr(&str[i], 0, len);						
	return (0);
}


int 	check_identifier(char *str, t_cub3D *cub3D)
{
	int		i;

	i = 0;

	if (str[i + 1] == ' ')
	{
		if (str[i] == 'R')
		{
			if (str[ft_strlen(str) - 1] == ' ')
				printf("ERROR\n"); //TODO вывод ошибок
			ft_parse_screen_size(&str[i], cub3D);
			cub3D->count_of_recorded_values++;
		}
		if (str[i] == 'S')
		{
			if (str[ft_strlen(str) - 1] == ' ')
				printf("ERROR\n"); //TODO вывод ошибок
			ft_read_path(&str[i], cub3D, "S");
			cub3D->count_of_recorded_values++;
		}
		if (str[i] == 'F' || str[i] == 'C')
		{
			if (str[ft_strlen(str) - 1] == ' ')
				printf("ERROR\n"); //TODO вывод ошибок
			if (str[i] == 'F')
			{
				cub3D->count_of_recorded_values++;
				ft_write_color(&str[i], 'F', cub3D);
			}
			else
			{
				cub3D->count_of_recorded_values++;
				ft_write_color(&str[i], 'C', cub3D);
			}
		}
	}
	else
	{
		if (str[i] == 'N' && str[i + 1] == 'O')
		{
			cub3D->count_of_recorded_values++;
			ft_read_path(&str[i], cub3D, "NO");
		}
		if (str[i] == 'S' && str[i + 1] == 'O')
		{
			cub3D->count_of_recorded_values++;
			ft_read_path(&str[i], cub3D, "SO");
		}
		if (str[i] == 'W' && str[i + 1] == 'E')
		{
			cub3D->count_of_recorded_values++;
			ft_read_path(&str[i], cub3D, "WE");
		}
		if (str[i] == 'E' && str[i + 1] == 'A')
		{
			cub3D->count_of_recorded_values++;
			ft_read_path(&str[i], cub3D, "EA");
		}
	}
	return (0);
}

int     ft_parse(char *map, t_cub3D *cub3D)
{
    if (map)
    {
		int 	fd;
		char	*line;
		int		i;
		int		count_check_values;

		fd = open(map, O_RDONLY);
		i = 0;
		count_check_values = 0;
    	while((i = get_next_line(fd, &line)) >= 0)
    	{
    	    printf("%s\n", &line[0]);

			if (ft_isidentifier(line))
    	    	check_identifier(line, cub3D);
			else if (line[0] == ' ')
				check_line(line);
			else if (line[0] == '1')
			{	
				if (count_check_values == 0)
					if (cub3D->count_of_recorded_values != 8)
						printf("Карта не может быть прочитана до инициализации всех \
									обязательных переменных");  //TODO вывод ошибок
				count_check_values = 1;
				ft_read_map(line);
			}
			else
				printf("ERROR\n"); //TODO вывод ошибок
			if (i == 0)
				break;
    	}

    }
	ft_print_structs(cub3D);
    return (0);
}  