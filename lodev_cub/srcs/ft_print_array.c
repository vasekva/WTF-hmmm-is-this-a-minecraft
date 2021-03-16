#include "cub3D.h"

void	ft_print_array(t_cub3D *cub3d)
{
	int i;

	i = 0;
	while (cub3d->array->map_arr[i])
	{
		printf("%s\n", cub3d->array->map_arr[i]);
		i++;
	}
}