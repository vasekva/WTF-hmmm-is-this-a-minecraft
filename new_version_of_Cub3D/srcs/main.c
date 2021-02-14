#include "cub3D.h"

/*
* В зависимости от угла, под которым смотрит игрок
* вычисляет координаты, куда упадет луч и 
* шаг по X и Y для дальнейшего сдвига координат луча
*/
void			ft_draw_rays(t_cub3D *cub3D)
{
	double rad = cub3D->player->posA;
	int Ya = 0;
	int Xa = 0;
	int arrayY = 0;
	int	arrayX = 0;

	/*
	* если вверх, то Ay = (Py / 64) * 64 - 1;
	* если вниз, то Ay = (Py / 64) * 64 + 64;
	*/

	//верх
	if (cub3D->player->degree > 225 && cub3D->player->degree < 315)
	{
		Xa = -SIZE_OF_CUB / tan(cub3D->player->posA);
		Ya = -SIZE_OF_CUB;
		arrayY = ((int)cub3D->player->posY / SIZE_OF_CUB) * SIZE_OF_CUB - 1;
		arrayX = (cub3D->player->posX + (cub3D->player->posY - arrayY) / -tan(cub3D->player->posA)); //TODO почему -tan ?? (cкорее всего из-за реверсивной системы)
	}
	//низ
	if (cub3D->player->degree > 45 && cub3D->player->degree < 135)
	{
		Xa = SIZE_OF_CUB / tan(cub3D->player->posA);
		Ya = SIZE_OF_CUB;
		arrayY = ((int)cub3D->player->posY / SIZE_OF_CUB) * SIZE_OF_CUB + SIZE_OF_CUB;
		arrayX = (cub3D->player->posX + (cub3D->player->posY - arrayY) / -tan(cub3D->player->posA));
	}	

	/* 
	* если влево, то Ay = (Py / 64) * 64 - 1;
	* если вправо, то Ay = (Py / 64) * 64 + 64;
	*/

	//лево
	if (cub3D->player->degree < 225 && cub3D->player->degree > 135)
	{
		Xa = -SIZE_OF_CUB;
		Ya = -SIZE_OF_CUB * tan(cub3D->player->posA);
		arrayX = ((int)cub3D->player->posX / SIZE_OF_CUB) * SIZE_OF_CUB - 1;
		arrayY = (cub3D->player->posY + (cub3D->player->posX - arrayX) * -tan(cub3D->player->posA)); //TODO почему -tan ?? (cкорее всего из-за реверсивной системы)
	}
	//право
	if (cub3D->player->degree > 315 || cub3D->player->degree < 45)
	{
		Xa = SIZE_OF_CUB;
		Ya = SIZE_OF_CUB * tan(cub3D->player->posA);
		arrayX = ((int)cub3D->player->posX / SIZE_OF_CUB) * SIZE_OF_CUB + SIZE_OF_CUB;
		arrayY = (cub3D->player->posY + (cub3D->player->posX - arrayX) * -tan(cub3D->player->posA)); //TODO почему -tan ?? (cкорее всего из-за реверсивной системы)
	}
	int skipBlocks = 0;

	int rx = arrayX + Xa + Xa;
	int ry = arrayY + Ya + Ya;
	int count = 0;


	print_DDALine(cub3D->player->posX, cub3D->player->posY, rx + Xa, ry + Ya, cub3D, 0x00FFFF00);

	// Xa = SIZE_OF_CUB / -tan(cub3D->player->posA);
	printf("TG: %f\n", tan(3.1547));
	printf("ArrayX: %d ArrayY: %d\n", arrayX, arrayY);
	printf("Ya: %d Xa: %d\n", Ya, Xa);
}

/*
 * На основе найденного символа начальной стороны взгляда игрока
 * устанавливает радианную меру угла, под которым направлен вектор
 * взгляда
 */
void			ft_found_player_in_array(t_cub3D *cub3D)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cub3D->parser->count_of_map_lines)
	{
		while (j < cub3D->parser->max_strlen_of_map)
		{
			if (cub3D->array[i][j] == 'N' || cub3D->array[i][j] == 'S' ||
			 	cub3D->array[i][j] == 'W' || cub3D->array[i][j] == 'E')
			{
				cub3D->player->arrayY = i;
				cub3D->player->arrayX = j;
				if (cub3D->array[i][j] == 'N')
				{
					cub3D->player->posA = 4.71239;
				}
				if (cub3D->array[i][j] == 'S')
				{
					cub3D->player->posA = 1.5708;
				}
				if (cub3D->array[i][j] == 'W')
				{
					cub3D->player->posA = 3.14159;
				}
				if (cub3D->array[i][j] == 'E')
				{
					cub3D->player->posA = 0;
				}
				// cub3D->player->degree
				cub3D->player->posDirX = cos(cub3D->player->posA) * 5;
				cub3D->player->posDirY = sin(cub3D->player->posA) * 5;
				cub3D->player->degree = cub3D->player->posA * (180 / PI);					
			}
			j++;
		}
		j = 0;
		i++;
	}
	cub3D->player->posY = (double)(cub3D->player->arrayY + 1) * SIZE_OF_CUB - (SIZE_OF_CUB / 2); //TODO УБРАТЬ + 1
	cub3D->player->posX = (double)(cub3D->player->arrayX + 1) * SIZE_OF_CUB - (SIZE_OF_CUB / 2); //TODO УБРАТЬ + 1
}

static int		loop_hook(void *param)
{
    t_cub3D   *cub3D;

    if (param)
    {
        cub3D = (t_cub3D *)param;
		ft_start_game(cub3D);
    }
    return (0);
}

static void    	init_cub3D(t_cub3D *cub3D, char *path)
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

int     		main(int argc, char **argv)
{
    t_cub3D cub3D;

    if (argc)
    {
        if (argc == 2)
        {
            init_cub3D(&cub3D, argv[1]);
			// mlx_key_hook(cub3D.env->win, keyrelease_hook, &cub3D);
			mlx_hook(cub3D.env->win, 3, 1L<<0, keyrelease_hook, &cub3D);
			ft_found_player_in_array(&cub3D);
			mlx_hook(cub3D.env->win, 2, 1L<<0, keypress_hook, &cub3D);
			mlx_loop_hook(cub3D.env->mlx, loop_hook, &cub3D);
			mlx_loop(cub3D.env->mlx);
        }
    }
	//ft_print_structs(&cub3D);
    return (0);
}