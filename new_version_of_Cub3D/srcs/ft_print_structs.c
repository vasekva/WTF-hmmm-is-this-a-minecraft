#include "cub3D.h"

/*
* Выводит содержимое структур в консоль
*/
void	ft_print_structs(t_cub3D *cub3D)
{
	printf("\n============================STRUCTURES===============================\n\n");
	printf("SCREEN: \n");
	printf("SCREEN W: %d\n", cub3D->screen->w);
	printf("SCREEN CENTER W: %d\n", cub3D->screen->center_w);
	printf("SCREEN H: %d\n", cub3D->screen->h);
	printf("SCREEN CENETR H: %d\n", cub3D->screen->center_h);

	printf("\n");

	printf("COLORS: \n");
	printf("FLOOR R: %d\n", cub3D->floor->r);
	printf("FLOOR G: %d\n", cub3D->floor->g);
	printf("FLOOR B: %d\n", cub3D->floor->b);
	printf("\n");
	printf("CEILING R: %d\n", cub3D->ceiling->r);
	printf("CEILING G: %d\n", cub3D->ceiling->g);
	printf("CEILING B: %d\n", cub3D->ceiling->b);

	printf("\n");

	printf(" Count of R: %d\n",  cub3D->parser->c_screen_size);
	printf(" Count of F: %d\n",  cub3D->parser->c_color_floor);
	printf(" Count of C: %d\n",  cub3D->parser->c_color_ceiling);
	printf(" Count of S: %d\n",  cub3D->parser->c_sprite);
	printf("Count of NO: %d\n", cub3D->parser->c_north);
	printf("Count of SO: %d\n", cub3D->parser->c_south);
	printf("Count of WE: %d\n", cub3D->parser->c_west);
	printf("Count of EA: %d\n", cub3D->parser->c_east);

	printf("\n");

	printf("NORTH:  %s\n", cub3D->map->north);

	printf("\n");

	printf("SOUTH:  %s\n", cub3D->map->south);

	printf("\n");

	printf("WEST:   %s\n", cub3D->map->west);

	printf("\n");

	printf("EAST:   %s\n", cub3D->map->east);

	printf("\n");

	printf("SPRITE: %s\n", cub3D->map->sprite);

	printf("\n");

	printf("COUNT_OF_VALUES: %d\n", cub3D->parser->count_of_recorded_values);

	printf("\n");

	printf("\n");
	printf("Count of lines in map: %d\n", cub3D->parser->count_of_map_lines);
	printf("    Max strlen in map: %d\n", cub3D->parser->max_strlen_of_map);
	printf("\n");

	printf("MAP: \n");
	for (int x = 0; x < cub3D->parser->count_of_map_lines; x++)
	{
		printf("%s\n", cub3D->array[x]);
	}
	printf("\n====================================================================\n");
}