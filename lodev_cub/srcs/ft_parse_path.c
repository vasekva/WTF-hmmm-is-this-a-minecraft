#include "cub3D.h"

static int ft_read_path(char *str, int start, int len, t_cub3D *cub3D)
{
	if (str[0] == 'S' && str[1] != 'O')
		cub3D->map->sprite = ft_substr(str, start, len);
	if (str[0] == 'S' && str[1] == 'O')
		cub3D->map->south = ft_substr(str, start, len);
	if (str[0] == 'N' && str[1] == 'O')
		cub3D->map->north = ft_substr(str, start, len);	
	if (str[0] == 'W' && str[1] == 'E')
		cub3D->map->west = ft_substr(str, start, len);	
	if (str[0] == 'E' && str[1] == 'A')
		cub3D->map->east = ft_substr(str, start, len);	
	return (0);
}

int		ft_parse_path(char *str, t_cub3D *cub3D)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (str[0] == 'S' && str[1] != 'O')
		i++;
	else
		i += 2;
	if (str[i] != ' ')
	{
		printf("PARSE ERROR: string can't be without a space after identifier %s\n", str);
		exit (0);
	}
	while (str[i] == ' ')
		i++;
	len = ft_strlen(&str[i]);
	if (len == 0)
	{
		printf("PARSE ERROR: file path can't be empty %s\n", str);
		exit (0);
	}
	else
	{
		ft_read_path(str, i, len, cub3D);
	}
	return (0);
}