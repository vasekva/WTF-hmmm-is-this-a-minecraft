#include "cub3d.h"

static int	is_param(char c)
{
	char	*params;
	int		i;

	i = 0;
	params = "RSNEWCF 1";
	while (params[i])
	{
		if (c == params[i])
			return (1);
		i++;
	}
	return (0);
}

static void	ft_check_params02(t_cub3d *cub3d, int i)
{
	if (cub3d->buff[i][0] == 'W'
		&& cub3d->buff[i][1] != 'E')
		exception(THIRTYTHREE);
	if (cub3d->buff[i][0] == 'S'
		&& (cub3d->buff[i][1] != ' '
			&& cub3d->buff[i][1] != 'O'))
		exception(THIRTYTHREE);
	if (cub3d->buff[i][0] == 'W'
		&& cub3d->buff[i][1] != 'E')
		exception(THIRTYTHREE);
	if (cub3d->buff[i][0] == 'N'
		&& cub3d->buff[i][1] != 'O')
		exception(THIRTYTHREE);
	if (cub3d->buff[i][0] == 'E'
		&& cub3d->buff[i][1] != 'A')
		exception(THIRTYTHREE);
}

void	ft_check_params01(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->buff[i])
	{
		if (is_param(cub3d->buff[i][0]))
		{
			if (cub3d->buff[i][0] == 'R'
				&& cub3d->buff[i][1] != ' ')
				exception(THIRTYTHREE);
			if (cub3d->buff[i][0] == 'C'
				&& cub3d->buff[i][1] != ' ')
				exception(THIRTYTHREE);
			if (cub3d->buff[i][0] == 'F'
				&& cub3d->buff[i][1] != ' ')
				exception(THIRTYTHREE);
			ft_check_params02(cub3d, i);
		}
		else
			if (cub3d->buff[i][0] != '\0')
				exception(THIRTYTHREE);
		i++;
	}
}
