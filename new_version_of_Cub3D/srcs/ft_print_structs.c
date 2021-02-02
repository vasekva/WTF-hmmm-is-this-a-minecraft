#include "cub3D.h"

void	ft_print_structs(t_cub3D *cub3D)
{
	printf("\n============================STRUCTURE===============================\n");
	printf("SCREEN W: %d\n", cub3D->screen->w);
	printf("SCREEN H: %d\n", cub3D->screen->h);
	printf("\n");
	printf("FLOOR R: %d\n", cub3D->floor->r);
	printf("FLOOR G: %d\n", cub3D->floor->g);
	printf("FLOOR B: %d\n", cub3D->floor->b);

	printf("\n");

	printf("CEILING R: %d\n", cub3D->ceiling->r);
	printf("CEILING G: %d\n", cub3D->ceiling->g);
	printf("CEILING B: %d\n", cub3D->ceiling->b);

	printf("\n");

	printf("NORTH: %s\n", cub3D->map->north);

	printf("\n");

	printf("SOUTH: %s\n", cub3D->map->south);

	printf("\n");

	printf("WEST: %s\n", cub3D->map->west);

	printf("\n");

	printf("EAST: %s\n", cub3D->map->east);

	printf("\n");

	printf("SPRITE: %s\n", cub3D->map->sprite);

	printf("\n");

	printf("COUNT_OF_VALUES: %d\n", cub3D->count_of_recorded_values);
	printf("\n====================================================================\n");
}