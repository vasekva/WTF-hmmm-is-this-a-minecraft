#include "cub3d.h"

int	exit_prog(t_cub3d *cub)
{
	ft_free_all(cub);
	exit(1);
	return (0);
}
