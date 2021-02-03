#include "cub3D.h"


t_map       *init_map(t_map *map)
{
    if (!map)
        map = (t_map *)malloc(sizeof(t_map));
    map->north = 0;
    map->south = 0;
    map->west = 0;
    map->east = 0;
    map->sprite = 0;
    return (map);
}  

t_screen    *init_screen(t_screen *screen)
{
    if (!screen)
        screen = (t_screen *)malloc(sizeof(t_screen));
    screen->w = 0;
    screen->h = 0;
    return (screen);
}

t_floor    *init_floor(t_floor *floor)
{
   if (!floor)
       floor = (t_floor *)malloc(sizeof(t_floor));
    floor->r = 0;
    floor->g = 0;
    floor->b = 0;
    return (floor);
}

t_ceiling    *init_ceiling(t_ceiling *ceiling)
{
   if (!ceiling)
       ceiling = (t_ceiling *)malloc(sizeof(t_ceiling));
    ceiling->r = 0;
    ceiling->g = 0;
    ceiling->b = 0;
    return (ceiling);
}

t_parser 	*init_parser(t_parser *parser)
{
    if (!parser)
        parser = (t_parser *)malloc(sizeof(t_parser));
    parser->c_screen_size = 0;
	parser->c_color_floor = 0;
	parser->c_color_ceiling = 0;
	parser->c_north = 0;
	parser->c_south = 0;
	parser->c_west = 0;
	parser->c_east = 0;
	parser->c_sprite = 0;
	parser->count_of_recorded_values = 0;
	parser->count_of_map_lines = 0;
	parser->max_strlen_of_map = 0;
	return (parser);
}

void    init_cub3D(t_cub3D *cub3D, char *path)
{
	cub3D->file_path = path;
    cub3D->screen = init_screen(NULL);
    cub3D->map = init_map(NULL);
    cub3D->floor = init_floor(NULL);
    cub3D->ceiling = init_ceiling(NULL);
    cub3D->parser = init_parser(NULL);
}

int		check_line_for_map(char *line)
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

void	init_array(t_cub3D *cub3D)
{
	int		i;
	int 	fd;
	char	*line;
	int 	x = cub3D->parser->max_strlen_of_map;
	int		y = cub3D->parser->count_of_map_lines;
	int		count;

	cub3D->array = (char **)malloc(y + 1);
	cub3D->array[y] = NULL;
	i = 0;
	count = 0;
	fd = open(cub3D->file_path, O_RDONLY);
	while((i = get_next_line(fd, &line)) >= 0)
    {
		if (line[0] == ' ')
		{
			if (check_line_for_map(line) == 1)
			{
				// printf("%s\n", line);
				cub3D->array[count] = (char *)malloc(ft_strlen(line) + 1);
				ft_strcpy(cub3D->array[count], line);
				count++;
			}
		}
		if (line[0] == '1')
		{	
			cub3D->array[count] = (char *)malloc(ft_strlen(line) + 1);
			ft_strcpy(cub3D->array[count], line);
			count++;
		}
		if (i == 0)
			break;
    }
}

int     main(int argc, char **argv)
{
    t_cub3D cub3D;

    if (argc)
    {
        if (argc == 2)
        {
            init_cub3D(&cub3D, argv[1]);
            ft_parse(&cub3D); //TODO проверка наличия файла, откуда идет чтение
			init_array(&cub3D);
        }
    }
	ft_print_structs(&cub3D);
    return (0);
}