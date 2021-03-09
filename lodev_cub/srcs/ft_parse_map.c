#include "cub3D.h"

int		ft_check_structs(t_cub3D *cub3D)
{
	if (cub3D->screen->h == 0 && cub3D->screen->w == 0)
		return (-1);
	if (cub3D->map->north == NULL || cub3D->map->south == NULL
		|| cub3D->map->west == NULL || cub3D->map->east == NULL
		|| cub3D->map->sprite == NULL)
		return (-1);
	if (cub3D->ceiling == NULL || cub3D->floor == NULL)
		return (-1);
	return (0);	
}

int		ft_parse_map(char *str)
{
	char	c;

	c = 0;
	while (str[c])
	{
		if (str[0] < 49 || str[0] > 57)
		{
			printf("PARSE ERROR: unknown digit at the start of a line %s\n", str);
			exit (0);
		}
		if ((c == ft_strlen(str) - 1) && (str[c] < 49 || str[c] > 57))
		{
			printf("PARSE ERROR: unknown digit at the end of a line %s\n", str);
			exit (0);
		}
		if (str[c] != 'S' && str[c] != 'N' && str[c] != 'W' && str[c] != 'E'
			&& (str[c] < 48 || str[c] > 57))
		{
			printf("PARSE ERROR: unknown digit in line %s\n", str);
			exit (0);
		}
		c++;
	}
	return (0);
}