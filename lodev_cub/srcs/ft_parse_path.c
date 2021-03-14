#include "cub3D.h"

static void ft_print_error(char *str)
{
	int i;

	i = 0;
	write(1, "Parameter '", 11);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "' has already been specified!\n\n", 31);
	exit(0);
}

static int ft_check_struct(char *str, t_cub3D *cub3D)
{
	if (str[0] == 'S' && str[1] != 'O')
	{
		if (cub3D->map->sprite != NULL)
			ft_print_error("S");
	}
	if (str[0] == 'S' && str[1] == 'O')
	{
		if (cub3D->map->south != NULL)
			ft_print_error("SO");		
	}
	if (str[0] == 'N' && str[1] == 'O')
	{
		if (cub3D->map->north != NULL)
			ft_print_error("NO");
	}
	if (str[0] == 'W' && str[1] == 'E')
	{
		if (cub3D->map->west != NULL)
			ft_print_error("WE");
	}
	if (str[0] == 'E' && str[1] == 'A')
	{
		if (cub3D->map->east != NULL)
			ft_print_error("EA");		
	}
	return (1);
}

static int ft_read_path(char *str, int start, int len, t_cub3D *cub3D)
{
	if (str[0] == 'S' && str[1] != 'O')
	{
		ft_check_struct(str, cub3D);
		cub3D->map->sprite = ft_substr(str, start, len);
	}
	if (str[0] == 'S' && str[1] == 'O')
	{
		ft_check_struct(str, cub3D);	
		cub3D->map->south = ft_substr(str, start, len);
	}
	if (str[0] == 'N' && str[1] == 'O')
	{
		ft_check_struct(str, cub3D);
		cub3D->map->north = ft_substr(str, start, len);	
	}
	if (str[0] == 'W' && str[1] == 'E')
	{
		ft_check_struct(str, cub3D);
		cub3D->map->west = ft_substr(str, start, len);	
	}
	if (str[0] == 'E' && str[1] == 'A')
	{
		ft_check_struct(str, cub3D);	
		cub3D->map->east = ft_substr(str, start, len);	
	}
	return (0);
}

int			ft_parse_path(char *str, t_cub3D *cub3D)
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
		exception(FOUR);
	}
	while (str[i] == ' ')
		i++;
	len = ft_strlen(&str[i]);
	if (len == 0)
	{
		exception(EIGHT);
	}
	else
	{
		ft_read_path(str, i, len, cub3D);
	}
	return (0);
}
