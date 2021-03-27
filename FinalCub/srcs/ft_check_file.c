#include "cub3d.h"

static int	ft_has_no_param(char **str, char first, char second)
{
	int	i;

	i = 0;
	while (str[i] && (str[i][1] != second || str[i][0] != first))
		i++;
	if (!str[i])
		return (-1);
	return (1);
}

static int	check_double_elem(char **str, char first, char second)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i][1] == second && str[i][0] == first)
			count++;
		i++;
	}
	if (count > 1)
		return (-1);
	return (1);
}

static void	ft_check_amount_param(t_cub3d *cub3d)
{
	if (ft_has_no_param(cub3d->buff, 'R', ' ') != 1
		|| ft_has_no_param(cub3d->buff, 'F', ' ') != 1
		|| ft_has_no_param(cub3d->buff, 'C', ' ') != 1
		|| ft_has_no_param(cub3d->buff, 'S', ' ') != 1
		|| ft_has_no_param(cub3d->buff, 'S', 'O') != 1
		|| ft_has_no_param(cub3d->buff, 'N', 'O') != 1
		|| ft_has_no_param(cub3d->buff, 'E', 'A') != 1
		|| ft_has_no_param(cub3d->buff, 'W', 'E') != 1)
		exception(cub3d, THREE);
	if (check_double_elem(cub3d->buff, 'R', ' ') != 1
		|| check_double_elem(cub3d->buff, 'F', ' ') != 1
		|| check_double_elem(cub3d->buff, 'C', ' ') != 1
		|| check_double_elem(cub3d->buff, 'S', ' ') != 1
		|| check_double_elem(cub3d->buff, 'S', 'O') != 1
		|| check_double_elem(cub3d->buff, 'N', 'O') != 1
		|| check_double_elem(cub3d->buff, 'E', 'A') != 1
		|| check_double_elem(cub3d->buff, 'W', 'E') != 1)
		exception(cub3d, FOUR);
}

static void	ft_check_pos_of_map(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->buff[i] && cub3d->buff[i][0] != '1')
		i++;
	while (cub3d->buff[i])
	{
		if (cub3d->buff[i][0] == 'R' || cub3d->buff[i][0] == 'S'
			|| cub3d->buff[i][0] == 'N' || cub3d->buff[i][0] == 'E'
			|| cub3d->buff[i][0] == 'W' || cub3d->buff[i][0] == 'F'
			|| cub3d->buff[i][0] == 'C' || cub3d->buff[i][0] == 'S')
			exception(cub3d, FIVE);
		i++;
	}
}

void	ft_check_file(t_cub3d *cub3d)
{
	ft_check_amount_param(cub3d);
	ft_check_pos_of_map(cub3d);
}
