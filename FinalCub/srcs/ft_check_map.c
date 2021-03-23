#include "cub3d.h"

int	ft_check_firstspaces(t_cub3d *cub3d, int ind)
{
	int	i;

	i = 0;
	while (cub3d->map[ind][i] == ' ')
	{
		if (cub3d->map[ind][i + 1] == '0' || cub3d->map[ind][i + 1] == '2')
		{
			printf("%s %d\n", cub3d->map[ind], ind);
			exception(NINE);
		}
		if (ind != 0
			&& (cub3d->map[ind - 1][i] == '0' || cub3d->map[ind - 1][i] == '2'))
		{
			printf("%s %d\n", cub3d->map[ind], ind);
			exception(NINE);
		}
		if ((ind != cub3d->map_h - 1)
			&& (cub3d->map[ind + 1][i] == '0' || cub3d->map[ind + 1][i] == '2'))
		{
			printf("%s %d\n", cub3d->map[ind], ind);
			exception(NINE);
		}
		i++;
	}
	return (i);
}

void	ft_check_top_bot_line(t_cub3d *cub3d)
{
	int	i;
	int	ind;

	ind = 0;
	i = ft_check_firstspaces(cub3d, ind);
	while (cub3d->map[ind][i])
	{
		if (cub3d->map[ind][i] != '1' && cub3d->map[ind][i] != ' ')
		{
			printf("%s %d\n", cub3d->map[ind], ind);
			exception(NINE);
		}
		i++;
	}
	ind = cub3d->map_h - 1;
	i = ft_check_firstspaces(cub3d, ind);
	while (cub3d->map[ind][i])
	{
		if (cub3d->map[ind][i] != '1' && cub3d->map[ind][i] != ' ')
		{
			printf("%s %d\n", cub3d->map[ind], ind);
			exception(NINE);
		}
		i++;
	}	
}

void	ft_check_middle_lines(t_cub3d *cub3d)
{
	int	i;
	int	ind;

	ind = 1;
	while (ind != cub3d->map_h - 1)
	{
		i = ft_check_firstspaces(cub3d, ind);
		if (cub3d->map[ind][i] != '1')
		{
			printf("%s %d\n", cub3d->map[ind], ind);
			exception(NINE);
		}
		while (cub3d->map[ind][i])
		{
			if (cub3d->map[ind][i] != '1')
				if (cub3d->map[ind][i] != ' ')
					if (cub3d->map[ind - 1][i] == ' '
						|| cub3d->map[ind + 1][i] == ' '
						|| cub3d->map[ind][i - 1] == ' '
						|| cub3d->map[ind][i + 1] == ' ')
						exception(TWENTYFIVE);
			i++;
		}
		ind++;
	}
}

void	ft_check_symbols_inside(t_cub3d *cub3d, int i, int ind)
{
	int		has_player;
	char	c;

	has_player = 0;
	while (ind != cub3d->map_h - 1)
	{
		while (cub3d->map[ind][i])
		{
			c = cub3d->map[ind][i];
			if (!is_map_symbol(c))
			{
				printf("%s %d\n", cub3d->map[ind], ind);
				exception(TEN);
			}
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				if (has_player == 1)
					exception(ELEVEN);
				has_player = 1;
			}
			i++;
		}
		i = 0;
		ind++;
	}
}

void	ft_check_map(t_cub3d *cub3d)
{
	ft_check_top_bot_line(cub3d);
	ft_check_middle_lines(cub3d);
	ft_check_symbols_inside(cub3d, 0, 1);
}
