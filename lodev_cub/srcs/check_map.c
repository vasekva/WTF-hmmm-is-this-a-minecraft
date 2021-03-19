#include "cub3d.h"

static int	check_size(t_cub3d *cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (cub->map_h < 3)
		return (0);
	while (x < cub->map_h)
	{
		while (cub->map[x][y])
			y++;
		if (y < 3)
			return (0);
		y = 0;
		x++;
	}
	return (1);
}

static int	check_edges(t_cub3d *cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (cub->map[0][y] && cub->map[cub->map_h - 1][y])
	{
		if (cub->map[0][y] != '1' || cub->map[cub->map_h - 1][y] != '1')
			return (0);
		y++;
	}
	while (x < cub->map_h)
	{
		if (cub->map[x][0] != '1' \
			|| cub->map[x][ft_strlen(cub->map[x]) - 1] != '1')
			return (0);
		x++;
	}
	return (1);
}

static int	check_inside(t_cub3d *cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < cub->map_h)
	{
		while (cub->map[x][y])
		{
			if (cub->map[x][y] != '0' && cub->map[x][y] != '1' \
				&& cub->map[x][y] != '2' && cub->map[x][y] != 'N' \
				&& cub->map[x][y] != 'S' && cub->map[x][y] != 'E' \
				&& cub->map[x][y] != 'W')
				return (0);
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}

static int	check_position(t_cub3d *cub)
{
	int x;
	int y;
	int count;

	x = 0;
	y = 0;
	count = 0;
	while (x < cub->map_h)
	{
		while (cub->map[x][y])
		{
			if (cub->map[x][y] == 'N' || cub->map[x][y] == 'S' \
				|| cub->map[x][y] == 'E' || cub->map[x][y] == 'W')
				count++;
			y++;
		}
		y = 0;
		x++;
	}
	if (count != 1)
		return (0);
	return (1);
}

void		check_map(t_cub3d *cub)
{
	if (!(check_size(cub)))
		display_error(cub, "Map too small.\n");
	if (!(check_edges(cub)))
		display_error(cub, "Map must be surrounded by 1.\n");
	if (!(check_inside(cub)))
		display_error(cub, "Invalid value.\n");
	if (!(check_position(cub)))
		display_error(cub, "Must have 1 position identifier.\n");
}
