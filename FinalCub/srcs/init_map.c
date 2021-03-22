#include "cub3d.h"

int	count_lines(t_cub3d *cub3d)
{
	int		count;
	int		nb;
	int		i;

	nb = 0;
	count = 0;
	i = 0;
	while (cub3d->buf.buffer[i])
	{
		nb++;
		i++;
	}
	i = 0;
	while (cub3d->buf.buffer[i] && cub3d->buf.buffer[i][0] != '1')
		i++;
	if (i < nb)
	{
		while (cub3d->buf.buffer[i] && cub3d->buf.buffer[i][0])
		{
			count++;
			i++;
		}
	}
	return (count);
}

void	create_map(t_cub3d *cub3d)
{
	int	x;
	int	i;

	cub3d->map_h = count_lines(cub3d);
	if (cub3d->map_h < 3)
		exception(SEVEN);
	cub3d->map = malloc(sizeof(cub3d->map) * cub3d->map_h);
	if (!cub3d->map)
		exception(EIGHT);
	i = 0;
	while (cub3d->buf.buffer && cub3d->buf.buffer[i][0] != '1')
		i++;
	x = 0;
	while (x < cub3d->map_h)
		cub3d->map[x++] = ft_strdup(cub3d->buf.buffer[i++]);
}

void	rm_elem(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ' ')
	{
		while (str[i])
		{
			str[i] = str[i + 1];
			i++;
		}
	}
}

void	adjust_map(t_cub3d *cub)
{
	int	x;
	int	y;
	int	len;

	x = 0;
	y = 0;
	cub->map_w = 0;
	while (x < cub->map_h)
	{
		while (cub->map[x][y] == ' ')
			cub->map[x][y++] = '1';
		while (cub->map[x][y])
		{
			rm_elem(&cub->map[x][y]);
			y++;
		}
		len = ft_strlen(cub->map[x]);
		if (len > cub->map_w)
			cub->map_w = len;
		y = 0;
		x++;
	}
}

void	complete_map(t_cub3d *cub3d)
{
	int		x;
	int		y;
	char	*endline;

	x = 0;
	while (x < cub3d->map_h)
	{
		y = 0;
		endline = ft_calloc(sizeof(char), \
				(cub3d->map_w - ft_strlen(cub3d->map[x]) + 1));
		ft_memset(endline, '1', cub3d->map_w - ft_strlen(cub3d->map[x]));
		cub3d->map[x] = ft_strjoin(cub3d->map[x], endline, 2);
		while (cub3d->map[x][y])
			y++;
		while (y < cub3d->map_w)
		{
			cub3d->map[x][y] = '1';
			y++;
		}
		x++;
	}
}

void	init_map(t_cub3d *cub3d)
{
	create_map(cub3d);
	adjust_map(cub3d);
	complete_map(cub3d);
	ft_check_map(cub3d);
}
