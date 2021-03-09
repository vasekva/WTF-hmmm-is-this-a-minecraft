#include "cub3D.h"

static void ft_print_error(char *str)
{
	printf("Parameter %s has already been specified!\n", str);
	exit(0);
}

static int ft_read_path(char *str, int start, int len, t_cub3D *cub3D)
{
	if (str[0] == 'S' && str[1] != 'O')
	{
		if (cub3D->map->sprite != NULL)
			ft_print_error("S");
		cub3D->map->sprite = ft_substr(str, start, len);
	}
	if (str[0] == 'S' && str[1] == 'O')
	{
		if (cub3D->map->south != NULL)
			ft_print_error("SO");		
		cub3D->map->south = ft_substr(str, start, len);
	}
	if (str[0] == 'N' && str[1] == 'O')
	{
		if (cub3D->map->north != NULL)
			ft_print_error("NO");
		cub3D->map->north = ft_substr(str, start, len);	
	}
	if (str[0] == 'W' && str[1] == 'E')
	{
		if (cub3D->map->west != NULL)
			ft_print_error("WE");
		cub3D->map->west = ft_substr(str, start, len);	
	}
	if (str[0] == 'E' && str[1] == 'A')
	{
		if (cub3D->map->east != NULL)
			ft_print_error("EA");		
		cub3D->map->east = ft_substr(str, start, len);	
	}
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