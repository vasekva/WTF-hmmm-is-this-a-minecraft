#include "cub3d.h"

void		count_sprites(t_cub3d *cub)
{
	int x;
	int y;

	x = 0;
	cub->spr.nb_sprite = 0;
	while (x < cub->map_h)
	{
		y = 0;
		while (cub->map[x][y])
		{
			if (cub->map[x][y] == '2')
				cub->spr.nb_sprite++;
			y++;
		}
		x++;
	}
	cub->c_spr = malloc(sizeof(*cub->c_spr) * cub->spr.nb_sprite);
	cub->spr.sp_order = malloc(sizeof(int) * cub->spr.nb_sprite);
	cub->spr.sp_dist = malloc(sizeof(double) * cub->spr.nb_sprite);
}
