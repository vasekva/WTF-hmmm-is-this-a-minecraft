#include "cub3d.h"

int	is_param(char c)
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

void 	ft_check_params02(t_cub3d *cub3d, int i)
{
	if (cub3d->buf.buffer[i][0] == 'W'
		&& cub3d->buf.buffer[i][1] != 'E')
		exception(cub3d, THIRTYTHREE);
	if (cub3d->buf.buffer[i][0] == 'S'
		&& (cub3d->buf.buffer[i][1] != ' '
			&& cub3d->buf.buffer[i][1] != 'O'))
		exception(cub3d, THIRTYTHREE);
	if (cub3d->buf.buffer[i][0] == 'W'
		&& cub3d->buf.buffer[i][1] != 'E')
		exception(cub3d, THIRTYTHREE);
	if (cub3d->buf.buffer[i][0] == 'N'
		&& cub3d->buf.buffer[i][1] != 'O')
		exception(cub3d, THIRTYTHREE);
	if (cub3d->buf.buffer[i][0] == 'E'
		&& cub3d->buf.buffer[i][1] != 'A')
		exception(cub3d, THIRTYTHREE);
}

void	ft_check_params01(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->buf.buffer[i])
	{
		if (is_param(cub3d->buf.buffer[i][0]))
		{
			if (cub3d->buf.buffer[i][0] == 'R'
				&& cub3d->buf.buffer[i][1] != ' ')
				exception(cub3d, THIRTYTHREE);
			if (cub3d->buf.buffer[i][0] == 'C'
				&& cub3d->buf.buffer[i][1] != ' ')
				exception(cub3d, THIRTYTHREE);
			if (cub3d->buf.buffer[i][0] == 'F'
				&& cub3d->buf.buffer[i][1] != ' ')
				exception(cub3d, THIRTYTHREE);
			ft_check_params02(cub3d, i);
		}
		else
			if (cub3d->buf.buffer[i][0] != '\0')
				exception(cub3d, THIRTYTHREE);
		i++;
	}
}
