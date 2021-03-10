#include "cub3D.h"

int		ft_check_structs(t_cub3D *cub3D)
{
	if (cub3D->screen->h == -1 && cub3D->screen->w == -1)
		return (-1);
	if (cub3D->map->north == NULL || cub3D->map->south == NULL
		|| cub3D->map->west == NULL || cub3D->map->east == NULL
		|| cub3D->map->sprite == NULL)
		return (-1);
	if (cub3D->ceiling->r == -1 || cub3D->ceiling->g == -1 ||
		cub3D->ceiling->b == -1 || cub3D->floor->r == -1 ||
		cub3D->floor->g == -1 || cub3D->floor->b == -1)
		return (-1);
	return (0);
}

int		ft_parse_array(char *str, t_cub3D *cub3D)
{
	char	c;

	c = 0;
	if (ft_check_structs(cub3D) == -1)
	{
		printf("PARSE ERROR: The map must be in the end of file! Not all values have been init %s\n", str);
		exit (0);
	}
	if (str[0] != ' ' && str[0] != '1')
	{
		printf("PARSE ERROR: The map must start with symbol '1' or ' ' \n");
		exit (0);
	}
	if (str[ft_strlen(str) - 1] != '1')
	{
		printf("PARSE ERROR: The map must end with symbol '1' \n");
		exit (0);
	}
	while (str[c] == ' ')
		c++;
	while (str[c] != '\0')
	{
		if (str[c] == 'W' || str[c] == 'E'
			|| str[c] == 'S' || str[c] == 'N')
		{
			if (cub3D->array->count_player_point == 1)
			{
				printf("PARSE ERROR: The point of player have been already init! \n");
				exit (0);
			}
			cub3D->array->count_player_point++;
		}
		if (str[c] != '0' && str[c] != '1' && str[c] != '2' && str[c] != 'W'
			&& str[c] != 'E' && str[c] != 'S' && str[c] != 'N')
		{
			printf("PARSE ERROR: A forbidden symbol is used in the map! \n");
			exit (0);
		}
		c++;
	}
	cub3D->array->size++;
	return (0);
}