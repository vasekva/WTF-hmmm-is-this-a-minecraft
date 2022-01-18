#include "cub3d.h"

static int	count_x(t_cub3d *cub)
{
	int		count;
	int		nb;
	int		i;

	nb = 0;
	count = 0;
	i = 0;
	while (cub->buf.buffer[i])
	{
		nb++;
		i++;
	}
	printf("COUNTDD: %d\n", nb);
	i = 0;
	while (cub->buf.buffer[i] && cub->buf.buffer[i][0] != '1')
		i++;
	if (i < nb)
	{
		while (cub->buf.buffer[i] && cub->buf.buffer[i][0])
		{
			count++;
			i++;
		}
	}
	printf("COUNT: %d\n", count);
	return (count);
}

void		create_map(t_cub3d *cub)
{
	int		x;
	int		i;

	cub->map_h = count_x(cub);
	if (cub->map_h < 3 || !(cub->map = malloc(sizeof(cub->map) * cub->map_h)))
		exception(EIGHT);
//		display_error(cub, "Map error.\n");
	i = 0;
	while (cub->buf.buffer && cub->buf.buffer[i][0] != '1')
		i++;
	x = 0;
	while (x < cub->map_h)
		cub->map[x++] = ft_strdup(cub->buf.buffer[i++]);
}
