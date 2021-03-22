#include "cub3d.h"

static int	check_size(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (cub3d->map_h < 3)
		return (-1);
	while (x < cub3d->map_h)
	{
		while (cub3d->map[x][y])
			y++;
		if (y < 3)
			return (-1);
		y = 0;
		x++;
	}
	return (1);
}

static int	check_edges(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (cub3d->map[0][y] && cub3d->map[cub3d->map_h - 1][y])
	{
		if (cub3d->map[0][y] != '1' || cub3d->map[cub3d->map_h - 1][y] != '1')
			return (-1);
		y++;
	}
	while (x < cub3d->map_h)
	{
		if (cub3d->map[x][0] != '1'
			|| cub3d->map[x][ft_strlen(cub3d->map[x]) - 1] != '1')
			return (-1);
		x++;
	}
	return (1);
}

static int	check_inside(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < cub3d->map_h)
	{
		while (cub3d->map[x][y])
		{
			if (cub3d->map[x][y] != '0' && cub3d->map[x][y] != '1'
				&& cub3d->map[x][y] != '2' && cub3d->map[x][y] != 'N'
				&& cub3d->map[x][y] != 'S' && cub3d->map[x][y] != 'E'
				&& cub3d->map[x][y] != 'W')
				return (-1);
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}

static int	check_position(t_cub3d *cub)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (x < cub->map_h)
	{
		while (cub->map[x][y])
		{
			if (cub->map[x][y] == 'N' || cub->map[x][y] == 'S'
				|| cub->map[x][y] == 'E' || cub->map[x][y] == 'W')
				count++;
			y++;
		}
		y = 0;
		x++;
	}
	if (count != 1)
		return (-1);
	return (1);
}

void	ft_check_map(t_cub3d *cub3d)
{
	if (check_size(cub3d) != 1)
		exception(SEVEN);
	if (check_edges(cub3d) != 1)
		exception(NINE);
	if (check_inside(cub3d) != 1)
		exception(TEN);
	if (check_position(cub3d) != 1)
		exception(ELEVEN);
}
