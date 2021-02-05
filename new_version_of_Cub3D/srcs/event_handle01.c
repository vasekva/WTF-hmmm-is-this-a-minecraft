#include "cub3D.h"

// void     keyrelease_hook(int key, void *param)
// {
//     t_cub3D   *cub3D;

//     if (param)
//     {
//         cub3D = (t_cub3D *)param;
//         if (key == LEFT || key == RIGHT)
//             cub3D->player->mv_h_bool = 0;
//         if (key == UP || key == DOWN)
//             cub3D->player->mv_v_bool = 0;  
//     }
//     return (1);
// }

int	keypress_hook(int key, void *param)
{
	t_cub3D *cub3D;

	if (param)
	{
		cub3D = (t_cub3D *)param;
		if (key == LEFT)
		{
			//cub3D->player->posX -= 5;
			printf("LEFT\n");
		}
		if (key == RIGHT)
		{
			//cub3D->player->posX += 5;
			printf("RIGHT\n");
		}
		if (key == UP)
		{
			//cub3D->player->posY -= 5;
			printf("UP\n");
		}
		if (key == DOWN)
		{
			//cub3D->player->posY += 5;
			printf("DOWN\n");
		}
	}
	return (1);
}