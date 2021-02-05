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

static void			read_and_copy_in_array(int fd, t_cub3D *cub3D)
{
	char	*line;
	int		count;
	int		i;

	i = 0;
	count = 0;
	while((i = get_next_line(fd, &line)) >= 0)
    {
		if (line[0] == ' ')
		{
			if (check_line_for_map(line) == 1)
			{
				// printf("%s\n", line);
				cub3D->array[count] = (char *)malloc(cub3D->parser->max_strlen_of_map + 1);
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

static void			init_array(t_cub3D *cub3D)
{
	int 	fd;
	int 	x = cub3D->parser->max_strlen_of_map;
	int		y = cub3D->parser->count_of_map_lines;

	cub3D->array = (char **)malloc(y + 1);
	cub3D->array[y] = NULL;
	fd = open(cub3D->file_path, O_RDONLY);
	read_and_copy_in_array(fd, cub3D);
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
	printf("ENDIAN: %d\n", mlx_img->endian);
	return (mlx_img);
}

t_player	*init_player(t_player *player, t_cub3D *cub3D)
{
	player = malloc(sizeof(t_player));
	player->posX = 0;
	player->posY = 0;
	player->posX = cub3D->screen->center_h - SIZE_OF_PLAYER;
	player->posY = cub3D->screen->center_w - SIZE_OF_PLAYER;
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

int     loop_hook(void *param)
{
    t_cub3D   *cub3D;

    if (param)
    {
        cub3D = (t_cub3D *)param;
		ft_start_game(&cub3D);
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
			mlx_hook(cub3D.env->win, 2, 1L<<0, keypress_hook, &cub3D);
			ft_start_game(&cub3D);
        }
    }
	//ft_print_structs(&cub3D);
    return (0);
}