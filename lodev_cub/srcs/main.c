/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:29:55 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/15 14:30:00 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_cub3d(t_cub3D *cub3d, char *path)
{
	cub3d->file_path = path;
	cub3d->identifier = 0;
	cub3d->screen = init_screen(NULL);
	cub3d->floor = init_floor(NULL);
	cub3d->ceiling = init_ceiling(NULL);
	cub3d->map = init_map(NULL);
	cub3d->array = init_array(NULL);
	ft_parse(cub3d);
	cub3d->env = init_env(NULL, cub3d);
	cub3d->mlx_img = init_mlx_img(NULL);
	cub3d->keys = init_keys(NULL);
	cub3d->player = init_player(NULL);
	cub3d->walls = init_walls(NULL);
}

static int	loop_hook(void *param)
{
	t_cub3D	*cub3d;

	if (param)
	{
		cub3d = (t_cub3D *)param;
		ft_start_game(cub3d, 0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub3D	cub3d;

	if (argc == 2)
	{
		init_cub3d(&cub3d, argv[1]);
		mlx_hook(cub3d.env->win, 2, 1L << 0, keypress_hook, &cub3d);
		mlx_hook(cub3d.env->win, 3, 1L << 0, keyrelease_hook, &cub3d);
		mlx_loop_hook(cub3d.env->mlx, loop_hook, &cub3d);
		mlx_loop(cub3d.env->mlx);
	}
}
