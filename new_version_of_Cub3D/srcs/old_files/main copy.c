#include "cub3D.h"
#include "mlx.h"

static int			check_line_for_map(char *line)
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

int				ft_check_line_map(char *line, int number_of_line, t_cub3D *cub3D)
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

static void			read_and_copy_in_array(t_cub3D *cub3D)
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

static void			init_array(t_cub3D *cub3D)
{
	int		y = cub3D->parser->count_of_map_lines;

	cub3D->array = (char **)malloc(y + 1);
	cub3D->array[y] = NULL;
	read_and_copy_in_array(cub3D);
}

t_env       *init_env(t_env *env, t_cub3D *cub3D)
{
    env = malloc(sizeof(t_env));
    env->win = NULL;
	env->mlx = NULL;
    env->mlx = mlx_init();
    env->win = mlx_new_window(env->mlx, cub3D->screen->w, cub3D->screen->h, "cub3D");
    return (env);
}

t_mlx		*init_mlx_img(t_mlx *mlx_img)
{
	mlx_img = malloc(sizeof(t_mlx));
	mlx_img->img = NULL;
	mlx_img->addr = NULL;
	mlx_img->bits_per_pixel = 0;
	mlx_img->line_length = 0;
	mlx_img->endian = 0;
	return (mlx_img);
}

t_player	*init_player(t_player *player, t_cub3D *cub3D)
{
	player = malloc(sizeof(t_player));
	player->arrayX = 0;
	player->arrayY = 0;
	player->posX = 0;
	player->posY = 0;
	player->posX = cub3D->screen->center_h;
	player->posY = cub3D->screen->center_w;
	player->posA = 0;
	player->posDirX = 0;
	player->posDirY = 0;
	player->posDirX = cos(player->posA) * 5;
	player->posDirY = sin(player->posA) * 5;
	return (player);
}

static void    		init_cub3D(t_cub3D *cub3D, char *path)
{
	cub3D->file_path = path;
    cub3D->screen = init_screen(NULL);
    cub3D->map = init_map(NULL);
    cub3D->floor = init_floor(NULL);
    cub3D->ceiling = init_ceiling(NULL);

    cub3D->parser = init_parser(NULL);
	ft_parse(cub3D); //TODO проверка наличия файла, откуда идет чтение
	init_array(cub3D); // инициализация массива и заполнение

	cub3D->env = init_env(NULL, cub3D); // mlx_init, mlx_new_win...
	cub3D->mlx_img = init_mlx_img(NULL); //инициализация структуры для my_mlx_pixel_put
	cub3D->player = init_player(NULL, cub3D); //инициализация изначального положения игрока
}

// void	ft_found_coord_of_user(t_cub3D *cub3D)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (i < cub3D->parser->max_strlen_of_map)
// 	{
// 		while (j < cub3D->parser->count_of_map_lines)
// 		{
// 			if (cub3D->array[i][j] == 'N' || 
// 				cub3D->array[i][j] == 'S' ||
// 				cub3D->array[i][j] == 'W' ||
// 				cub3D->array[i][j] == 'E')
// 			{
// 				cub3D->player->arrayY = i;
// 				cub3D->player->arrayX = j;
// 			}
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	cub3D->player->posX = cub3D->player->arrayX * SIZE_OF_CUB - (SIZE_OF_CUB / 2);
// 	cub3D->player->posY = cub3D->player->arrayY * SIZE_OF_CUB - (SIZE_OF_CUB / 2);
// 	printf("COORD X OF PLAYER: %d\n", cub3D->player->arrayX);
// 	printf("COORD Y OF PLAYER: %d\n", cub3D->player->arrayY);

// }

int     loop_hook(void *param)
{
    t_cub3D   *cub3D;

    if (param)
    {
        cub3D = (t_cub3D *)param;
		// ft_found_coord_of_user(cub3D);
		ft_start_game(cub3D);
    }
    return (0);
}

int     			main(int argc, char **argv)
{
    t_cub3D cub3D;

    if (argc)
    {
        if (argc == 2)
        {
            init_cub3D(&cub3D, argv[1]);
			//mlx_key_hook(cub3D.env->win, keyrelease_hook, &cub3D);
			mlx_hook(cub3D.env->win, 2, 1L<<0, keypress_hook, &cub3D);
			// ft_found_coord_of_user(&cub3D);
			mlx_loop_hook(cub3D.env->mlx, loop_hook, &cub3D);
			mlx_loop(cub3D.env->mlx);
        }
    }
	//ft_print_structs(&cub3D);
    return (0);
}