#include "cub3d.h"

int 	is_map_symbol(char c)
{
	char	*symbols;
	int		i;

	i = 0;
	symbols = "012NSWE ";
	while (symbols[i])
	{
		if (symbols[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int 	is_map_line(t_cub3d *cub3d, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (is_map_symbol(line[i]))
			return (1);
		else
			exception(TWENTYTHREE);
		i++;
	}
	return (0);
}

static int	ft_add_mapsize(t_cub3d *cub3d, char *line, int i)
{
	char	c;
	int		size;
	int		has_empty_line;

	size = 0;
	has_empty_line = 0;
	c = line[0];
	if (cub3d->buff[i][0] == ' ')
	{
		if (is_map_line(cub3d, cub3d->buff[i]))
			size++;
		else
			has_empty_line = 1;
	}
	if (c == '1' || c == '2' || c == '0')
		size++;
	if (has_empty_line)
		return (-1);
	if (size)
		return (1);
	return (0);
}

static int 	ft_count_mapline(t_cub3d *cub3d, int size, int i, char c)
{
	int		has_map;
	int		has_empty_line;

	has_map = 0;
	has_empty_line = 0;
	while (cub3d->buff[i])
	{
		c = cub3d->buff[i][0];
		if (size != 0 && has_map == 0)
			has_map = 1;
		if (has_empty_line && has_map
			&& (c == '1' || c == '2'
				|| c == '0' || is_map_line(cub3d, cub3d->buff[i])))
			exception(TWENTYFOUR);
		if (ft_add_mapsize(cub3d, cub3d->buff[i], i) == -1)
			has_empty_line = 1;
		if (ft_add_mapsize(cub3d, cub3d->buff[i], i) == 1)
			size++;
		if (cub3d->buff[i][0] == '\0' && has_map)
			has_empty_line = 1;
		if (has_empty_line == 1)
			exception(THIRTYFIVE);
		i++;
	}
	return (size);
}

void	ft_init_map(t_cub3d *cub3d)
{
	int	i;

	cub3d->map_h = ft_count_mapline(cub3d, 0, 0, 0);
	if (cub3d->map_h < 3)
		exception(SEVEN);
	cub3d->map = malloc(sizeof(cub3d->map) * (cub3d->map_h + 1));
	if (!cub3d->map)
		exception(EIGHT);
	cub3d->map[cub3d->map_h] = NULL;
	ft_found_and_fill_map(cub3d);
	ft_check_map(cub3d);
}
