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