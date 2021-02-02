#include "cub3D.h"
#include "mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


int             main(void)
{
	t_cub cub;
    int moveX;
	int moveY;

    void    *mlx;
    void    *mlx_win;
    t_data  img;

    cub.map = get_map();
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    /*
    ** Отрисовка карты *
    */
    for (int x = 0; x < MAP_H; x++)
    {
        for (int y = 0; y < MAP_W; y++)
        {
            moveX = x * PIXEL_SIZE;
            moveY = y * PIXEL_SIZE;
            if (cub.map[x][y] == '1')
            {
                printf("hello");
                for (int n = 0; n < PIXEL_SIZE - 1; n++)
                {
                    for (int num = 0; num < PIXEL_SIZE - 1; num++)
                    {
                        my_mlx_pixel_put(&img, moveX + n, moveY + num, WHITE);
                    }
                }
            }
        }
    }
    /*
    ** Конец отрисовки карты ***
    */

    /*
    ** Отрисовка игрока *
    */
    int posX = 30;
	int posY = 30;

	moveX = posX * PIXEL_SIZE;
	moveY = posY * PIXEL_SIZE;

	for (int n = 0; n < PIXEL_SIZE / 2; n++)
	{
		for (int num = 0; num < PIXEL_SIZE / 2; num++)
		{
			my_mlx_pixel_put(&img, moveX + n, moveY + num, GREEN);
		}
	}
    /*
    ** Конец отрисовки игрока ***
    */

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}