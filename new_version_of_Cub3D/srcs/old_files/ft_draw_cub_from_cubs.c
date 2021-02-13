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
	int count_of_block_in_array = 50;

	while (posY < size_of_block * count_of_block_in_array)
	{
		while (posX < size_of_block * count_of_block_in_array)
		{
			while (y + posY < (size_of_block + posY) - 1)
			{
				while (x + posY < (size_of_block + posY) - 1)
				{
					my_mlx_pixel_put(cub3D->mlx_img, x + posX, y + posY, 0x00FF0000);
					x++;
				}
				x = 0;
				y++;
			}
			y = 0;
			posX+= size_of_block;
		}
		posX = 0;
		posY += size_of_block;
	}
}