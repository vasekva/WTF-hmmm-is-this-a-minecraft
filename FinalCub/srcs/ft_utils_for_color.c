#include "cub3d.h"

static int	ft_pow(int num, int i)
{
	int	count;

	count = 0;
	while (count < i)
	{
		num *= 10;
		count++;
	}
	return (num);
}

/*
* Используется парсером в ft_parse_screen_size
*/
int	ft_parse_int(char *str)
{
	int	i;
	int	sum;
	int	len;
	int	n;

	len = ft_strlen(str);
	i = 0;
	sum = 0;
	while (i < len)
	{
		n = str[len - (i + 1)] - '0';
		sum = sum + ft_pow(n, i);
		i++;
	}
	return (sum);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
