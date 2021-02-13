#include "cub3D.h"

static int	ft_pow(int num, int i)
{
	int count;

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
int			ft_parse_int(char *str)
{
	int i;
	int	sum;
	int len;

	len = ft_strlen(str);
	i = 0;
	sum = 0;
	while (i < len)
	{
		int n = str[len - (i + 1)] - '0';
		sum = sum + ft_pow(n, i);
		i++;
	}
	return (sum);
}

/*
* Используется парсером в ft_parse
*/
int			ft_isidentifier(char *str)
{
	int i;

	i = 0;
	if (str[i] == 'R' && str[i + 1] == ' ')
		return (1);
	if (str[i] == 'S' && str[i + 1] == ' ')
		return (1);
	if (str[i] == 'F' && str[i + 1] == ' ')
		return (1);
	if (str[i] == 'C' && str[i + 1] == ' ')
		return (1);						
	if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		return (1);
	if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		return (1);
	if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		return (1);
	if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		return (1);
	return (-1);
}