#include "cub3D.h"

/*
* Возвращает персонажу стандартные цвета заливки
*/
void	ft_set_standart_colors(t_cub3D *cub3D)
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
		cub3D->player->player2D->color_of_player = player_color;
	if (cub3D->player->player2D->color_of_cross == 0x00FF0000)
		cub3D->player->player2D->color_of_cross = cub3D->player->player2D->color_of_player;
}

/*
* Меняет цвета различных "датчиков"(угловых блоков) 
* и самого персонажа в зависимости от угла под которым он
* приблизился к стене
*/
void	ft_change_color(t_cub3D *cub3D)
{
	if (cub3D->player->degree > 269 && cub3D->player->degree < 271)
	{
		cub3D->player->player2D->color_minicubeLU = 0x00FF0000;
		cub3D->player->player2D->color_minicubeRU = 0x00FF0000;
	}
	// вправо вверх
	if (cub3D->player->degree > 271 && cub3D->player->degree < 359)
	{
		cub3D->player->player2D->color_minicubeRU = 0x00FF0000;
	}
	// вправо
	if (cub3D->player->degree > 359 || cub3D->player->degree < 0) // TODO ПОЧЕМУ встречается МЕНЬШЕ 0???
	{
		cub3D->player->player2D->color_minicubeRU = 0x00FF0000;
		cub3D->player->player2D->color_minicubeRD = 0x00FF0000;
	}
	// вправо вниз
	if (cub3D->player->degree > 1 && cub3D->player->degree < 89)
	{
		cub3D->player->player2D->color_minicubeRD = 0x00FF0000;
	}
	// вниз
	if (cub3D->player->degree > 89 && cub3D->player->degree < 91)
	{
		cub3D->player->player2D->color_minicubeRD = 0x00FF0000;
		cub3D->player->player2D->color_minicubeLD = 0x00FF0000;
	}
	// влево вниз
	if (cub3D->player->degree > 91 && cub3D->player->degree < 179)
	{
		cub3D->player->player2D->color_minicubeLD = 0x00FF0000;
	}
	// влево
	if (cub3D->player->degree > 179 && cub3D->player->degree < 181)
	{
		cub3D->player->player2D->color_minicubeLD = 0x00FF0000;
		cub3D->player->player2D->color_minicubeLU = 0x00FF0000;
	}
	// влево вверх
	if (cub3D->player->degree > 181 && cub3D->player->degree < 269)
	{
		cub3D->player->player2D->color_minicubeLU = 0x00FF0000;
	}
	cub3D->player->player2D->color_of_player = 0x00000000;
	cub3D->player->player2D->color_of_cross = 0x00FF0000;
}

/*
* Расчитывает координаты X и Y пересечений луча со следующим блоком 
* относительно направления взгляда и определяет координаты найденной ячейки
*/
void	ft_define_next_block(t_cub3D *cub3D)
{
	//верх
	if (cub3D->player->degree > 225 && cub3D->player->degree < 315)
	{
		cub3D->player->ray_coords->Xa = -SIZE_OF_CUB / tan(cub3D->player->posA);
		cub3D->player->ray_coords->Ya = -SIZE_OF_CUB;
		cub3D->player->ray_coords->arrayY = ((int)cub3D->player->posY / SIZE_OF_CUB) * SIZE_OF_CUB - 1;
		cub3D->player->ray_coords->arrayX = (cub3D->player->posX + (cub3D->player->posY - cub3D->player->ray_coords->arrayY) / -tan(cub3D->player->posA)); //TODO почему -tan ?? (cкорее всего из-за реверсивной системы)
	}
	//низ
	if (cub3D->player->degree > 45 && cub3D->player->degree < 135)
	{
		cub3D->player->ray_coords->Xa = SIZE_OF_CUB / tan(cub3D->player->posA);
		cub3D->player->ray_coords->Ya = SIZE_OF_CUB;
		cub3D->player->ray_coords->arrayY = ((int)cub3D->player->posY / SIZE_OF_CUB) * SIZE_OF_CUB + SIZE_OF_CUB;
		cub3D->player->ray_coords->arrayX = (cub3D->player->posX + (cub3D->player->posY - cub3D->player->ray_coords->arrayY) / -tan(cub3D->player->posA));
	}
	//право
	if (cub3D->player->degree > 315 || cub3D->player->degree < 45)
	{
		cub3D->player->ray_coords->Xa = SIZE_OF_CUB;
		cub3D->player->ray_coords->Ya = SIZE_OF_CUB * tan(cub3D->player->posA);
		cub3D->player->ray_coords->arrayX = ((int)cub3D->player->posX / SIZE_OF_CUB) * SIZE_OF_CUB + SIZE_OF_CUB;
		cub3D->player->ray_coords->arrayY = (cub3D->player->posY + (cub3D->player->posX - cub3D->player->ray_coords->arrayX) * -tan(cub3D->player->posA)); //TODO почему -tan ?? (cкорее всего из-за реверсивной системы)
	}
	//лево
	if (cub3D->player->degree < 225 && cub3D->player->degree > 135)
	{
		cub3D->player->ray_coords->Xa = -SIZE_OF_CUB;
		cub3D->player->ray_coords->Ya = -SIZE_OF_CUB * tan(cub3D->player->posA);
		cub3D->player->ray_coords->arrayX = ((int)cub3D->player->posX / SIZE_OF_CUB) * SIZE_OF_CUB - 1;
		cub3D->player->ray_coords->arrayY = (cub3D->player->posY + (cub3D->player->posX - cub3D->player->ray_coords->arrayX) * -tan(cub3D->player->posA)); //TODO почему -tan ?? (cкорее всего из-за реверсивной системы)
	}
	cub3D->player->ray_coords->arrayX /= SIZE_OF_CUB;
	cub3D->player->ray_coords->arrayY /= SIZE_OF_CUB; 
}

/*
* Главная функция отвечающая за передвижения персонажа
* посредством определения нажатых клавиш и вызова
* вспомогательных функций
*/
int	ft_player_control(t_cub3D *cub3D)
{
	if (cub3D->player->leftAKey == 1)
	{
		cub3D->player->posDirX = cos(cub3D->player->posA - 1.5839) * MOVE_SPEED;
		cub3D->player->posDirY = sin(cub3D->player->posA - 1.5839) * MOVE_SPEED;
		cub3D->player->posX += cub3D->player->posDirX;                                
		cub3D->player->posY += cub3D->player->posDirY;
	}
	if (cub3D->player->rightDKey == 1)
	{
		cub3D->player->posDirX = cos(cub3D->player->posA - 1.5839) * MOVE_SPEED;
		cub3D->player->posDirY = sin(cub3D->player->posA - 1.5839) * MOVE_SPEED;
		cub3D->player->posX -= cub3D->player->posDirX;
		cub3D->player->posY -= cub3D->player->posDirY;
	}
	/*
	* поворот луча влево и вправо
	*/
	if (cub3D->player->leftKey == 1)
	{
		cub3D->player->posA -= 0.1;
		cub3D->player->degree = cub3D->player->posA * (180 / PI);
		if (cub3D->player->posA < 0)
		{
			cub3D->player->posA += 2 * PI;
		}
	}
	if (cub3D->player->rightKey == 1)
	{
		cub3D->player->posA += 0.1;
		cub3D->player->degree = cub3D->player->posA * (180 / PI);
		if (cub3D->player->posA > 2 * PI)
		{
			cub3D->player->posA -= 2 *PI;
		}
	}
	if (cub3D->player->upKey == 1)
	{
			ft_define_next_block(cub3D);
			if (cub3D->array[cub3D->player->ray_coords->arrayY][cub3D->player->ray_coords->arrayX] == '1')
			{
				ft_change_color(cub3D);
			}
			else
			{
				ft_set_standart_colors(cub3D);
			}
			cub3D->player->posDirX = cos(cub3D->player->posA) * MOVE_SPEED;
			cub3D->player->posDirY = sin(cub3D->player->posA) * MOVE_SPEED;

			cub3D->player->posX += cub3D->player->posDirX;
			cub3D->player->posY += cub3D->player->posDirY;

		}
	if (cub3D->player->downKey == 1)
	{	
		ft_set_standart_colors(cub3D);
		cub3D->player->posDirX = cos(cub3D->player->posA) * MOVE_SPEED;
		cub3D->player->posDirY = sin(cub3D->player->posA) * MOVE_SPEED;

		cub3D->player->posX -= cub3D->player->posDirX;
		cub3D->player->posY -= cub3D->player->posDirY;
	}
	return (0);
}
