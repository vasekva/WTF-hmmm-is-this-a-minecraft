#include "cub3d.h"

static void 	ft_malloc_sprites(t_cub3d *cub3d)
{
	cub3d->spr_crds
		= malloc(sizeof(*cub3d->spr_crds) * cub3d->sprite.num_of_sprites);
	if (!cub3d->spr_crds)
		exception(SIXTEEN);
	cub3d->sprite.sprite_order
		= malloc(sizeof(int) * cub3d->sprite.num_of_sprites);
	if (!cub3d->sprite.sprite_order)
		exception(SEVENTEEN);
	cub3d->sprite.distance
		= malloc(sizeof(double) * cub3d->sprite.num_of_sprites);
	if (!cub3d->sprite.distance)
		exception(EIGHTEEN);
}

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
	ft_malloc_sprites(cub3d);
}
