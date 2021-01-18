#include <fcntl.h>
#include <stdio.h>
#include "./get_next_line/get_next_line.h"
#include "./mlx/mlx.h"

#define mapWidth 24
#define mapHeight 24
#define w 1280
#define h 1024

int		ft_abs(int num);
int		create_trgb(int t, int r, int g, int b);

int		main(void)
{
	//char	world_map[mapWidth][mapHeight];

    // int		fd;
	// int		i;
	// char	*line;
    // int		num_of_line;
    // int		j;

	// num_of_line = 0;
	// j = 0;
	// fd = open("map.txt", O_RDONLY);
	// while ((i = get_next_line(fd, &line)) >= 0)
	// {
	// 	j = 0;
	// 	while (line[j] != '\0')
	// 	{
	// 		world_map[num_of_line][j] = line[j];
	// 		j++;
	// 	}
	// 	printf("%s\n", world_map[num_of_line]);
	// 	num_of_line++;
	// 	free(line);
    //     if (i == 0)
    //         break;
	// }
	// if (i < 0)
	// 	printf("All is good");

	int world_map[mapWidth][mapHeight] =
	{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	double	posX = 22; // стартовая позиция X
	double	posY = 12; // стартовая позиция Y
	double	dirX = -1; // начальный вектор направления по X
	double	dirY = 0; // начальный вектор направления по Y
	double	planeX = 0;
	double	planeY = 0.66;

	// double	time = 0; // время текущего кадра
	// double	oldTime = 0; // время предыдущего кадра

	void    *mlx;
    void    *mlx_win;

	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, w, h, "Hello world!");
	int y = 50;
	int x;
	// while (y++ < 200)
	// {
	// 	x = 50;
	// 	while (x < 200)
	// 	{
	// 		if (x < 55 || y < 55 || x > 195 || y > 195)
	// 			mlx_pixel_put(mlx, mlx_win, x, y, 0xFFFFFF);
	// 		else
	// 			mlx_pixel_put(mlx, mlx_win, x, y, 0xFFCC99);
	// 			x++;
	// 		// x = cos(x) + cos(y);
	// 	}
	// }
	int		done = 0;
	while (!done)
	{
		for(int x = 0; x < w; x++)
		{
			// вычисляем положение и направление луча
			double cameraX = 2 * x / (double)(w) - 1; //x - координата в пространстве камеры
			double rayDirX = dirX + planeX * cameraX;
			double rayDirY = dirY + planeY * cameraX;

			// в каком квадрате карты мы находимся
			int mapX = (int)(posX);
			int mapY = (int)(posY);

			// длина луча от текущей позиции до следующей x или y стороны
			double sideDistX;
			double sideDistY;

			// длина луча от текущей стороны x или y до следующей стороны x или y
			// double deltaDistX = ft_abs(1 / rayDirX);
			// double deltaDistY = ft_abs(1 / rayDirY);
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
				sideDistX = (posX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (posY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
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
				perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
			else           
				perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

			// Рассчитываем высоту линии для рисования на экране
			int lineHeight = (int)(h / perpWallDist);

			// вычисляем самый низкий и самый высокий пиксели для заполнения текущей полосы
			int drawStart = -lineHeight / 2 + h / 2;
			if (drawStart < 0)
				drawStart = 0;
			int drawEnd = lineHeight / 2 + h / 2;
			if (drawEnd >= h)
				drawEnd = h - 1;

			printf("DS: %d DE: %d\n", drawStart, drawEnd);
			int y = drawStart;
			int x = drawStart;

			if (drawEnd < drawStart) {drawStart += drawEnd; drawEnd = drawStart - drawEnd; drawStart -= drawEnd;} //swap y1 and y2
			if (drawEnd < 0 || drawStart >= h  || x < 0 || x >= w) return 0; //no single point of the line is on screen
			if (drawStart < 0) drawStart = 0; //clip
			if (drawEnd >= w) drawEnd = h - 1; //clip

			for(int x = 0; x <= drawStart; x++)
				for(int y = drawStart; y <= drawEnd; y++)
				{
					mlx_pixel_put(mlx, mlx_win, x, y, 0xFFCC99);
				}
			// while (y++ < drawEnd)
			// {
			// 	x = drawStart;
			// 	while (x++ < drawEnd)
			// 	{
			// 		mlx_pixel_put(mlx, mlx_win, x, y, 0xFFCCC9);
			// 	}
			// }
		}
		mlx_loop(mlx);
	}
}