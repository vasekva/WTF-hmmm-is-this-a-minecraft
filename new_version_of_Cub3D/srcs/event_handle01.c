#include "cub3D.h"

int     keyrelease_hook(int key, void *param)
{
	t_cub3D *cub3D;

	if (param)
	{
		cub3D = (t_cub3D *)param;
		if (key == LEFT)
		{
			printf("LEFT\n");
		}
		if (key == RIGHT)
		{

			printf("RIGHT\n");
		}
		if (key == UP)
		{
			printf("UP\n");
		}
		if (key == DOWN)
		{
			printf("DOWN\n");
		}
	}
	return (1);
}

int	keypress_hook(int key, void *param)
{
	t_cub3D *cub3D;
	int arrayY = 0;
	int arrayX = 0;
	int Xa = 0;
	int Ya = 0;

	if (param)
	{
		cub3D = (t_cub3D *)param;
		if (key == ESC)
            exit(0);
		if (key == LEFT)
		{
			cub3D->player->posA -= 0.1;
			cub3D->player->degree = cub3D->player->posA * (180 / PI);
			if (cub3D->player->posA < 0)
			{
				cub3D->player->posA += 2 * PI;
			}
			cub3D->player->posDirX = cos(cub3D->player->posA) * 5;
			cub3D->player->posDirY = sin(cub3D->player->posA) * 5;
		}
		if (key == RIGHT)
		{
			cub3D->player->posA += 0.1;
			cub3D->player->degree = cub3D->player->posA * (180 / PI);
			if (cub3D->player->posA > 2 * PI)
			{
				cub3D->player->posA -= 2 *PI;
			}
			cub3D->player->posDirX = cos(cub3D->player->posA) * 5;
			cub3D->player->posDirY = sin(cub3D->player->posA) * 5;
		}
		if (key == UP)
		{
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
			arrayX /= SIZE_OF_CUB;
			arrayY /= SIZE_OF_CUB; 
			printf("AX %d AY %d\n", arrayX, arrayY);
			if (cub3D->array[arrayY][arrayX] == '1')
			{
				printf("WALL\n");
				// вверх
				if (cub3D->player->degree > 269 && cub3D->player->degree < 271)
				{
					cub3D->player->player2D->color_minicubeLU = 0x00FF0000;
					cub3D->player->player2D->color_minicubeRU = 0x00FF0000;
					cub3D->player->player2D->color_of_player = 0x00000000;
				}
				// вправо вверх
				if (cub3D->player->degree > 271 && cub3D->player->degree < 359)
				{
					cub3D->player->player2D->color_minicubeRU = 0x00FF0000;
					cub3D->player->player2D->color_of_player = 0x00000000;
				}
				// вправо
				if (cub3D->player->degree > 359)
				{
					cub3D->player->player2D->color_minicubeRU = 0x00FF0000;
					cub3D->player->player2D->color_minicubeRD = 0x00FF0000;
					cub3D->player->player2D->color_of_player = 0x00000000;
				}
				// вправо вниз
				if (cub3D->player->degree > 1 && cub3D->player->degree < 89)
				{
					cub3D->player->player2D->color_minicubeRD = 0x00FF0000;
					cub3D->player->player2D->color_of_player = 0x00000000;
				}
				// вниз
				if (cub3D->player->degree > 89 && cub3D->player->degree < 91)
				{
					cub3D->player->player2D->color_minicubeRD = 0x00FF0000;
					cub3D->player->player2D->color_minicubeLD = 0x00FF0000;
					cub3D->player->player2D->color_of_player = 0x00000000;
				}
				// влево вниз
				if (cub3D->player->degree > 91 && cub3D->player->degree < 179)
				{
					cub3D->player->player2D->color_minicubeLD = 0x00FF0000;
					cub3D->player->player2D->color_of_player = 0x00000000;
				}
				// влево
				if (cub3D->player->degree > 179 && cub3D->player->degree < 181)
				{
					cub3D->player->player2D->color_minicubeLD = 0x00FF0000;
					cub3D->player->player2D->color_minicubeLU = 0x00FF0000;
					cub3D->player->player2D->color_of_player = 0x00000000;
				}
				// влево вверх
				if (cub3D->player->degree > 181 && cub3D->player->degree < 269)
				{
					cub3D->player->player2D->color_minicubeLU = 0x00FF0000;
					cub3D->player->player2D->color_of_player = 0x00000000;
				}
				//cub3D->player->color_minicubes = 0x00FF0000;
				// ft_draw_corner_cubes(cub3D, 'R', 'D', 0x00FF0000);
			}
			else
			{
				if (cub3D->player->player2D->color_minicubeRU == 0x00FF0000)
					cub3D->player->player2D->color_minicubeRU = 0x0000FF00;
				if (cub3D->player->player2D->color_minicubeRD == 0x00FF0000)
					cub3D->player->player2D->color_minicubeRD = 0x0000FF00;
				if (cub3D->player->player2D->color_minicubeLU == 0x00FF0000)
					cub3D->player->player2D->color_minicubeLU = 0x0000FF00;
				if (cub3D->player->player2D->color_minicubeLD == 0x00FF0000)
					cub3D->player->player2D->color_minicubeLD = 0x0000FF00;
				if (cub3D->player->player2D->color_of_player == 0x00000000)
				cub3D->player->player2D->color_of_player = 0x009932CC;
			}
			cub3D->player->posX += cub3D->player->posDirX;
			cub3D->player->posY += cub3D->player->posDirY;
		}
		if (key == DOWN)
		{	
			if (cub3D->player->player2D->color_minicubeRU == 0x00FF0000)
				cub3D->player->player2D->color_minicubeRU = 0x0000FF00;
			if (cub3D->player->player2D->color_minicubeRD == 0x00FF0000)
				cub3D->player->player2D->color_minicubeRD = 0x0000FF00;
			if (cub3D->player->player2D->color_minicubeLU == 0x00FF0000)
				cub3D->player->player2D->color_minicubeLU = 0x0000FF00;
			if (cub3D->player->player2D->color_minicubeLD == 0x00FF0000)
				cub3D->player->player2D->color_minicubeLD = 0x0000FF00;
			if (cub3D->player->player2D->color_of_player == 0x00000000)
				cub3D->player->player2D->color_of_player = 0x009932CC;
			cub3D->player->posX -= cub3D->player->posDirX;
			cub3D->player->posY -= cub3D->player->posDirY;
		}
		// if (cub3D->player->color_minicubes == 0x00FF0000)
		// 	cub3D->player->color_minicubes = 0x0000FF00;
	}
	return (1);
}