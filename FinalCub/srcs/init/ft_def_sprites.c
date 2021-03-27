#include "cub3d.h"

static	void	ft_swap_int(int *first, int *second)
{
	int	number;

	number = *first;
	*first = *second;
	*second = number;
}

static	void	ft_swap_double(double *first, double *second)
{
	double	number;

	number = *first;
	*first = *second;
	*second = number;
}

static	void 	ft_count_amt(int *amount)
{
	*amount = *amount * 10 / 13;
	if (*amount < 1)
		*amount = 1;
	if (*amount == 9 || *amount == 10)
		*amount = 11;
}

void 	ft_spr_sort(int *order, double *dist, int number)
{
	int	amt;
	int	flag;
	int	i;
	int	j;

	flag = 0;
	amt = number;
	while (amt > 1 || flag == 1)
	{
		ft_count_amt(&amt);
		flag = 0;
		i = 0;
		while (i < number - amt)
		{
			j = i + amt;
			if (dist[i] < dist[j])
			{
				ft_swap_double(&dist[i], &dist[j]);
				ft_swap_int(&order[i], &order[j]);
				flag = 1;
			}
			i++;
		}
	}
}

void 	ft_def_spr_dist(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < cub3d->sprite.num_of_sprites)
	{
		cub3d->sprite.sprite_order[i] = i;
		cub3d->sprite.distance[i]
			= ft_power(cub3d->player.pos_x - cub3d->spr_crds[i].x, 2)
			+ ft_power(cub3d->player.pos_y - cub3d->spr_crds[i].y, 2);
		i++;
	}
}
