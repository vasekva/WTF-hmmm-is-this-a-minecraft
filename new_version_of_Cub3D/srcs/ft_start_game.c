#include "cub3D.h"
#include "mlx.h"

static void            my_mlx_pixel_put(t_mlx *mlx_img, int x, int y, int color)
{
    char    *dst;

    dst = mlx_img->addr + (y * mlx_img->line_length + x * (mlx_img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

// void		draw_cub_in_pixel(int x, int y, t_cub3D *cub3D)
void		draw_cub_in_pixel(int y, int x, t_cub3D *cub3D)
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

void		ft_draw_cub_from_cubs(t_cub3D *cub3D)
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
			draw_cub_in_pixel(y, x, cub3D);
			x++;
		}
		x = 0;
		y++;
	}
}

void		draw_cub_in_pixel2D(int x, int y, int size, t_cub3D *cub3D)
{
	//int size =;

	int posX = x;
	int posY = y;

	int posXFinal = posX + size;
	int posYFinal = posY + size;
	while (posY < posYFinal)
	{
		while (posX < posXFinal)
		{
			// mlx_pixel_put(mlx, mlx_win, posX, posY, 0x00FF0000);
			my_mlx_pixel_put(cub3D->mlx_img, posX, posY, 0x00FF0000);
			posX++;
		}
		posX = x;
		posY++;
	}
}

void		ft_draw_cub_from_cubs2D(t_cub3D *cub3D)
{
	// int SIZE_OF_PLAYER = 50;
	int SIZE = SIZE_OF_PLAYER / 10;

	int x = cub3D->player->posX;
	int y = cub3D->player->posY;

	int startDrawX = x - SIZE_OF_PLAYER / 2;
	int startDrawY = y - SIZE_OF_PLAYER / 2;

	while (startDrawY < y + SIZE_OF_PLAYER / 2 - SIZE)
	{
		while (startDrawX < x + SIZE_OF_PLAYER / 2 - SIZE)
		{
			if (startDrawY == (y - SIZE_OF_PLAYER / 2) || startDrawX == x - SIZE_OF_PLAYER / 2
			|| startDrawY == (y + SIZE_OF_PLAYER / 2 - SIZE) - 1
			|| startDrawX == (x + SIZE_OF_PLAYER / 2 - SIZE) - 1)
			{
				draw_cub_in_pixel2D(startDrawX, startDrawY, SIZE, cub3D);
			}
			startDrawX++;
		}
		startDrawX = x - SIZE_OF_PLAYER / 2;
		startDrawY++;
	}
	
	int SIZ = SIZE / 2;
	draw_cub_in_pixel2D(x - SIZ, y - SIZ, SIZE, cub3D);
	// draw_cub_in_pixel2D(x - SIZ * 3, y - SIZ * 3, SIZE, cub3D);
	// draw_cub_in_pixel2D(x - SIZ * 5, y - SIZ * 5, SIZE, cub3D);
	// draw_cub_in_pixel2D(x - SIZ * 7, y - SIZ * 7, SIZE, cub3D);

	// draw_cub_in_pixel2D(x - SIZE * 2, y - SIZE * 2, SIZE, cub3D);

	for (int i = 3; i <= 7; i+=2)
	{
		draw_cub_in_pixel2D(x - SIZ * i, y - SIZ * i, SIZE, cub3D);
		draw_cub_in_pixel2D(x + SIZ * (i - 2), y + SIZ * (i - 2), SIZE, cub3D);
		draw_cub_in_pixel2D(x - SIZ * i, y + SIZ * (i - 2), SIZE, cub3D);
		draw_cub_in_pixel2D(x + SIZ * (i - 2), y - SIZ * i, SIZE, cub3D);
		// draw_cub_in_pixel2D(x + SIZ * i, y + SIZ * i, SIZE, cub3D);
	}

}

/*
* Рисует кубик размером 1/5 SIZE_OF_PLAYER в одном из четырех углов
* в зависимости от входных параметров hor_flag & ver_flag цветом int color
*/
void					ft_draw_corner_cubes(t_cub3D *cub3D, char hor_flag, char vert_flag, int color)
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

void					ft_draw_user(t_cub3D *cub3D)
{
		// int SIZE_OF_PLAYER = 50;
	int SIZE = SIZE_OF_PLAYER / 10;

	int x = cub3D->player->posX;
	int y = cub3D->player->posY;

	int startDrawX = x - SIZE_OF_PLAYER / 2;
	int startDrawY = y - SIZE_OF_PLAYER / 2;

	while (startDrawY < y + SIZE_OF_PLAYER / 2 - SIZE)
	{
		while (startDrawX < x + SIZE_OF_PLAYER / 2 - SIZE)
		{
			if (startDrawY == (y - SIZE_OF_PLAYER / 2) || startDrawX == x - SIZE_OF_PLAYER / 2
			|| startDrawY == (y + SIZE_OF_PLAYER / 2 - SIZE) - 1
			|| startDrawX == (x + SIZE_OF_PLAYER / 2 - SIZE) - 1)
			{
				draw_cub_in_pixel2D(startDrawX, startDrawY, SIZE, cub3D);
			}
			startDrawX++;
		}
		startDrawX = x - SIZE_OF_PLAYER / 2;
		startDrawY++;
	}
	
	draw_cub_in_pixel2D(x - SIZE / 2, y - SIZE / 2, SIZE, cub3D);
 
	// print_DDALine(cub3D->player->posX, cub3D->player->posY, Xend, Yend, cub3D, 0x00FF0000);
	// ft_draw_corner_cubes(cub3D, 'L', 'U', cub3D->player->player2D->color_minicubeLU);
	// ft_draw_corner_cubes(cub3D, 'L', 'D', cub3D->player->player2D->color_minicubeLD);
	// ft_draw_corner_cubes(cub3D, 'R', 'U', cub3D->player->player2D->color_minicubeRU);
	// ft_draw_corner_cubes(cub3D, 'R', 'D', cub3D->player->player2D->color_minicubeRD);
	ft_draw_rays(cub3D);
	ft_draw_cub_from_cubs2D(cub3D);

}

// void					ft_draw_user(t_cub3D *cub3D)
// {
// 	int startDrawX = cub3D->player->posX - SIZE_OF_PLAYER / 2;
// 	int startDrawY = cub3D->player->posY - SIZE_OF_PLAYER / 2;

// 	for (int x = 0; x < SIZE_OF_PLAYER; x++)
// 	{
// 		for (int y = 0; y < SIZE_OF_PLAYER; y++)
// 		{
// 			my_mlx_pixel_put(cub3D->mlx_img, startDrawX, startDrawY, cub3D->player->player2D->color_of_player);
// 			startDrawY++;
// 		}
// 		startDrawY = cub3D->player->posY - SIZE_OF_PLAYER / 2;
// 		startDrawX++;
// 	}

// 	int Xend = cub3D->player->posX + cub3D->player->posDirX * 20;
// 	int Yend = cub3D->player->posY + cub3D->player->posDirY * 20;

// 	printf("208 PosX %d PosY %d\n", cub3D->player->posX, cub3D->player->posY);
// 	print_DDALine(cub3D->player->posX, cub3D->player->posY, Xend, Yend, cub3D, 0x00FF0000);
// 	ft_draw_corner_cubes(cub3D, 'L', 'U', cub3D->player->player2D->color_minicubeLU);
// 	ft_draw_corner_cubes(cub3D, 'L', 'D', cub3D->player->player2D->color_minicubeLD);
// 	ft_draw_corner_cubes(cub3D, 'R', 'U', cub3D->player->player2D->color_minicubeRU);
// 	ft_draw_corner_cubes(cub3D, 'R', 'D', cub3D->player->player2D->color_minicubeRD);
// 	ft_draw_rays(cub3D);
// 	ft_draw_cub_from_cubs2D(cub3D);
// }

void					ft_fill_background(t_cub3D *cub3D)
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

void					ft_start_game(t_cub3D *cub3D)
{
	//ft_print_structs(cub3D);

	cub3D->env->img = mlx_new_image(cub3D->env->mlx, cub3D->screen->w, cub3D->screen->h);
	cub3D->mlx_img->addr = mlx_get_data_addr(cub3D->env->img, &cub3D->mlx_img->bits_per_pixel, &cub3D->mlx_img->line_length,
                                &cub3D->mlx_img->endian);
	ft_fill_background(cub3D);

	ft_draw_cub_from_cubs(cub3D);	//рисует карту и массив в консоль		
	ft_draw_user(cub3D);

	mlx_put_image_to_window(cub3D->env->mlx, cub3D->env->win, cub3D->env->img, 0, 0);
 
	//Degree
	mlx_string_put(cub3D->env->mlx, cub3D->env->win, cub3D->player->posX - (SIZE_OF_PLAYER / 2 - 5), cub3D->player->posY + (SIZE_OF_PLAYER / 2 + 10), 0x00FF0000, ft_itoa(cub3D->player->degree));
	//X
	mlx_string_put(cub3D->env->mlx, cub3D->env->win, cub3D->player->posX + (SIZE_OF_PLAYER / 2 + 5), cub3D->player->posY + (SIZE_OF_PLAYER / 2 + 10), 0x00FF0000, ft_itoa(cub3D->player->posX));
	//Y
	mlx_string_put(cub3D->env->mlx, cub3D->env->win, cub3D->player->posX + (SIZE_OF_PLAYER / 2 + 35), cub3D->player->posY + (SIZE_OF_PLAYER / 2 + 10), 0x00FF0000, ft_itoa(cub3D->player->posY));
}