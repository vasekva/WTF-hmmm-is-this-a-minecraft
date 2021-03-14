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

int		ft_read_width(char *str, int c, t_cub3D *cub3D)
{
	int len;

	len = 0;
	while (str[c] == ' ')
		c++;
	if (!ft_isdigit(str[c]))
	{
		if (str[c] == '-')
			exception(SIX);
		else
			exception(SEVEN);
	}
	while (ft_isdigit(str[c]))
	{
		len++;
		c++;
	}
	cub3D->screen->w = ft_parse_int(ft_substr(str, c - len, len));
	return (c);
}

int		ft_read_height(char *str, int c, t_cub3D *cub3D)
{
	int len;

	len = 0;
	while (str[c] == ' ')
		c++;
	if (!ft_isdigit(str[c]))
	{
		if (str[c] == '-')
			exception(SIX);
		else
			exception(SEVEN);
	}
	while (ft_isdigit(str[c]))
	{
		len++;
		c++;
	}
	cub3D->screen->h = ft_parse_int(ft_substr(str, c - len, len));
	return (c);
}

int		ft_parse_screen_size(char *str, t_cub3D *cub3D)
{
	int c;
	int	count_values;
	int	len;

	c = 1;
	count_values = 0;
	len = 0;
	if (str[c] != ' ')
	{
		exception(FOUR);
	}
	if (cub3D->screen->h != -1 && cub3D->screen->w != -1)
	{
		exception(FIVE);
	} 
	c = ft_read_width(str, c, cub3D);
	c = ft_read_height(str, c, cub3D);
	return (0);
}