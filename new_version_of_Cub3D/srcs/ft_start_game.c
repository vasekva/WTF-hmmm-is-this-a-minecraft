#include "cub3D.h"
#include "mlx.h"

static void            my_mlx_pixel_put(t_mlx *mlx_img, int x, int y, int color)
{
    char    *dst;

    dst = mlx_img->addr + (y * mlx_img->line_length + x * (mlx_img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void		ft_draw_cub_from_cubs(t_cub3D *cub3D)
{
	int posX;
	int posY;
	int x;
	int y;

	posY = 0;
	posX = 0;
	y = 0;
	x = 0;

	int size_of_block = 20;
	int count_of_block_in_array_y = cub3D->parser->count_of_map_lines;
	int	count_of_block_in_array_x = cub3D->parser->max_strlen_of_map;
	printf("Y: %d\n", count_of_block_in_array_y);
	printf("X: %d\n", count_of_block_in_array_x);
	while (y < count_of_block_in_array_y)
	{
		while (x < count_of_block_in_array_x)
		{
			// if (cub3D->array[y][x] == '1')
			// 	for (int posY = y; posY < y + 40; posY++)
			// 		for (int posX = x; posX < x + 40; posX++)
						// my_mlx_pixel_put(cub3D->mlx_img, posY, posX, 0x00FF0000);

			if (cub3D->array[y][x] == '1')
				my_mlx_pixel_put(cub3D->mlx_img, y, x, 0x00FF0000);

			printf("%c", cub3D->array[y][x]);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}

void					ft_draw_user(t_cub3D *cub3D)
{
	int	posX = cub3D->player->posX;
	int posY = cub3D->player->posY;

	for (int x = 0; x < SIZE_OF_PLAYER; x++)
	{
		for (int y = 0; y < SIZE_OF_PLAYER; y++)
		{
			my_mlx_pixel_put(cub3D->mlx_img, posY, posX, 0x00FFFF00);
			posY++;
		}
		posY = cub3D->player->posY;
		posX++;
	}
}

int					ft_start_game(void *param)
{
	printf("FUuUUUUUUUUUUUUUUUU\n");

	t_cub3D   *cub3D;

	cub3D = (t_cub3D *)param;
	// cub3D->env->mlx = mlx_init();
    // cub3D->env->win = mlx_new_window(cub3D->env->mlx, cub3D->screen->w, cub3D->screen->h, "cub3D");
	cub3D->env->img = mlx_new_image(cub3D->env->mlx, cub3D->screen->w, cub3D->screen->h);
	cub3D->mlx_img->addr = mlx_get_data_addr(cub3D->env->img, &cub3D->mlx_img->bits_per_pixel, &cub3D->mlx_img->line_length,
                                &cub3D->mlx_img->endian);

	ft_draw_user(cub3D);

	ft_draw_cub_from_cubs(cub3D);	//рисует карту и массив в консоль		

	mlx_put_image_to_window(cub3D->env->mlx, cub3D->env->win, cub3D->env->img, 0, 0);
	mlx_loop(cub3D->env->mlx);
	return (1);
}

// void					ft_start_game(t_cub3D *cub3D)
// {
//     void    *mlx;
//     void    *mlx_win;
//     t_mlx  img;

// 	// cub3D->env->mlx = mlx_init();
//     // cub3D->env->win = mlx_new_window(cub3D->env->mlx, cub3D->screen->w, cub3D->screen->h, "cub3D");
// 	cub3D->env->img = mlx_new_image(cub3D->env->mlx, cub3D->screen->w, cub3D->screen->h);
// 	cub3D->mlx_img->addr = mlx_get_data_addr(cub3D->env->img, &cub3D->mlx_img->bits_per_pixel, &cub3D->mlx_img->line_length,
//                                 &cub3D->mlx_img->endian);

// 	ft_draw_user(cub3D);

// 	ft_draw_cub_from_cubs(cub3D);	//рисует карту и массив в консоль		

// 	mlx_put_image_to_window(cub3D->env->mlx, cub3D->env->win, cub3D->env->img, 0, 0);
// 	mlx_loop(cub3D->env->mlx);
// }