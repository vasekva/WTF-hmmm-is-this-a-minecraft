
#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int		ft_abs(int num)
{
	return (num < 0 ? -num : num);
}

/*
**
*/
int     loop_hook(void *param)
{
    t_cub   *cub;
    t_pos   pos;
    t_pos   tmp;

    if (param)
    {
        cub = (t_cub *)param;
        tmp.x = cub->cam->pos.x;
        tmp.y = cub->cam->pos.y;
        // if (cub->vel_v_bool)
        //     move_cam_v(cub->vel_v, cub->cam);
        // if (cub->vel_h_bool)
        //     move_cam_h(cub->vel_h, cub->cam);
        pos.x = cub->cam->pos.x / WALL_W;
        pos.y = cub->cam->pos.y / WALL_H;
        if (cub->map[pos.y][pos.x] == WALL)
        {
            cub->cam->pos.x = tmp.x;
            cub->cam->pos.y = tmp.y;
        }
        else
            (cub->map)[pos.y][pos.x] = VOID;
        //raycaster(cub, cub->cam, cub->map);
    }
    return (0);
}
/*
* Отслеживание зажатой клавиши
*/
static void     aux_press(int key, t_cub *cub)
{
    if (key == UP && !cub->vel_v_bool)
    {
        cub->vel_v = VEL_V;
        cub->vel_v_bool = 1;
		//cub->cam->pos.x++;
		printf("UP\n");
    }
    if (key == DOWN && !cub->vel_v_bool)
    {
        cub->vel_v = -VEL_V;
        cub->vel_v_bool = 1;
    }
}

int             keypress_hook(int key, void *param)
{
    t_cub *cub;

    if (param)
    {
        cub = (t_cub *)param;
        if (key == ESC)
            exit(0);
        if (key == LEFT && !cub->vel_h_bool)
        {
            cub->vel_h = 0.02;
            cub->vel_h_bool = 1;
        }
        if (key == RIGHT && !cub->vel_h_bool)
        {
            cub->vel_h = -0.02;
            cub->vel_h_bool = 1;
        }
        aux_press(key, cub);
    }
    return (1);
}
/**
 * Отслеживание нажатий
 */
int     keyrelease_hook(int key, void *param)
{
    t_cub   *cub;

    if (param)
    {
        cub = (t_cub *)param;
        if (key == LEFT || key == RIGHT)
            cub->vel_h_bool = 0;
        if (key == UP || key == DOWN)
            cub->vel_v_bool = 0;
    }
    return (1);
}
/*
** Отрисовка стен
*/
void	ft_print_wall(t_cub cub, char **world_map, int x, int y, int color)
{
	int moveX = x * PIXEL_SIZE;
	int moveY = y * PIXEL_SIZE;

	if (world_map[x][y] == '1')
	{
	 	for (int n = 0; n < PIXEL_SIZE - 1; n++)
		{
			for (int num = 0; num < PIXEL_SIZE - 1; num++)
			{
				my_mlx_pixel_put(&cub.img, moveX + n, moveY + num, color);
			}
		}
	}
}
/*
** Отрисовка игрока
*/
void	ft_print_player(t_cub cub, int color)
{
	int posX = 30;
	int posY = 30;

	int moveX = posX * PIXEL_SIZE;
	int moveY = posY * PIXEL_SIZE;

	for (int n = 0; n < PIXEL_SIZE / 2; n++)
		{
			for (int num = 0; num < PIXEL_SIZE / 2; num++)
			{
				my_mlx_pixel_put(&cub.img, moveX + n, moveY + num, color);
			}
		}
}

int main(void)
{
	t_cub cub;

    cub.map = get_map();
    double posX = 22; // стартовая позиция игрока по Х
    double posY = 12; // стартовая позиция игрока по Y
    double dirX = -1; // начальный вектор направления по X
    double dirY = 0; // начальный вектор направления по Y
    double planeX = 0;
    double planeY = 0.66;

	// cub.cam->pos.x = 0;
	// cub.cam->pos.y = 0;

	/*
	** Процесс создания окна
	*/

	cub.mlx = mlx_init();
	cub.mlx_win = mlx_new_window(cub.mlx, MAP_H * PIXEL_SIZE * 2, MAP_W * PIXEL_SIZE * 1.5, "Cub3D"); // размер экрана тут
	cub.img.img = mlx_new_image(cub.mlx, MAP_H * PIXEL_SIZE, MAP_W * PIXEL_SIZE);
	cub.img.addr = mlx_get_data_addr(cub.img.img, &cub.img.bits_per_pixel, &cub.img.line_length, &cub.img.endian);

	/*
	** Отрисовка карты 
	*/
	for (int x = 0; x < MAP_H; x++)
	{
		for (int y = 0; y < MAP_W; y++)
		{
			ft_print_wall(cub, cub.map, x, y, WHITE);
			
			// mlx_key_hook(cub.mlx_win, keyrelease_hook, &cub);
			// mlx_hook(cub.mlx_win, 2, 1L<<0, keypress_hook, &cub);
			// mlx_loop_hook(cub.mlx_win, loop_hook, &cub);
			ft_print_player(cub, GREEN);
		}
	}
	
	mlx_put_image_to_window(cub.mlx, cub.mlx_win, cub.img.img, 0, 0);
	mlx_loop(cub.mlx);






	// mlx_win = mlx_new_cub(mlx, screenWidth, screeenHeight, "Cub3D");
    // img.img = mlx_new_image(mlx, screenWidth, screeenHeight);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
    //                              &img.endian);
    // my_mlx_pixel_put(&img, 5, 5, 0x00FFFFFF);
    // mlx_put_image_to_cub(mlx, mlx_win, img.img, 0, 0);
    // mlx_loop(mlx);

	// int w = screen_width;
	// for (int x = 0; x < w; x++)
	// {
	// 	// вычисление положение и направление луча
	// 	double cameraX = 2 * x / (double)w - 1;
	// 	double rayDirX = dirX + planeX * cameraX;
	// 	double rayDirY = dirY + planeY * cameraX;

	// 	// в какой клетке карты мы находимся
    // 	int mapX = (int)(posX);
    // 	int mapY = (int)(posY);

    // 	// длинна луча от текущей позиции до следующей стороны X или Y
    // 	double sideDistX;
    // 	double sideDistY;

	// 	// длинна луча от одной стороны Х или Y до слудующей стороны Х или У
    // 	double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : ft_abs(1 / rayDirX));
    // 	double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : ft_abs(1 / rayDirY));
    // 	double perpWallDist;	

	// 	// какое направление шага по оси x или оси y (либо +1, либо -1)
    // 	int stepX;
    // 	int stepY;
    // 	int side; // какая из стен была поражена, стена NS или EW?
    // 	int hit = 0; // там была стена?
		
	// 	// вычисляем шаг и начальный sideDist
	// 	if (rayDirX < 0)
    //   	{
    //   	  stepX = -1;
    //   	  sideDistX = (posX - mapX) * deltaDistX;
    //   	}
    //   	else
    //   	{
    //   	  stepX = 1;
    //   	  sideDistX = (mapX + 1.0 - posX) * deltaDistX;
    //   	}
    //   	if (rayDirY < 0)
    //   	{
    //   	  stepY = -1;
    //   	  sideDistY = (posY - mapY) * deltaDistY;
    //   	}
    //   	else
    //   	{
    //   	  stepY = 1;
    //   	  sideDistY = (mapY + 1.0 - posY) * deltaDistY;
    //   	}


    //   	//выполнение DDA
    //   	while (hit == 0)
    //   	{
	// 		// переход к следующему квадрату карты ИЛИ по оси x, ИЛИ по оси y
    //   		if (sideDistX < sideDistY)
    //   		{
    //   	    	sideDistX += deltaDistX;
    //   	   		mapX += stepX;
    //   	    	side = 0;
    //   	  	}
    //   	  	else
    //   	  	{
    //   	  	  sideDistY += deltaDistY;
    //   	  	  mapY += stepY;
    //   	  	  side = 1;
    //   	  	}
	// 		// проверяем ударил ли луч стену
    //   	  	if (world_map[mapX][mapY] > 0) hit = 1;
    //   	}

	// 	// Расчет расстояния, проецируемого в направлении камеры (евклидово расстояние даст эффект рыбьего глаза !)
 	// 	if (side == 0)
	// 		perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
    //   	else
	// 	  	perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
		

	// 	int h = screen_height;
    //   	// Рассчитываем высоту линии для рисования на экране
    //    	int lineHeight = (int) (h / perpWallDist);

	//     // вычисляем самый низкий и самый высокий пиксели для заполнения текущей полосы
    //   	int drawStart = -lineHeight / 2 + h / 2;
    //   	if(drawStart < 0)drawStart = 0;
    //   	int drawEnd = lineHeight / 2 + h / 2;
    //   	if(drawEnd >= h)drawEnd = h - 1;

    // 	//choose wall color
    // 	unsigned int color;
    // 	switch(world_map[mapX][mapY])
    // 	{
    // 	  case 1:  color = RED;  break; //red
    // 	  case 2:  color = GREEN;  break; //green
    // 	  case 3:  color = BLUE;   break; //blue
    // 	  case 4:  color = WHITE;  break; //white
    // 	  default: color = YELLOW; break; //yellow
    // 	}
    // 	//give x and y sides different brightness
    // 	if (side == 1) {color = color / 2;}
    // 	//draw the pixels of the stripe as a vertical line
	// 	// for (int y = drawStart; y < drawEnd; y++)
	// 	// {
	// 	// 	my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 	// }
	// 	// mlx_put_image_to_cub(mlx, mlx_win, img.img, 0, 0);
	// 	// mlx_loop(mlx);
    // }
}