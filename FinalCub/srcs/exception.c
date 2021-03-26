#include "cub3d.h"

void	exception(t_cub3d *cub3d, char *str)
{
	int	i;

	i = 0;
	write(1, "ERROR\n", 6);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit(0);
}
