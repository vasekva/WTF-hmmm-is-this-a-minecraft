#include "cub3D.h"

#define roundf(x) floor(x + 0.5f)

static void			my_mlx_pixel_put(t_mlx *mlx_img, int x, int y, int color)
{
    char    *dst;

    dst = mlx_img->addr + (y * mlx_img->line_length + x * (mlx_img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int		max(int x, int y)
{
	return (x > y ? x : y);
}

int		abs(int num)
{
	return (num > 0 ? num : -num);
}

void	print_DDALine(float x1, float y1, float x2, float y2, t_cub3D *cub3D, int color)
{
	// (1) Целочисленные значения координат начала и конца отрезка,
	// округленные до ближайшего целого
	int		iX1 = roundf(x1);
	int		iY1 = roundf(y1);
	int		iX2 = roundf(x2);
	int		iY2 = roundf(y2);

	// (2) Длина и высота линии
	int deltaX = abs(iX1 - iX2);
	int deltaY = abs(iY1 - iY2);

	// (3) Считаем минимальное количество итераций, необходимое
	// для отрисовки отрезка. Выбирая максимум из длины и высоты
	// линии, обеспечиваем связность линии
	int length = max(deltaX, deltaY);

	// особый случай, на экране закрашивается ровно один пиксель
    if (length == 0)
    {
		my_mlx_pixel_put(cub3D->mlx_img, iX1, iY1, color);
        return;
    }
    // (4) Вычисляем приращения на каждом шаге по осям абсцисс и ординат
	double dX = (x2 - x1) / length;
	double dY = (y2 - y1) / length;

	// (5)  Начальные значения
	double x = x1;
	double y = y1;

	// Основной цикл
	length++;
	while (length--)
	{
		x += dX;
		y += dY;
		my_mlx_pixel_put(cub3D->mlx_img, roundf(x), roundf(y), color);
	}
}