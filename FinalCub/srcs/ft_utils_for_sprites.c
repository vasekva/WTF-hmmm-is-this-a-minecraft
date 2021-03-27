#include "cub3d.h"

void	ft_count_sprites(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	cub3d->sprite.num_of_sprites = 0;
	while (x < cub3d->map_h)
	{
		y = 0;
		while (cub3d->map[x][y])
		{
			if (cub3d->map[x][y] == '2')
				cub3d->sprite.num_of_sprites++;
			y++;
		}
		x++;
	}
	cub3d->spr_crds = malloc(sizeof(*cub3d->spr_crds) * cub3d->sprite.num_of_sprites);
	cub3d->sprite.sprite_order = malloc(sizeof(int) * cub3d->sprite.num_of_sprites);
	cub3d->sprite.distance = malloc(sizeof(double) * cub3d->sprite.num_of_sprites);
}
