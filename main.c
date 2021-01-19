#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "./get_next_line/get_next_line.h"
#include "./mlx/mlx.h"

#define mapWidth 24
#define mapHeight 24
#define w 1280
#define h 1024

int		ft_abs(int num);
int		create_trgb(int t, int r, int g, int b);

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct  s_vars {
    void        *mlx;
    void        *mlx_win;
    int         key_code;
}               t_vars;

typedef struct	s_coord
{
	int			world_map[mapWidth][mapHeight];
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
}				t_coords;


void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             key_hook(int keycode, t_vars *vars)
{
    //printf("Hello from key_hook! CODE: %d\n", keycode);
    vars->key_code = keycode;
    // 123 <- | 124 -> | 125 -^ | 126 ^

    return (keycode);
}

int		main(void)
{
    t_data  	img;
	t_vars		vars;
	t_coords	coords;


	int 	world_map[mapWidth][mapHeight];
    int		fd;
	int		i;
	char	*line;
    int		num_of_line;
    int		j;


	num_of_line = 0;
	j = 0;
	fd = open("map1.txt", O_RDONLY);
	while ((i = get_next_line(fd, &line)) >= 0)
	{
		while (line[j] != '\0')
		{
			world_map[num_of_line][j] = line[j] - '0';
			printf("%d", world_map[num_of_line][j]);
			j++;
		}
		printf("\n");
		j = 0;
		num_of_line++;
		if (i == 0)
			break;
	}

	coords.posX = 22; // стартовая позиция X
	coords.posY = 12; // стартовая позиция Y
	coords.dirX = -1; // начальный вектор направления по X
	coords.dirY = 0; // начальный вектор направления по Y
	double	planeX = 0;
	double	planeY = 0.66;

	vars.mlx = mlx_init();
    vars.mlx_win = mlx_new_window(vars.mlx, w, h, "Hello world!");
	img.img = mlx_new_image(vars.mlx, w, h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);

    //mlx_key_hook(vars.mlx_win, key_hook, &vars);
	int		done = 0;
	while (!done)
	{
		for(int x = 0; x < w; x++)
		{
			// вычисляем положение и направление луча
			double cameraX = 2 * x / (double)(w) - 1; //x - координата в пространстве камеры
			double rayDirX = coords.dirX + planeX * cameraX;
			double rayDirY = coords.dirY + planeY * cameraX;

			// в каком квадрате карты мы находимся
			int mapX = (int)(coords.posX);
			int mapY = (int)(coords.posY);

			// длина луча от текущей позиции до следующей x или y стороны
			double sideDistX;
			double sideDistY;

			// длина луча от текущей стороны x или y до следующей стороны x или y
			// double deltaDistX = ft_abs(1 / raycoords.dirX);
			// double deltaDistY = ft_abs(1 / raycoords.dirY);
			double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : ft_abs(1 / rayDirX));
			double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : ft_abs(1 / rayDirY));
			double perpWallDist;

			// в каком направлении шагать по оси x или y (либо +1, либо -1)
			int stepX;
			int stepY;

			int hit = 0; // там была стена?
			int side; //was a NS or a EW wall hit?


			// вычисляем шаг и начальный sideDist
			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (coords.posX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - coords.posX) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (coords.posY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - coords.posY) * deltaDistY;
			}

			// выполняем DDA
			while (hit == 0)
			{
				// переход к следующему квадрату карты, ИЛИ по оси x, ИЛИ по оси y
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				// Проверяем, попал ли луч в стену
				if (world_map[mapX][mapY] > 0) hit = 1;
			} 
			// Вычислить расстояние, проецируемое в направлении камеры (евклидово расстояние даст эффект рыбьего глаза !)
			if (side == 0) 
				perpWallDist = (mapX - coords.posX + (1 - stepX) / 2) / rayDirX;
			else           
				perpWallDist = (mapY - coords.posY + (1 - stepY) / 2) / rayDirY;

			// Рассчитываем высоту линии для рисования на экране
			int lineHeight = (int)(h / perpWallDist);

			// вычисляем самый низкий и самый высокий пиксели для заполнения текущей полосы
			int drawStart = -lineHeight / 2 + h / 2;
			if (drawStart < 0)
				drawStart = 0;
			int drawEnd = lineHeight / 2 + h / 2;
			if (drawEnd >= h)
				drawEnd = h - 1;

			//printf("DS: %d DE: %d\n", drawStart, drawEnd);
			int y = drawStart;
			int x = drawStart;

			if (drawEnd < drawStart) {drawStart += drawEnd; drawEnd = drawStart - drawEnd; drawStart -= drawEnd;} //swap y1 and y2
			if (drawEnd < 0 || drawStart >= h  || x < 0 || x >= w) return 0; //no single point of the line is on screen
			if (drawStart < 0) drawStart = 0; //clip
			if (drawEnd >= w) drawEnd = h - 1; //clip

			int color = create_trgb(0, 255, 255, 0);
			// switch (world_map[mapX][mapY])
			// {
			// 	case 1:  color = create_trgb(0, 255, 0, 0);  break; //red
			// 	case 2:  color = create_trgb(0, 0, 255, 0); break; //green
			// 	case 3:  color = create_trgb(0, 0, 0, 255);  break; //blue
			// 	case 4:  color = create_trgb(0, 255, 255, 255);  break; //white
			// 	default: color = create_trgb(0, 255, 255, 0); break; //yellow
			// }

			//if (side == 1) {color = color / 2;}
			
			for(int x = 0; x <= drawStart; x++)
				for(int y = drawStart; y <= drawEnd; y++)
				{
					//vars.mlx_pixel_put(vars.mlx, vars.mlx_win, x, y, color);
					my_mlx_pixel_put(&img, x, y, color);
				}

			double frameTime = 1; //frameTime is the time this frame has taken, in seconds

			double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
			double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

			//move forward if no wall in front of you


			mlx_key_hook(vars.mlx_win, key_hook, &vars);

			if (vars.key_code == 13)
			{
				if(world_map[(int)(coords.posX + coords.dirX * moveSpeed)][(int)(coords.posY)] == 0) coords.posX += coords.dirX * moveSpeed;
				if(world_map[(int)(coords.posX)][(int)(coords.posY + coords.dirY * moveSpeed)] == 0) coords.posY += coords.dirY * moveSpeed;
			}

			// if (keyDown(SDLK_UP))
			// {
			// if(world_map[(int)(coords. + coords.dirX * moveSpeed)][(int)(coords.posY)] == 0) coords. += coords.dirX * moveSpeed;
			// if(world_map[(int)(coords.)][(int)(coords.posY + coords.dirY * moveSpeed)] == 0) coords.posY += coords.dirY * moveSpeed;
			// }
			// //move backwards if no wall behind you
			// if (keyDown(SDLK_DOWN))
			// {
			// if(world_map[(int)(coords. - coords.dirX * moveSpeed)][(int)(coords.posY)] == 0) coords. -= coords.dirX * moveSpeed;
			// if(world_map[(int)(coords.)][(int)(coords.posY - coords.dirY * moveSpeed)] == 0) coords.posY -= coords.dirY * moveSpeed;
			// }
			// //rotate to the right
			// if (keyDown(SDLK_RIGHT))
			// {
			// //both camera direction and camera plane must be rotated
			// double oldcoords.dirX = coords.dirX;
			// coords.dirX = coords.dirX * cos(-rotSpeed) - coords.dirY * sin(-rotSpeed);
			// coords.dirY = oldcoords.dirX * sin(-rotSpeed) + coords.dirY * cos(-rotSpeed);
			// double oldPlaneX = planeX;
			// planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
			// planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
			// }
			// //rotate to the left
			// if (keyDown(SDLK_LEFT))
			// {
			// //both camera direction and camera plane must be rotated
			// double oldcoords.dirX = coords.dirX;
			// coords.dirX = coords.dirX * cos(rotSpeed) - coords.dirY * sin(rotSpeed);
			// coords.dirY = oldcoords.dirX * sin(rotSpeed) + coords.dirY * cos(rotSpeed);
			// double oldPlaneX = planeX;
			// planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
			// planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
			// }	
			// while (y++ < drawEnd)
			// {
			// 	x = drawStart;
			// 	while (x++ < drawEnd)
			// 	{
			// 		vars.mlx_pixel_put(vars.mlx, vars.mlx_win, x, y, 0xFFCCC9);
			// 	}
			// }
		}
		mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
		mlx_loop(vars.mlx);
	}
}