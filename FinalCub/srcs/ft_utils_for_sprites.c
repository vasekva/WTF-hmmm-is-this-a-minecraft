#include "cub3d.h"

void	ft_count_sprites(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	cub3d->sprite.nb_sprite = 0;
	while (x < cub3d->map_h)
	{
		y = 0;
		while (cub3d->map[x][y])
		{
			if (cub3d->map[x][y] == '2')
				cub3d->sprite.nb_sprite++;
			y++;
		}
		x++;
	}
	cub3d->c_spr = malloc(sizeof(*cub3d->c_spr) * cub3d->sprite.nb_sprite);
	cub3d->sprite.sp_order = malloc(sizeof(int) * cub3d->sprite.nb_sprite);
	cub3d->sprite.sp_dist = malloc(sizeof(double) * cub3d->sprite.nb_sprite);
}
