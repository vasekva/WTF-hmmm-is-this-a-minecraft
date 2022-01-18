#include "cub3d.h"

void	display_error(t_cub3d *cub, char *err_message)
{
	ft_putstr_fd("ERROR\n", 1);
	ft_putstr_fd(err_message, 1);
	exit_prog(cub);
}
