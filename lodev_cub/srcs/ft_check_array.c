#include "cub3D.h"

void	ft_check_last_lines(t_cub3D *cub3D)
{
	int line;
	int j;
	int i;

	j = 0;
	line = cub3D->array->size - 1;;
	i = cub3D->array->size - 1;
	// i = 0;
	// проходим по пробельным символам
	while (cub3D->array->map_arr[i][j] == ' ')
	{
		j++;
	}
	// если символ после пробела не равен стене
	if (cub3D->array->map_arr[i][j] != '1')
		exception(TWENTYFOUR);
}

void	ft_check_top_lines(t_cub3D *cub3D)
{
	int line;
	int j;

	j = 0;
	line = 0;
	// проходим по пробельным символам
	while (cub3D->array->map_arr[0][j] != '\0'
		&& cub3D->array->map_arr[0][j] == ' ')
	{
		// спускаемся по каждому пробельному столбцу вниз
		while (cub3D->array->map_arr[line] != NULL)
		{
			if (cub3D->array->map_arr[line][j] == '0'
				|| cub3D->array->map_arr[line][j] == '2')
			{
				exception(TWENTYONE);
			}
			if (cub3D->array->map_arr[line][j] == '1')
				break;
			// если мы пришли в угол ограниченный справа и снизу
			if (cub3D->array->map_arr[line][j + 1] == '1'
				&& cub3D->array->map_arr[line + 1] != NULL
				&& cub3D->array->map_arr[line + 1][j] == '1')
			{
				if (cub3D->array->map_arr[line + 1][j + 1] == '0')
					exception(TWENTYFIVE);
			}
			line++;
		}
		line = 0;
		j++;
	}
	// проходим по непробельным символам в строке
	while (cub3D->array->map_arr[0][j] != '\0')
	{
		if (cub3D->array->map_arr[0][j] != '1')
		{
			exception(TWENTYONE);
		}
		j++;
	}
}

void	ft_check_longline(t_cub3D *cub3D, int line, int diff)
{
	int i;
	int j;

	printf("HELLO\n");
	if (diff < 0)
		diff *= -1;
	j = 0;
	i = ft_strlen(cub3D->array->map_arr[line]) - 1;
	if (diff == 1 && cub3D->array->map_arr[line][i - 1] != '1')
	{
		exception(TWENTYFIVE);
	}
	else
	{
		// пока мы не дойдем до значения разницы
		while (j < diff)
		{
			// если текущий символ в строке не равен стене
			if (cub3D->array->map_arr[line][(i - 1) - j] != '1')
			{
				// проверка верхней строки 
				if (cub3D->array->map_arr[line + 1][(i - 1) - j] != '1')
					exception(TWENTYSIX);
				// проверка нижней строки
				if (cub3D->array->map_arr[line - 1][(i - 1) - j] != '1')
					exception(TWENTYSIX);
			}
			j++;
		}
	}
}

void	ft_check_middle_lines(t_cub3D *cub3D, int i)
{
	int j;

	j = 0;
	while (cub3D->array->map_arr[i][j] == ' ')
	{
		// если в строке сверху есть не закрытый 0
		if (cub3D->array->map_arr[i - 1][j] == '0')
		{
			exception(TWENTYTWO);
		}
		// если в строке снизу есть не закрытый 0
		if (cub3D->array->map_arr[i + 1][j] == '0'
			&& cub3D->array->map_arr[i + 1] != NULL)
		{
			exception(TWENTYTHREE);
		}
		// если символ справа не 1 и не ' '
		if (cub3D->array->map_arr[i][j + 1] == '0'
			|| cub3D->array->map_arr[i][j + 1] == '2')
		{
			exception(TWENTYFOUR);
		}
		j++;
	}
}

void	ft_check_array(t_cub3D *cub3D)
{
	int i;
	int j;
	int diff;

	i = 0;
	j = 0;
	diff = 0;
	if (cub3D->array->size < 2)
	{
		exception(EIGHTEEN);
	}
	// проходимся по строкам
	while (cub3D->array->map_arr[i] != NULL)
	{
		// если самая верхняя строка
		if (i == 0)
		{
			ft_check_top_lines(cub3D);
			diff = ft_strlen(cub3D->array->map_arr[i + 1]) - ft_strlen(cub3D->array->map_arr[i]);
			if (diff != 0)
				ft_check_longline(cub3D, i, diff);
		}
		else if (i > 0 && i < cub3D->array->size - 1)
		{
			ft_check_middle_lines(cub3D, i);
			diff = ft_strlen(cub3D->array->map_arr[i + 1]) - ft_strlen(cub3D->array->map_arr[i]);
			if (diff != 0)
				ft_check_longline(cub3D, i, diff);
		}
		else
			ft_check_last_lines(cub3D);
		i++;
	}
}
