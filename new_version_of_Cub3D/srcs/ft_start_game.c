#include "cub3D.h"

static void		my_mlx_pixel_put(t_mlx *mlx_img, int x, int y, int color)
{
    char    *dst;

    dst = mlx_img->addr + (y * mlx_img->line_length + x * (mlx_img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

/*
* Функция отрисовывает карту на экран
*/
static void		draw_cub_in_pixel(int x, int y, t_cub3D *cub3D) // TODO сменить у и x местами
{
	int posX = x * SIZE_OF_CUB;
	int posY = y * SIZE_OF_CUB;

	int posXFinal = posX + SIZE_OF_CUB;
	int posYFinal = posY + SIZE_OF_CUB;
	while (posY < posYFinal - 1)
	{
		while (posX < posXFinal - 1)
		{
			if (cub3D->array[y][x] == '1')
				my_mlx_pixel_put(cub3D->mlx_img, posX, posY, color_of_wall_minimap);
			else
				my_mlx_pixel_put(cub3D->mlx_img, posX, posY, color_of_field_minimap);
			posX++;
		}
		posX = x * SIZE_OF_CUB;
		posY++;
	}
}

/*
* Схожая с предыдущей функцией, используется
* для отрисовки массива(двумерной карты)
* вызывая draw_cub_in_pixel c нужными координатами
*/
static void		ft_draw_cub_in_pos(t_cub3D *cub3D) // вызывается в ft_start_game
{
	int x;
	int y;

	x = 0;
	y = 0;

	int count_of_block_in_array_y = cub3D->parser->count_of_map_lines;
	int	count_of_block_in_array_x = cub3D->parser->max_strlen_of_map;
	while (y < count_of_block_in_array_y)
	{
		while (x < count_of_block_in_array_x)
		{
			draw_cub_in_pixel(x, y, cub3D);
			x++;
		}
		x = 0;
		y++;
	}
}

/*
* Рисует куб размером size по координатам, которые принимает в параметрах
*/
static void		draw_cub_in_pixel2D(int x, int y, int size, int color, t_cub3D *cub3D)
{
	int posX = x;
	int posY = y;

	int posXFinal = posX + size;
	int posYFinal = posY + size;
	while (posY < posYFinal)
	{
		while (posX < posXFinal)
		{
			my_mlx_pixel_put(cub3D->mlx_img, posX, posY, color);
			posX++;
		}
		posX = x;
		posY++;
	}
}

/*
* Вычисление координат для отрисовки креста и 
* дальнейший вызов draw_cub_in_pixel с координатами
*/
static void		ft_draw_cross2D(t_cub3D *cub3D)
{
	int color = cub3D->player->player2D->color_of_cross;
	int SIZE = SIZE_OF_PLAYER / 7;
	int x = cub3D->player->posX;
	int y = cub3D->player->posY;
	int startDrawX = x - SIZE_OF_PLAYER / 2;
	int startDrawY = y - SIZE_OF_PLAYER / 2;
	int block_size = SIZE / 2;

	for (int i = 3; i <= 7; i+=2)
	{
		draw_cub_in_pixel2D(x - block_size * i, y - block_size * i, SIZE, color, cub3D);
		draw_cub_in_pixel2D(x - block_size * i, y + block_size * (i - 2), SIZE, color, cub3D);
		draw_cub_in_pixel2D(x + block_size * (i - 2), y - block_size * i, SIZE, color, cub3D);
		draw_cub_in_pixel2D(x + block_size * (i - 2), y + block_size * (i - 2), SIZE, color, cub3D);
	}
}

/*
* Рисует кубик размером 1/5 SIZE_OF_PLAYER в одном из четырех углов
* в зависимости от входных параметров hor_flag & ver_flag цветом int color
*/
static void		ft_draw_corner_cubes(t_cub3D *cub3D, char hor_flag, char vert_flag, int color)
{
	int startDrawX = 0;
	int startDrawY = 0;
	int endDrawX = 0;
	int endDrawY = 0;
	int	size_of_cube = SIZE_OF_PLAYER / 5;

	if (hor_flag == 'L')
	{
		if (vert_flag == 'U')
		{
			startDrawX = cub3D->player->posX - SIZE_OF_PLAYER / 2;
			startDrawY = cub3D->player->posY - SIZE_OF_PLAYER / 2;
		}
		else
		{
			startDrawX = cub3D->player->posX - SIZE_OF_PLAYER / 2;
			startDrawY = cub3D->player->posY + SIZE_OF_PLAYER / 2;
		}
	}
	if (hor_flag == 'R')
	{
		if (vert_flag == 'U')
		{
			startDrawX = cub3D->player->posX + SIZE_OF_PLAYER / 2;
			startDrawY = cub3D->player->posY - SIZE_OF_PLAYER / 2;
		}
		else
		{
			startDrawX = cub3D->player->posX + SIZE_OF_PLAYER / 2;
			startDrawY = cub3D->player->posY + SIZE_OF_PLAYER / 2;
		}
	}
	int x = startDrawX - size_of_cube / 2;
	int y = startDrawY - size_of_cube / 2;
	int i = 0;
	int j = 0;
	while (i < size_of_cube)
	{
		while (j < size_of_cube)
		{
			my_mlx_pixel_put(cub3D->mlx_img, x, y, color);
			j++;
			y++;
		}
		y = startDrawY - size_of_cube / 2;
		j = 0;
		i++;
		x++;
	}
}

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
}

/*
* отрисовка квадрата игрока,
* вызовы функций отрисовки угловых кубов,
* креста и лучей
*/
static void		ft_draw_user(t_cub3D *cub3D)
{
	int color = cub3D->player->player2D->color_of_player;
	int SIZE = SIZE_OF_PLAYER / 10;

	int x = cub3D->player->posX;
	int y = cub3D->player->posY;

	int startDrawX = x - SIZE_OF_PLAYER / 2;
	int startDrawY = y - SIZE_OF_PLAYER / 2;

	while (startDrawY < y + SIZE_OF_PLAYER / 2 - SIZE)
	{
		while (startDrawX < x + SIZE_OF_PLAYER / 2 - SIZE)
		{
			draw_cub_in_pixel2D(startDrawX, startDrawY, SIZE, color, cub3D);
			startDrawX++;
		}
		startDrawX = x - SIZE_OF_PLAYER / 2;
		startDrawY++;
	}
	
	draw_cub_in_pixel2D(x - SIZE / 2, y - SIZE / 2, SIZE, 0x00FF0000, cub3D);
 
	ft_draw_corner_cubes(cub3D, 'L', 'U', cub3D->player->player2D->color_minicubeLU);
	ft_draw_corner_cubes(cub3D, 'L', 'D', cub3D->player->player2D->color_minicubeLD);
	ft_draw_corner_cubes(cub3D, 'R', 'U', cub3D->player->player2D->color_minicubeRU);
	ft_draw_corner_cubes(cub3D, 'R', 'D', cub3D->player->player2D->color_minicubeRD);

	ft_draw_cross2D(cub3D); // отрисовка креста

	ft_draw_rays(cub3D); // отрисовка лучей

}

/*
* Заливка фона
*/
static void		ft_fill_background(t_cub3D *cub3D)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < cub3D->screen->w)
	{
		while (y < cub3D->screen->h)
		{
			my_mlx_pixel_put(cub3D->mlx_img, x, y, 0x00696969);
			y++;
		}
		y = 0;
		x++;
	}
}

void			ft_start_game(t_cub3D *cub3D)
{
	//ft_print_structs(cub3D);

	cub3D->env->img = mlx_new_image(cub3D->env->mlx, cub3D->screen->w, cub3D->screen->h);
	cub3D->mlx_img->addr = mlx_get_data_addr(cub3D->env->img, &cub3D->mlx_img->bits_per_pixel, &cub3D->mlx_img->line_length,
                                &cub3D->mlx_img->endian);
	ft_fill_background(cub3D);
	/*
	* отрисовывание 2д карты
	* // TODO возможно переделать ее по причине наличия
	* идентичной функции 	
	*/
	ft_draw_cub_in_pos(cub3D);
	ft_draw_user(cub3D);			// отрисовка персонажа
	ft_move_player(cub3D);			// функция отвечающая за передвижение персонажа

	mlx_put_image_to_window(cub3D->env->mlx, cub3D->env->win, cub3D->env->img, 0, 0);
 
	//Degree
	mlx_string_put(cub3D->env->mlx, cub3D->env->win, cub3D->player->posX - (SIZE_OF_PLAYER / 2 - 5), cub3D->player->posY + (SIZE_OF_PLAYER / 2 + 10), 0x00FF0000, ft_itoa(cub3D->player->degree));
	//X
	mlx_string_put(cub3D->env->mlx, cub3D->env->win, cub3D->player->posX + (SIZE_OF_PLAYER / 2 + 5), cub3D->player->posY + (SIZE_OF_PLAYER / 2 + 10), 0x00FF0000, ft_itoa(cub3D->player->posX));
	//Y
	mlx_string_put(cub3D->env->mlx, cub3D->env->win, cub3D->player->posX + (SIZE_OF_PLAYER / 2 + 35), cub3D->player->posY + (SIZE_OF_PLAYER / 2 + 10), 0x00FF0000, ft_itoa(cub3D->player->posY));
}